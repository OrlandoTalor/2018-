#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int IsMark(char *p)
{
	return *p == '+' || *p == '-' || *p == '*' || *p == '/';
}

double Add(double a, double b)
{
	return a + b;
}

double Sub(double a, double b)
{
	return a - b;
}

double Mul(double a, double b)
{
	return a * b;
}

double Div(double a, double b)
{//处理除数为0
	if (b == 0)
	{
		puts("Divisor cannot be zero!");
		exit(0);
	}
	return a / b;
}

double(*Cal)(double a, double b);


int main(int argc, char* argv[])
{
	int n = 1;
	char sResource[100] = { 0 };
	while (n < argc)//先去除所有空格，并整理到字符串当中
		strcat_s(sResource, sizeof(sResource), argv[n++]);

	//判断溢出
	int i = 0;
	for (i = 0; i < 100; ++i)
		if (sResource[i] == '\0')
			break;
	if (i == 100)
	{
		puts("Overflow!");
		exit(0);
	}

	for (i = 0; i < 100 && sResource[i] != 0 && sResource[i] != -2; ++i)
		printf("sResource[%d] = %d\n", i, sResource[i]);

	/*printf("\ti = %d\n\targc = %d\n", i, argc);
	puts(sResource);*/

	i = 0;
	char sLeft[100] = { 0 };
	char sRight[100] = { 0 };
	char cMark = 0;
	int nRightOrigin = 0;
	while (sResource[i])
	{
		if (IsMark(&sResource[i]))//先判断是不是运算符
			cMark = sResource[i++];
		if (!cMark)//找到运算符之前
			sLeft[i] = sResource[i++];
		else
			sRight[nRightOrigin++] = sResource[i++];
	}
	double fLeft = atof(sLeft);
	double fRight = atof(sRight);
	switch (cMark)
	{
	case '+':
		Cal = Add;
		break;
	case '-':
		Cal = Sub;
		break;
	case '*':
		Cal = Mul;
		break;
	case '/':
		Cal = Div;
	}
	printf("%.2lf %c %.2lf = %.2lf\n", fLeft, cMark, fRight, Cal(fLeft,fRight));

	system("pause");
	return 0;
}