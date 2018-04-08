#include<stdio.h>
#include<stdlib.h>
int Itoa(int n, char* s, int Size, int nRadix)
{
	int i = 0;
	int sign = n;
	if (sign < 0)
		n = -n;//得到n的绝对值

	//取每一位到s中
	while (n)
	{//进制变化Radix
		s[i] = n % nRadix + '0';
		n = n / nRadix;
		i++;
	}
	if (sign < 0 && i + 1 >= Size || sign > 0 && i >= Size)
		//有负号时，多一位
		return 0;				//溢出，返回0
	if (sign < 0)
		s[i] = '-';

	//puts(s);

	int j = -1;
	while (s[j])
		j++;
	s[j] = '\0';//添加结尾符，不参与后面的Reverse反序
	i = 0;
	while (i < j - 1)
	{
		char t = s[i];
		s[i] = s[j - 1];
		s[j - 1] = t;
		i++;
		j--;
	}
	return 1;			//没有溢出，返回0
}

int main()
{//itoa
	int n = 589621;
	char s[8] = { 0 };
	//_itoa_s(n, s, sizeof(s), 10);
	if (!Itoa(n, s, sizeof(s), 8))
	{
		puts("Length over flow");
		system("pause");
		return -1;
	}
	puts(s);
	system("pause");
	return 0;
}