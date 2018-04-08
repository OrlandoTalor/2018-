#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

#include "direct.h"
int main()
{
	while (1)
	{
		_mkdir("C:\\Users\\1\\Desktop\\first");
		_mkdir("C:\\Users\\1\\Desktop\\first\\sec");
		_mkdir("C:\\Users\\1\\Desktop\\first\\sec\\thir");
		_mkdir("C:\\Users\\1\\Desktop\\first\\sec\\thir\\four");
		_mkdir("C:\\Users\\1\\Desktop\\first\\sec\\thir\\four\\fif");
	}

	system("pause");
	return 0;
}