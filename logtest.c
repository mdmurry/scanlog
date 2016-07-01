#include <syslog.h>
#include <stdio.h>

void main(void)
{
	setlogmask(LOG_UPTO (LOG_NOTICE));

//	openlog("logtest", LOG_CONS | LOG_PID | LOG_NDELAY, LOG_LOCAL1);
	openlog("logtest", LOG_CONS | LOG_PID | LOG_NDELAY, LOG_USER);
	syslog(LOG_NOTICE, "LOGTEST: Program started by User %d", getuid());
	syslog(LOG_INFO, "LOGTEST: A tree falls in the forest");
	closelog();
	printf("Program run by user: %d\n", getuid());
} 
