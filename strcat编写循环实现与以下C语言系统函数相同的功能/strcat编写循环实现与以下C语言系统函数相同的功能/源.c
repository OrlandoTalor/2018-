#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int Strcat(	char* sDestination, 
			int n, 
			const char* sResource)
{
	//��ȫ�汾�У��ַ����鶨��ĳ��Ȳ�Ӱ������ִ��
	//�����Ŀ�����鲻����'\0'��β���򱨴�
	int i = 0;
	while (sDestination[i])//ȥ��Ŀ�������'\0'��βλ��
		i++;

	int j = 0;
	while (i < n && sResource[j])//����Ŀ������д��֮ǰ &&���� Դ���黹û��'\0'��β��
		sDestination[i++] = sResource[j++];


	if (sDestination[n - 1] != '\0')//������һλ����'\0'��β������
		return 0;

	return 1;
}

int main()
{
	char sDes[10] = "ABCD";
	char sRes[20] = "1";

	if (!Strcat(sDes, _countof(sDes), sRes))
	{
		puts("Error,the Destinantion array not long enough!");

		system("pause");
		return -1;
	}

	puts(sDes);

	system("pause");
	return 0;
}