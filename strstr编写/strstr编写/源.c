//strstr, strtok, _strupr, strlwr
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
char* StrStr(const char *str, const char *strSearch)
{

	while (*str)//�ڴ��ַ����б���
	{
		if (*str == *strSearch)//���ڴ��ַ������ҵ�С�ַ�������ĸ
		{
			char* pSch = strSearch;
			char* pstr = str;
			while (*pSch)//����С�ַ���,��ָ�����
			{
				if (*pSch != *pstr)
					break;//������ȫ��ͬʱ������С�ַ����ı�����ȥ������һ��
				++pSch;
				++pstr;
			}
			if (*pSch == '\0')
				return str;//����С������û������������С�����ָ��str���׵�ַ��
		}
		++str;
	}
	return NULL;
}


int main()
{
	char str[] = "lazy";
	char string[] = "The quick brown dog jumps over the lazy fox";
	char fmt1[] = "         1         2         3         4         5";
	char fmt2[] = "12345678901234567890123456789012345678901234567890";

	char* pdest = 0;
	int result = 0;

	printf("String to be searched:\n     %s\n", string);
	printf("     %s\n     %s\n\n", fmt1, fmt2);

	pdest = strstr(string, str);
	result = (int)(pdest - string + 1);
	if (pdest != NULL)
		printf("%s found at position %d\n", str, result);
	else
		printf("%s not found\n", str);
	system("pause");
	return 0;
}

/*
char* pdest = str;
while (pdest)//�ڴ��ַ����б���
{
if (*pdest == *strSearch)//���ڴ��ַ������ҵ�С�ַ�������ĸ
{
char* pSch = strSearch;
while (*pSch)//����С�ַ���,��ָ�����
{
if (*pSch != *pdest)
{//������ȫ��ͬʱ������С�ַ����ı�����ȥ������һ��
break;
}
++pSch;
++pdest;
}
if (*pSch == 0)
return pdest-(pSch-strSearch);
}
++pdest;
}
return 0;
*/