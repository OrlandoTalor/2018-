#include<stdio.h>			
#include<conio.h>			//kbhit()
#include<graphics.h>		//ʱ��

void print_SYSTEMTIME(void * p)
{
	SYSTEMTIME LocTime;
	while (!_kbhit())
	{
		GetLocalTime(&LocTime);
		system("cls");
		puts("System_Time:");
		printf("%04d��%02d��%02d��    ����%d  ", LocTime.wYear, LocTime.wMonth, LocTime.wDay, LocTime.wDayOfWeek);
		printf("%02d:%02d:%02d.%03d\n", LocTime.wHour, LocTime.wMinute, LocTime.wSecond, LocTime.wMilliseconds);
		Sleep(20);
	}
}