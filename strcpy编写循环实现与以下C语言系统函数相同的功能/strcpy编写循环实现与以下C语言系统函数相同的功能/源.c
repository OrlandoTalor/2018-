#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int Strcpy(char* sDestination, int n, const char* sResource)
{
	//��ȫ�汾�У��ַ����鶨��ĳ��Ȳ�Ӱ������ִ��
	//�����Ŀ�����鲻����'\0'��β���򱨴�
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