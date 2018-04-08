#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int Strcat(	char* sDestination, 
			int n, 
			const char* sResource)
{
	//安全版本中，字符数组定义的长度不影响程序的执行
	//但如果目标数组不存在'\0'结尾，则报错
	int i = 0;
	while (sDestination[i])//去到目标数组的'\0'结尾位置
		i++;

	int j = 0;
	while (i < n && sResource[j])//（将目标数组写满之前 &&并且 源数组还没到'\0'结尾）
		sDestination[i++] = sResource[j++];


	if (sDestination[n - 1] != '\0')//如果最后一位不是'\0'结尾，报错
		return 0;

	return 1;
}

int main()
{
	char sDes[10] = "ABCD";
	char sRes[20] = "1";

	if (!Strcat(sDes, _countof(sDes), sRes))
	{
		puts("Error,the Destinantion array not long enough!");

		system("pause");
		return -1;
	}

	puts(sDes);

	system("pause");
	return 0;
}