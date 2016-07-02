#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <wiringPi.h>

#define MAX_LINE 1024

void main(void)
{
	FILE *f;
	char buffer[MAX_LINE];
	char *ptr;
	unsigned count = 0;

	printf("\nLogCheck - Reading from /var/log/syslog\n");

	wiringPiSetup();
	pinMode(0,OUTPUT);

	f = fopen("/var/log/syslog","r");
	if(f == NULL)
	{
		printf("Error opening /var/log/syslog\n");
		return;
	}
	while(fgets(buffer, (MAX_LINE-1), f))
	{
		ptr = strstr(buffer,"scanlogd: 192");	
		if(ptr)
		{
			printf("%s", buffer);
			count++;
		}
	}
	if(count>0)
	{
		if(count==1)
			printf("Warning: One port scan has occurred - notify network security administrator immediately!\n");
		else
			printf("Warning: %d port scans have occurred - notify network security adminstrator immediately!\n", count);
	}
	else
	{
		printf("No port scans have occurred\n");
	}
	fclose(f);
}
