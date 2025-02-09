#ifndef __TIME_H__#define __TIME_H__#include "common.h"#define DEBUG_TIME	0
#define CLOCK_REALTIME            	0 #define CLOCK_MONOTONIC            	1 #define CLOCK_PROCESS_CPUTIME_ID    2 #define CLOCK_THREAD_CPUTIME_ID     3 #define CLOCK_MONOTONIC_RAW         4 #define CLOCK_REALTIME_COARSE       5 #define CLOCK_MONOTONIC_COARSE      6 #define CLOCK_BOOTTIME            	7 #define CLOCK_REALTIME_ALARM        8 #define CLOCK_BOOTTIME_ALARM        9 #define CLOCK_SGI_CYCLE            	10    /* Hardware specific */ #define CLOCK_TAI            		11#define MAX_CLOCKS            		16#define DEBUG_TIME					0#define SYSTEM_SEC	get_system_clock_sec()#define CONVERTSEC(H, M, S)	(H * 3600 + M * 60 + S)void GetSystemTime(int *Year, int *Mon, int *Data, int *Hour, int *Min);void GetAllSystemTime(int *Year, int *Mon, int *Data, int *Hour, int *Min, int *Sec, int *Weekday);int GetSystemTime_Sec();char * weekday(int day);char * month(int month);

long GetTimestrip_us();void time_init();unsigned int get_system_clock_sec(void);#endif


