#include<stdio.h>
#include<stdlib.h>

void my_itoa(int n, char s[])
{
	int i, j, sign;

	if ((sign = n) < 0)    //��¼����    
		n = -n;         //ʹn��Ϊ����    
	i = 0;
	do {
		s[i++] = n % 10 + '0';    //ȡ��һ������    

	} while ((n /= 10) > 0);      //ѭ�����    

	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	for (j = i - 1; j >= 0; j--)        //���ɵ�����������ģ�����Ҫ�������    
		printf("%c", s[j]);
}

int main()
{



	system("pause");
	return 0;
}