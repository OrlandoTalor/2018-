/*�������ַ���s���԰�����delim�е��ַ�Ϊ�ֽ������s�зֳ�һ�����Ӵ���
�����sΪ��ֵNULL�����������ָ��SAVE_PTR����һ�ε����н���Ϊ��ʼλ�á�*/
/*�����ķ���ֵΪ��ָ�򱻷ָ���Ӵ���ָ�롣*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int DelimiterJudging(const unsigned char* pDelimiter,const unsigned char* c)//delimiter������ж�
{
	while (*pDelimiter)
	{
		if (*c == *pDelimiter)
			return 1;//��
		++pDelimiter;
	}
	return 0;//����
}
char* StringToken(const char*string_org, const char* demial)//�㷨����
{
	static unsigned char* last;
	unsigned char* str;
	const unsigned char* ctrl = (const unsigned char*)demial;
	if (string_org)
	{//����ַ�����Ϊ�գ���ͷû��0��β��
		str = (unsigned char*)string_org;//strָ��ʼλ��
	}
	else
	{//����ַ���Ϊ��
		str = last;//strָ����һ���뿪��λ��
	}

	while (DelimiterJudging(ctrl,str))
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
		if (DelimiterJudging(ctrl, str))//����Ƿֽ��
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