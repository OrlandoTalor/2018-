#include<stdio.h>
#include<stdlib.h>

int Atoi(const char* nptr)
{
	int c = 0;
	int total = 0;
	int sign = 0;
	//跳过空格
	while (isspace((int)(unsigned)*nptr))
		++nptr;
	c = (int)(unsigned)*nptr++;//将非空格的第一位赋值给c，并将指针指向下一位

	//如果字符串初始化时带有正负符号，则将此位赋值给sign并跳过
	//不是符号，则sign值为数字，没关系，后面只判定是不是负号
	sign = c;
	if (sign == '+' || sign == '-')
		c = (int)(unsigned)*nptr++;

	while (isdigit(c))
	{
		total = 10 * total + (c - '0');
		c = (int)(unsigned)*nptr++;
	}
	if (sign == '-')
		return -total;
	return total;
}

int main()
{//atoi
	char s[20] = "\n + 321a123";

	int n = atoi(s);
	int m = Atoi(s);

	printf("n = %d\nm = %d\n", n, m);
	system("pause");
	return 0;
}