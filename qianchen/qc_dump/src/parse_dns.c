#include "includes.h"

#define MAX_IP_STRING_SIZE	32

/* Formats a 32-bit IP address into a dotted quad string and
   copies it into the given buffer. */
static void _format_ip_address(uint32_t ip_address, char *buffer)
{
	uint8_t *segments = (uint8_t *)&ip_address;

	sprintf(buffer, "%d.%d.%d.%d", segments[3], segments[2],
		  segments[1], segments[0]);
}

/*
static char *_get_authority_string(int is_authoritative)
{
	return is_authoritative ? "auth" : "nonauth";
}*/

/* Increments the buffer pointer by a number of bytes and checks that it is still
   below the max index value. Returns 0 if the new address is invalid, 1 otherwise. */
static int _increment_buffer_index(char **buffer_pointer, char *max_index, int bytes)
{
	*buffer_pointer += bytes;
	return *buffer_pointer >= max_index ? 0 : 1;
}

/* Reads the next domain name from a NAME, QNAME, or RDATA field in a DNS 
   packet and copies it into the destination buffer. It returns the number
   of bytes read after the packet index. Returns -1 on an error. */
static int _read_domain_name(char *packet_index, char *packet_start, 
			    int packet_size, char *dest_buffer)
{
	int bytes_read = 0;
	uint8_t label_length = 0;
	uint16_t offset = 0;
	char *max_index = NULL;

	bytes_read = 0;
	max_index = packet_start + packet_size;

	/* The domain name is stored as a series of sub-domains or pointers to
	 sub-domains. Each sub-domain contains the length as the first byte, 
	 followed by LENGTH number of bytes (no null-terminator). If it's a pointer,
	 the first two bits of the length byte will be set, and then the rest of
	 the bits contain an offset from the start of the packet to another
	 sub-domain (or set of sub-domains). 

	 We first get the length of the sub-domain (or label), check if it's a
	 pointer, and if not, read the that number of bytes into a buffer. Each
	 sub-domain is separated by a period character. If a pointer is found,
	 we can call this function recursively. 

	 The end of the domain name is found when we read a label length of 
	 0 bytes. */

	if (packet_index >= max_index)
	{
		return -1;
	}
	label_length = (uint8_t)*packet_index;

	while (label_length > 0)
	{
		/* If this isn't the first label, add a period in between the labels. */
		if (bytes_read > 0)
		{
			*dest_buffer = '.';
			dest_buffer ++;
		}

		/* Check to see if this label is a pointer. */
		if ((label_length & DNS_POINTER_FLAG) == DNS_POINTER_FLAG)
		{
			char *new_packet_index;

			offset = ntohs(*(uint16_t *)packet_index) & DNS_POINTER_OFFSET_MASK;
			new_packet_index = packet_start + offset;
			if (new_packet_index >= max_index)
			{
				return -1;
			}

			/* Recursively call this function with the packet index set to
			the offset value and the current location of the destination
			buffer. Since we're using an offset and reading from some
			other part of memory, we only need to increment the number
			of bytes read by 2 (for the pointer value). */
			_read_domain_name(new_packet_index, packet_start, packet_size, dest_buffer);
			return bytes_read + 2;
		}

		++ packet_index;
		label_length &= DNS_LABEL_LENGTH_MASK;

		if (packet_index + label_length >= max_index)
		{
			return -1;
		}

		memcpy(dest_buffer, packet_index, label_length);
		dest_buffer += label_length;
		*dest_buffer = 0;

		packet_index += label_length;
		bytes_read += label_length + 1;

		label_length = (uint8_t)*packet_index;
	}

	++ bytes_read; /* For the null root. */

	return bytes_read;
}

static struct dns_response *_parse_dns_response(void *packet_buffer, int packet_length, int *answer_count)
{
	int i = 0, bytes_read = 0, authoritative = 0;
	char buffer[MAX_DOMAIN_LENGTH + 1] = {0};
	char *buffer_index = NULL, *max_index = NULL;
	uint8_t error_code = 0;
	uint16_t rdata_length = 0;
	size_t header_size = 0;
	struct dns_header header;
	struct dns_response *responses = NULL;

	authoritative = 0;
	*answer_count = 0;

	header_size = sizeof(struct dns_header);

	/* Verify that the packet is large enough to contain the DNS header, and
	 then copy it into a dns_header struct. */
	if (packet_length < header_size)
	{
		LOG_NORMAL_INFO("response has invalid format!\n");
		return NULL;
	}

	/* Use the buffer index to step through the packet, checking that it 
	 doesn't extend past the max_index value. */
	buffer_index = (char *)packet_buffer;
	max_index = buffer_index + packet_length;

	/* When copying the header back, convert the values from network byte
	 order to the host byte order. */
	memcpy(&header, buffer_index, header_size);
	buffer_index += header_size;

