#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int Strcmp(char* sDestination,
	int n,
	const char* sResource)
{
	int i = 0;
	//����һ�����Ϸ��ģ�����ѭ���������ɵó���������Ϸ����鲻�����ͨ�������迼�ǣ�
	//ʵ�����ڶ������ѭ������β֮ǰ�����ɵó����
	while (i < n)
	{
		if ((unsigned)sDestination[i] > (unsigned)sResource[i])
			return 1;
		else if ((unsigned)sDestination[i] < (unsigned)sResource[i])
			return -1;
		i++;
	}
	return 0;
}

int main()
{
	char sDes[10] = "ABCD";
	char sRes[20] = "ABCD";
	int m = strcmp(sDes, sRes);
	int n = Strcmp(sDes, _countof(sDes), sRes);



	system("pause");
	return 0;
}