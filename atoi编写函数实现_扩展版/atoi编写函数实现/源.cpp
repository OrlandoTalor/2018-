#include<stdio.h>
#include<stdlib.h>

int isdigit(int x)
{
	if (x <= '9'&&x >= '0')
		return 1;
	else
		return 0;

}

int Atoi(char* nptr)
{
	int total = 0;
	int sign = 0;
	int c = (int)(unsigned)*nptr;
	char* pt = nptr;
	while (!isdigit(c))
	{
		pt = nptr++;
		c = (int)(unsigned)*nptr;
	}
	//循环结束时，pt指向第一个数字的前一位
	//nptr指向第一个数字
	sign = (int)(unsigned)*pt;//取得符号位

	while (isdigit(c))
	{
		total = 10 * total + (c - '0');
		c = (int)(unsigned)*++nptr;
	}

	if (sign == '-')
		return -total;
	else
		return total;

}

int main()
{//atoi
	//char s[20] = "\n -'+321a123";	
	//如此，基础版atoi无法实现顺利读取数字，
	//有必要的话，扩展一下
	//数字前一位如果是负号则为负值
	char s[20] = " - 321a123";

	int n = atoi(s);
	int m = Atoi(s);

	printf("n = %d\nm = %d\n", n, m);
	system("pause");
	return 0;
}