	header.id	  	= ntohs(header.id);
	header.flags	= ntohs(header.flags);
	header.qd_count = ntohs(header.qd_count);
	header.an_count = ntohs(header.an_count);
	header.ns_count = ntohs(header.ns_count);
	header.ar_count = ntohs(header.ar_count);

	/* Check the flags to verify that this is a valid response. */
	if (! (header.flags & DNS_QR_RESPONSE))
	{
		LOG_NORMAL_INFO("header does not contain response flag!\n");
		return NULL;
	}

	/* If the message was truncated, return an error. */
	if (header.flags & DNS_TRUNCATED)
	{
		LOG_NORMAL_INFO("response was truncated!\n");
		return NULL;
	}

	/* If no recursion is available, return an error. */
	if (! (header.flags & DNS_RECURSION_AVAIL))
	{
		LOG_NORMAL_INFO("no recursion available!\n");
		return NULL;
	}

	/* Check for error conditions. */
	error_code = header.flags & DNS_ERROR_MASK;

	switch (error_code)
	{
		case DNS_FORMAT_ERROR:
		{
			LOG_NORMAL_INFO("server unable to interpret query!\n");
			return NULL;
		}

		case DNS_SERVER_FAILURE:
		{
			LOG_NORMAL_INFO("unable to process due to server error!\n");
			return NULL;
		}
		
		case DNS_NOT_IMPLEMENTED:
		{
			LOG_NORMAL_INFO("server does not support requested query type!\n");
			return NULL;
		}
		
		case DNS_REFUSED:
		{
			LOG_NORMAL_INFO("server refused query!\n");
			return NULL;
		}

		case DNS_NAME_ERROR:
		{
			/* A name error indicates that the name was not found. This isn't due to
			   an error, so we just indicate that the number of answers is 0 and return
			   a null value. */
			*answer_count = 0;
			return NULL;
		}
		
		default:
		{
			break;
		}
	}

	/* Verify that there is at least one answer. We also put a limit on the number
	 of answers allowed. This is to prevent a bogus response containing a very
	 high answer count from allocating too much memory by setting an upper
	 bound. */
	if (header.an_count < 1)
	{ 
		*answer_count = 0;
		return NULL;
	}

	if (header.an_count > MAX_AN_COUNT)
	{
		header.an_count = MAX_AN_COUNT;
	}

	/* Is this response authoritative? */
	if (header.flags & DNS_AUTH_ANS)
	{
		authoritative = 1;
	}

	/* Verify that the question section contains the domain name we requested. */
	bytes_read = _read_domain_name(buffer_index, packet_buffer, 
				packet_length, buffer);
	if (bytes_read == -1)
	{
		LOG_NORMAL_INFO("response has invalid format!\n");
		return NULL;
	}

	if (! _increment_buffer_index(&buffer_index, max_index, bytes_read))
	{
		LOG_NORMAL_INFO("response has invalid format!\n");
		return NULL;
	}

	/* After the null root character, skip over the QTYPE and QCLASS sections which
	 should put the buffer index at the start of the answer section. */
	if (! _increment_buffer_index(&buffer_index, max_index, 2 * sizeof(uint16_t)))
	{
		LOG_NORMAL_INFO("response has invalid format!\n");
		return NULL;
	}

	/* Answer section. There may be multiple answer sections which we can determine from
	 the packet header. Allocate enough space for all of the buffers. 

	 The first part of each answer section is similar to the question section, containing
	 the name  that we queried for. Ignore this for now, maybe verify that it is the
	 same name later. */
	*answer_count = header.an_count;
	responses = malloc(sizeof(struct dns_response) * header.an_count);
	if (responses == NULL)
	{
		LOG_NORMAL_INFO("unable to allocate memory for response!\n");
		return NULL;
	}

	memset(responses, 0, sizeof(struct dns_response) * header.an_count);

	/* Aname was request domain */
	memcpy(responses->aname, buffer, strlen(buffer));

