#ifndef __SERVER_H__
#define __SERVER_H__


#include "includes.h"

#if (PROCESS_NUM > 1)
extern sprocess_lock *g_sprolock;				//������
#endif

int create_server(char * bindip, int listen_port, int listen_counts);
int epoll_server_exit();
int get_listenfd();
int get_listen_port();

int get_epollfd();

#endif

