#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<time.h>
#include<conio.h>
void print_Localtime(void* p)
{//	localtime		time		mktime
	tm *NewTime;
	
	while (!_kbhit())
	{	
		__time64_t long_time;
		_time64(&long_time);
		NewTime = _localtime64(&long_time);
		system("cls");
		puts("Local_Time:");
		printf("%04d年%02d月%02d日    星期%d  ", 1900+NewTime->tm_year , NewTime->tm_mon, NewTime->tm_mday, NewTime->tm_wday);
		printf("%02d:%02d:%02d\n", NewTime->tm_hour, NewTime->tm_min, NewTime->tm_sec);
		Sleep(1000);
	}

	



}