	/* Fill out the dns_response structure for each answer. */
	for (i = 0; i < header.an_count; ++ i)
	{
		responses[i].authoritative = authoritative;

		/* Read the domain name from the answer section and verify it matches
		   the name in the question section. */
		bytes_read = _read_domain_name(buffer_index, packet_buffer, packet_length, buffer);
		if (bytes_read == -1)
		{
			free(responses);
			LOG_NORMAL_INFO("response has invalid format!\n");
			return NULL;
		}

		if (! _increment_buffer_index(&buffer_index, max_index, bytes_read))
		{
			free(responses);
			LOG_NORMAL_INFO("response has invalid format!\n");
			return NULL;
		}

		/* The next part contains the type of response in 2 bytes. */
		responses[i].response_type = ntohs(*(uint16_t *)buffer_index);

		if (! _increment_buffer_index(&buffer_index, max_index, sizeof(uint16_t)))
		{
			free(responses);
			LOG_NORMAL_INFO("response has invalid format!\n");
			return NULL;
		}

		/* The response class should be for an Internet address. */
		if (ntohs(*(uint16_t *)buffer_index) != DNS_INET_ADDR)
		{
			free(responses);
			LOG_NORMAL_INFO("invalid response class!\n");
			return NULL;
		}

		if (! _increment_buffer_index(&buffer_index, max_index, sizeof(uint16_t)))
		{
			free(responses);
			LOG_NORMAL_INFO("response has invalid format!\n");
			return NULL;
		}

		/* The next 4 bytes contain the TTL value. */
		responses[i].cache_time = ntohl(*(uint32_t *)buffer_index);
		if (! _increment_buffer_index(&buffer_index, max_index, sizeof(uint32_t)))
		{
			free(responses);
			LOG_NORMAL_INFO("response has invalid format!\n");
			return NULL;
		}

		/* The next 2 bytes contain the length of the RDATA field. */
		rdata_length = ntohs(*(uint16_t *)buffer_index);
		if (! _increment_buffer_index(&buffer_index, max_index, sizeof(uint16_t)))
		{
			free(responses);
			LOG_NORMAL_INFO("response has invalid format!\n");
			return NULL;
		}

		/* At the RDATA field. How we process the data depends on the type of response this is. */
		switch (responses[i].response_type)
		{
			case DNS_A_RECORD:
			{
				responses[i].ip_address = ntohl(*(uint32_t *)buffer_index);
				break;
			}
			
			case DNS_NS_RECORD:
			{
				bytes_read = _read_domain_name(buffer_index, packet_buffer, packet_length, responses[i].name);
				if (bytes_read == -1)
				{
					free(responses);
					LOG_NORMAL_INFO("response has invalid format!\n");
					return NULL;
				}
				
				break;
			}
			
			case DNS_CNAME_RECORD:
			{
				bytes_read = _read_domain_name(buffer_index, packet_buffer, packet_length, responses[i].name);
				if (bytes_read == -1)
				{
					free(responses);
					LOG_NORMAL_INFO("response has invalid format!\n");
					return NULL;
				}
				
				break;
			}

			case DNS_MX_RECORD:
			{
				responses[i].preference = ntohs(*(uint16_t *)buffer_index);

				if (! _increment_buffer_index(&buffer_index, max_index, sizeof(uint16_t)))
				{
					free(responses);
					LOG_NORMAL_INFO("response has invalid format!\n");
					return NULL;
				}

				bytes_read = _read_domain_name(buffer_index, packet_buffer, packet_length, responses[i].name);      
				if (bytes_read == -1)
				{
					free(responses);
					LOG_NORMAL_INFO("response has invalid format!\n");
					return NULL;
				}
				
				rdata_length -= sizeof(uint16_t);
				break;
			}
		}

		/* When we increment the buffer, we may move past the end of the packet at this
		   point. This is OK only if this is the last answer we are processing. */
		if (! _increment_buffer_index(&buffer_index, max_index, rdata_length)
		&& (i + 1 < header.an_count))
		{
			free(responses);
			LOG_NORMAL_INFO("response has invalid format!\n");
			return NULL;
		}
	}  

	return responses;
}

void parse_dns_response(cap_t *cap, unsigned char *buf, int data_len)
{
	int answer_count, i;

	char ip_buffer[MAX_IP_STRING_SIZE];
	
	struct dns_response *responses;

	responses = _parse_dns_response(buf, data_len, &answer_count);
	if (! responses)
		return ;

	//LOG_NORMAL_INFO("--------------------------------\n");
	//LOG_NORMAL_INFO("Aname request domain: %s\n", responses->aname);
	for (i = 0; i < answer_count; ++ i)
	{
		switch(responses[i].response_type)
		{
			case DNS_A_RECORD:
			{
				_format_ip_address(responses[i].ip_address, ip_buffer);
				//LOG_NORMAL_INFO("IP\t%s\t%d\t%s\n", ip_buffer, responses[i].cache_time, 
						//_get_authority_string(responses[i].authoritative));

				/* put traffic hash table */
				if (responses->aname && strlen(responses->aname) > 0)
				{
					//do somthing
				}
				
				break;
			}
			
			case DNS_NS_RECORD:
			{
				//LOG_NORMAL_INFO("NS\t%s\t%d\t%s\n", responses[i].name, responses[i].cache_time, 
						//_get_authority_string(responses[i].authoritative));
				break;
			}
			
			case DNS_CNAME_RECORD:
			{
				//LOG_NORMAL_INFO("CNAME\t%s\t%d\t%s\n", responses[i].name, responses[i].cache_time, 
						//_get_authority_string(responses[i].authoritative));
				break;
			}
			
			case DNS_MX_RECORD:
			{
				//LOG_NORMAL_INFO("MX\t%s\t%d\t%d\t%s\n", responses[i].name, 
					//responses[i].preference, responses[i].cache_time, 
					//_get_authority_string(responses[i].authoritative));
				break;
			}
			
			default:
			{
				//LOG_NORMAL_INFO("ERROR unknown response type\n");
				break;
			}
		}
	}
	//LOG_NORMAL_INFO("--------------------------------\n\n");
	
	free(responses);
}

