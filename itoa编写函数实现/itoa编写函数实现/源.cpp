#include<stdio.h>
#include<stdlib.h>
int Itoa(int n, char* s, int Size, int nRadix)
{
	int i = 0;
	int sign = n;
	if (sign < 0)
		n = -n;//�õ�n�ľ���ֵ

	//ȡÿһλ��s��
	while (n)
	{//���Ʊ仯Radix
		s[i] = n % nRadix + '0';
		n = n / nRadix;
		i++;
	}
	if (sign < 0 && i + 1 >= Size || sign > 0 && i >= Size)
		//�и���ʱ����һλ
		return 0;				//���������0
	if (sign < 0)
		s[i] = '-';

	//puts(s);

	int j = -1;
	while (s[j])
		j++;
	s[j] = '\0';//��ӽ�β��������������Reverse����
	i = 0;
	while (i < j - 1)
	{
		char t = s[i];
		s[i] = s[j - 1];
		s[j - 1] = t;
		i++;
		j--;
	}
	return 1;			//û�����������0
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