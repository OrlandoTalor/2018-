//strstr, strtok, _strupr, strlwr
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
char* StrStr(const char *str, const char *strSearch)
{

	while (*str)//在大字符串中遍历
	{
		if (*str == *strSearch)//当在大字符串中找到小字符串首字母
		{
			char* pSch = strSearch;
			char* pstr = str;
			while (*pSch)//遍历小字符串,大串指针跟随
			{
				if (*pSch != *pstr)
					break;//当不完全相同时，结束小字符串的遍历，去大串找下一个
				++pSch;
				++pstr;
			}
			if (*pSch == '\0')
				return str;//遍历小串结束没有异样，返回小串起点指针str（首地址）
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
while (pdest)//在大字符串中遍历
{
if (*pdest == *strSearch)//当在大字符串中找到小字符串首字母
{
char* pSch = strSearch;
while (*pSch)//遍历小字符串,大串指针跟随
{
if (*pSch != *pdest)
{//当不完全相同时，结束小字符串的遍历，去大串找下一个
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