/**
monitor 模块: 
负责进程守护
*/

#include "includes.h"

int main()
{
	signal(SIGPIPE, SIG_IGN);
	
	//初始化消息队列
	InitMsgQueue();

	create_monitor_mproxy_thread();
	
    while (1)
	{
	    // 消息处理
	    // 消息的类型有:其他模块对调度中心、手柄查询、设置的响应
	    char recvbuf[MAX_MESSAGE_LEN + 1]= {0};
		int ret = RecvMonitorMsg(recvbuf);
		if (ret > 0)
		{
            // 消息处理
            LOG_NORMAL_INFO("recv data, len = %d\n", ret);
			OnMessage((unsigned char *)recvbuf, ret);
		}
    }
	
	return 0;
}

