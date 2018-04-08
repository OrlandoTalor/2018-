#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

char*  StrTok_r(char* string_org, const char* demial)
{
	static unsigned char* last;
	unsigned char* str;
	const unsigned char* ctrl = (const unsigned char*)demial;
	unsigned char map[32];//新建数组包含32个u_char变量
	int count;//位标记

	//将每一位赋值为零，清空数组
	for (count = 0; count < 32; count++)
		map[count] = 0;

	//将分界符保存在map中*
	do {
		map[*ctrl >> 3] |= (1 << (*ctrl & 7));
	} while (*ctrl++);

	
	if (string_org)
	{//如果字符串不为空（或开头没有0结尾）
		str = (unsigned char*)string_org;//str指向开始位置
	}
	else
	{//如果字符串为空
		str = last;//str指向上一次离开的位置
	}
	while ((map[*str >> 3] & (1 << (*str & 7))) && *str)
	{//判断该位是不是分界符，如果是，str++去下一位，直到找到不是分界符的字符
		str++;
	}
	//这里str是原字符串的有效串
	//（经过循环会被添加"\0'在分界符处，
	//			从上一次添加的"\0'之后一位开始，到原字符串结尾为str）
	//将新的有效串str覆盖到原字符串string_org
	string_org = (char*)str;

	//利用指针*str在 下一个 分界符 处 覆盖'\0'
	for (; *str; str++)//////////*str != '\0'如果已经到'\0'结尾，不进入循环
	{
		if (map[*str >> 3] & (1 << (*str & 7)))//如果是分界符
		{
			*str++ = '\0';//写入'\0' 并++ 去下一位
			break;
		}
	}
	last = str;//保留首个有效位到last
	if (string_org == (char*)str)
	{//如果已经到'\0'结尾，不再进入循环，程序结束
		return NULL;
	}
	else
	{//没到'\0'结尾，输出
		return string_org;
	}
}


int main()
{
	char str[100] = "I want my life,apple\nnext\tline\n";
	char seps[20] = " ,\n\t";
	char* token;
	token = StrTok_r(str, seps);
	while (token != NULL)
	{
		printf("%s\n", token);
		token = StrTok_r(NULL, seps);//???
	}

	system("pause");
	return 0;
}

/*int main()
{
	char str[100] = "I want my life,apple\nnext\tline\n";
	char seps[20] = " ,\n\t";
	char* token;
	token = StrTok_r(str, seps);
	while (token != NULL)
	{
		printf("%s\n", token);
		token = StrTok_r(NULL, seps);//???
	}

	system("pause");
	return 0;
	}*/