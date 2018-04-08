/*作用于字符串s，以包含在delim中的字符为分界符，将s切分成一个个子串；
如果，s为空值NULL，则函数保存的指针SAVE_PTR在下一次调用中将作为起始位置。*/
/*函数的返回值为从指向被分割的子串的指针。*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int DelimiterJudging(const unsigned char* pDelimiter,const unsigned char* c)//delimiter定界符判定
{
	while (*pDelimiter)
	{
		if (*c == *pDelimiter)
			return 1;//是
		++pDelimiter;
	}
	return 0;//不是
}
char* StringToken(const char*string_org, const char* demial)//算法主体
{
	static unsigned char* last;
	unsigned char* str;
	const unsigned char* ctrl = (const unsigned char*)demial;
	if (string_org)
	{//如果字符串不为空（或开头没有0结尾）
		str = (unsigned char*)string_org;//str指向开始位置
	}
	else
	{//如果字符串为空
		str = last;//str指向上一次离开的位置
	}

	while (DelimiterJudging(ctrl,str))
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
		if (DelimiterJudging(ctrl, str))//如果是分界符
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
	char str[] = "one,,two......three??.,\n\tfour\nfive\tsix\t\tseven\n\neight,nine.ten\n";
	char seps[] = " ,.\n\t?";
	char* token;
	token = StringToken(str, seps);
	while (token != NULL)
	{
		printf("%s\n", token);
		token = StringToken(NULL, seps);
	}
	system("pause");
	return 0;
}