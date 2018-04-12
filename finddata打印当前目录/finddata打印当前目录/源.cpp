#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<io.h>
#include<string.h>
#include<time.h>

void ScanFile(char* path)
{

	char s[256] = { 0 };
	strcpy(s, path);
	char sRound[256] = "*.*";
	strcat(s, sRound);


	_finddata_t c_file;
	intptr_t hFile;
	if ((hFile = _findfirst(s, &c_file)) == -1L)
	{//搜索 *.* 如果当前目录没有文件，findfirst返回值为-1
		_findclose(hFile);
		return;
	}
	else
	{
		printf("%s  的目录\n\n", path);
		do
		{
			if (!(c_file.attrib &_A_HIDDEN))
			{

				tm *NewTime;
				NewTime = _localtime64(&c_file.time_write);

				if (c_file.attrib & _A_SUBDIR)
				{
					if (strcmp(c_file.name, ".") != 0 && strcmp(c_file.name, "..") != 0)
					{
						printf("%04d/%02d/%02d    ", 1900 + NewTime->tm_year, NewTime->tm_mon, NewTime->tm_mday);
						printf("%02d:%02d ", NewTime->tm_hour, NewTime->tm_min);
						printf("%10s", "<DIR>");
						printf("%106s\n", c_file.name);
					}
				}
				else
				{
					printf("%04d/%02d/%02d    ", 1900 + NewTime->tm_year, NewTime->tm_mon, NewTime->tm_mday);
					printf("%02d:%02d ", NewTime->tm_hour, NewTime->tm_min);
					printf("%10s", " ");
					printf("%10d", c_file.size);
					printf("%96s\n", c_file.name);
				}
			}
		} while (_findnext(hFile, &c_file) == 0);
	}
}

int main()
{

	//ScanFile("D:\\AAA\\");
	ScanFile("F:\\VS C++\\");

	system("pause");
	return 0;
}