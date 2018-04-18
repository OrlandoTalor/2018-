#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<time.h>
#include<conio.h>			//kbhit()
#include<graphics.h>		//时间


void both()
{//	localtime		time		mktime
	tm *NewTime;
	SYSTEMTIME LocTime;
	while (!_kbhit())
	{
		__time64_t long_time;
		_time64(&long_time);
		NewTime = _localtime64(&long_time);
		system("cls");
		puts("Local_Time:");
		printf("%04d年%02d月%02d日    星期%d  ", 1900 + NewTime->tm_year, NewTime->tm_mon, NewTime->tm_mday, NewTime->tm_wday);
		printf("%02d:%02d:%02d\n", NewTime->tm_hour, NewTime->tm_min, NewTime->tm_sec);
		


		GetLocalTime(&LocTime);
	
		puts("System_Time:");
		printf("%04d年%02d月%02d日    星期%d  ", LocTime.wYear, LocTime.wMonth, LocTime.wDay, LocTime.wDayOfWeek);
		printf("%02d:%02d:%02d.%03d\n", LocTime.wHour, LocTime.wMinute, LocTime.wSecond, LocTime.wMilliseconds);
		Sleep(20);
	}





}