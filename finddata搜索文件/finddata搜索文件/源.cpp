#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<io.h>
#include<string.h>
#include<time.h>

void ScanFile(char* path, char* Find)
{

	char s[256] = { 0 };
	strcpy(s, path);
	strcat(s, "\\");
	strcat(s, "*.*");


	_finddata_t c_file;
	intptr_t hFile;
	if ((hFile = _findfirst(s, &c_file)) == -1L)
	{//搜索 *.* 如果当前目录没有文件，findfirst返回值为-1
		_findclose(hFile);
		return;
	}
	else
	{

		do
		{
			tm *NewTime;
			NewTime = _localtime64(&c_file.time_write);

			if (c_file.attrib & _A_SUBDIR && !(c_file.attrib &_A_HIDDEN))
			{
				if (strcmp(c_file.name, ".") != 0 && strcmp(c_file.name, "..") != 0)
				{
					strcpy(s, path);
					strcat(s, "\\");
					strcat(s, c_file.name);
					strcat(s, "\\");

					ScanFile(s, Find);
				}
			}
			else
			{
				if (strstr(c_file.name, Find) != NULL)
				{

					printf("%s  的目录\n\n", path);
					printf("%-17s%25s%34s\n\n", "time_write", "file_size(kb)", "file_name");
					printf("%04d/%02d/%02d    ", 1900 + NewTime->tm_year, 1 + NewTime->tm_mon, NewTime->tm_mday);
					printf("%02d:%02d ", NewTime->tm_hour, NewTime->tm_min);
					printf("%10s", " ");
					printf("%10d", c_file.size);
					printf("%36s\n", c_file.name);
				}
			}
		} while (_findnext(hFile, &c_file) == 0);
	}
}

int main()
{

	//ScanFile("D:\\AAA\\",".Orlando");
	//ScanFile("d:\\", ".cpp");
	puts("请输入要查找的目录，如\"c:\\Users\\1\"或“C:”\n");
	char sPath[256] = { 0 };
	scanf("%s", sPath);
	puts("请输入要查找文件名（或部分文件名，后缀等），如\".cpp\"\n");
	char sFind[256] = { 0 };
	scanf("%s", sFind);

	ScanFile(sPath, sFind);


	system("pause");
	return 0;
}