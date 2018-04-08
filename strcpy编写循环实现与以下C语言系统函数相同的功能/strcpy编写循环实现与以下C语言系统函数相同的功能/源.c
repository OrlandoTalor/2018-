#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int Strcpy(char* sDestination, int n, const char* sResource)
{
	//安全版本中，字符数组定义的长度不影响程序的执行
	//但如果目标数组不存在'\0'结尾，则报错
	int i = 0;
	while (i <n)
		sDestination[i] = sResource[i++];
	if (sDestination[n - 1] != '\0')
		return 0;
	return 1;
}

int main()
{
	char sDes[];
	char sRes[20] = { "hgy65ucvy9" };

	if (!Strcpy(sDes, _countof(sDes), sRes))
	{
		puts("Error,the Destinantion array not long enough!");
		system("pause");
		return -1;
	}
	puts(sDes);
	system("pause");
	return 0;
}