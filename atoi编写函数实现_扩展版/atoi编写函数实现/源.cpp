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
	//ѭ������ʱ��ptָ���һ�����ֵ�ǰһλ
	//nptrָ���һ������
	sign = (int)(unsigned)*pt;//ȡ�÷���λ

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
	//��ˣ�������atoi�޷�ʵ��˳����ȡ���֣�
	//�б�Ҫ�Ļ�����չһ��
	//����ǰһλ����Ǹ�����Ϊ��ֵ
	char s[20] = " - 321a123";

	int n = atoi(s);
	int m = Atoi(s);

	printf("n = %d\nm = %d\n", n, m);
	system("pause");
	return 0;
}