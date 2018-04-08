#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

char*  StrTok_r(char* string_org, const char* demial)
{
	static unsigned char* last;
	unsigned char* str;
	const unsigned char* ctrl = (const unsigned char*)demial;
	unsigned char map[32];//�½��������32��u_char����
	int count;//λ���

	//��ÿһλ��ֵΪ�㣬�������
	for (count = 0; count < 32; count++)
		map[count] = 0;

	//���ֽ��������map��*
	do {
		map[*ctrl >> 3] |= (1 << (*ctrl & 7));
	} while (*ctrl++);

	
	if (string_org)
	{//����ַ�����Ϊ�գ���ͷû��0��β��
		str = (unsigned char*)string_org;//strָ��ʼλ��
	}
	else
	{//����ַ���Ϊ��
		str = last;//strָ����һ���뿪��λ��
	}
	while ((map[*str >> 3] & (1 << (*str & 7))) && *str)
	{//�жϸ�λ�ǲ��Ƿֽ��������ǣ�str++ȥ��һλ��ֱ���ҵ����Ƿֽ�����ַ�
		str++;
	}
	//����str��ԭ�ַ�������Ч��
	//������ѭ���ᱻ���"\0'�ڷֽ������
	//			����һ����ӵ�"\0'֮��һλ��ʼ����ԭ�ַ�����βΪstr��
	//���µ���Ч��str���ǵ�ԭ�ַ���string_org
	string_org = (char*)str;

	//����ָ��*str�� ��һ�� �ֽ�� �� ����'\0'
	for (; *str; str++)//////////*str != '\0'����Ѿ���'\0'��β��������ѭ��
	{
		if (map[*str >> 3] & (1 << (*str & 7)))//����Ƿֽ��
		{
			*str++ = '\0';//д��'\0' ��++ ȥ��һλ
			break;
		}
	}
	last = str;//�����׸���Чλ��last
	if (string_org == (char*)str)
	{//����Ѿ���'\0'��β�����ٽ���ѭ�����������
		return NULL;
	}
	else
	{//û��'\0'��β�����
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