#include<stdio.h>
#include<stdlib.h>

int Atoi(const char* nptr)
{
	int c = 0;
	int total = 0;
	int sign = 0;
	//�����ո�
	while (isspace((int)(unsigned)*nptr))
		++nptr;
	c = (int)(unsigned)*nptr++;//���ǿո�ĵ�һλ��ֵ��c������ָ��ָ����һλ

	//����ַ�����ʼ��ʱ�����������ţ��򽫴�λ��ֵ��sign������
	//���Ƿ��ţ���signֵΪ���֣�û��ϵ������ֻ�ж��ǲ��Ǹ���
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