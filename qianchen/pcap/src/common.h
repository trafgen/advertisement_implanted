
#ifndef  __COMMON_H__
#define  __COMMON_H__
#include <arpa/inet.h>
#include <alloca.h>

#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>

#include <limits.h>
#include <libgen.h>
#include <linux/sockios.h>
#include <linux/netlink.h>
#include <linux/rtnetlink.h>

#include <math.h>

#include <netinet/in.h>
#include <netdb.h>
#include <netinet/tcp.h>
#include <net/if.h>
#include <netinet/if_ether.h>

#include <pthread.h>
#include <resolv.h>
#include <time.h> 

#include <unistd.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>

#include <signal.h>
#include <stdlib.h>

#include <sys/time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/epoll.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/sendfile.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/wait.h>
#include <sys/file.h>
#include <sys/param.h>
#include <sys/ioctl.h> 
#include <sys/shm.h>
#include <sys/msg.h>
#include <sys/queue.h>

#include <sys/sysinfo.h>

#include <event2/event.h>  
#include <event2/buffer.h>  
#include <event2/bufferevent.h>  
#include <event2/bufferevent_ssl.h>
#include <event2/event.h>
#include <event2/event_struct.h>
#include <event2/http.h>
#include <event2/buffer.h>
#include <event2/util.h>
#include <event2/keyvalq_struct.h>
#include <event2/dns.h>
#include <event2/http_struct.h>

#include <json.h>

#include <pcap/pcap.h>


#define _exit_(t) {\
	return t; \
}
#define _continue_(t) {\
	sleep(t);\
	continue; \
}


#define DEBUG_ON	1


#if DEBUG_ON
#define VAL_LOG(first...) {\
    printf("[PID:%d][%s][%s]:%d ", getpid(), "pcap", __FUNCTION__, __LINE__);\
    printf(first);\
    fflush(stdout);\
}
#else
#define VAL_LOG(first...)	;
#endif

#if DEBUG_ON
#define VAL_PERROR(first...) {\
    printf("[PID:%d][%s][%s][perror]:%d ", getpid(), "pcap", __FUNCTION__, __LINE__);\
    printf(first);\
    printf(" errno = %d: %s\n", errno, strerror(errno));\
    fflush(stdout);\
}
#else
#define VAL_PERROR(first...)	;
#endif

#endif

