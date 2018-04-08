#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
void AddData(int, int);
int *arr;//�����׵�ַ

void Save()
{
	FILE* pf = NULL;
	fopen_s(&pf, "arr.orlando", "w");
	if (!pf)
	{
		puts("д��ʧ�ܣ�");
		return;
	}
	int i = 0;
	//++iд�����棬��Ϊ�˽�����0Ҳд�룬������Loadʱ������0��β��
	while (arr[i])
	{
		fwrite(&arr[i], 1, sizeof(arr[0]), pf);
		++i;
	}
	fclose(pf);
}

void Load()
{
	FILE* pf = NULL;
	fopen_s(&pf, "arr.orlando", "r");
	if (!pf)
	{
		puts("д��ʧ�ܣ�");
		return;
	}
	int n = 0, i = 0;
	while (fread(&n, 1, sizeof(arr[0]), pf) == sizeof(arr[0]))
	{
		AddData(i, n);
		++i;
	}
	fclose(pf);
}



void Browse()
{
	system("cls");
	int i = 0;
	while (arr[i])
	{
		printf("arr[%d] = %d\n", i, arr[i]);
		++i;
	}
	printf("����%d��Ԫ�ء�\n\n", i);
	system("pause");
}

void AddData(int i, int nNumb)
{
	int * NewArr = (int*)calloc(i + 2, sizeof(int));
	memcpy(NewArr, arr, sizeof(int)*(i + 1));
	free(arr);
	arr = NewArr;
	NewArr = 0;
	arr[i] = nNumb;
	Save();
}

void Add()
{
	int i = 0, j = 0;
	while (arr[i])
		++i;

	int nNumb = 0;
	printf("������������(����#�˳�)��\n");
	printf("arr[%d] = ", i);
	fflush(stdin);
	scanf_s("\n%d", &nNumb);
	if (nNumb == (int)'#')
		return;
	else
	{
		AddData(i, nNumb);
	}
}

void DeleteData(int ToBeDelete)
{//ɾ��ʱд��-1�����ｫ-1Ԫ��ժ���������ڶ����д��ڣ������鷳
	int arrCount = 0;
	while (arr[arrCount++]);//һֱȡ����0Ԫ�أ��õ�����arrCount(���++���ְ�0Ԫ�ؼ����ˣ�������ԭ���鳤�ȣ�
	int *NewArr = NULL;
	NewArr = (int*)calloc(arrCount - 1, sizeof(int));//�½����飬��ԭ������1��ȥ��Ҫɾ����Ԫ�أ������ֶ���
	int i = 0, j = 0;
	while (arr[i])
	{
		if (i == ToBeDelete)
			++i;//����Ҫɾ����Ԫ�أ�+1����
		NewArr[j++] = arr[i++];
	}
	arr = NewArr;
}

void Delete()
{
	int nNumb = 0;
	puts("������Ҫɾ����Ԫ�أ�");
	fflush(stdin);
	scanf_s("%d", &nNumb);

	int i = 0;
	int flag = 0;
	while (arr[i])
	{
		if (nNumb == i)
		{
			DeleteData(i);
			flag = 1;
			break;
		}
		++i;
	}
	if (flag == 1)
	{
		puts("ɾ���ɹ���");
		Save();
	}
	else
		puts("û�ҵ�Ҫɾ�������ݡ�����");

	system("pause");
}

void Modify()
{
	int nNumb = 0;
	puts("������Ҫ���ҵ�Ԫ�أ�");
	fflush(stdin);
	scanf_s("%d", &nNumb);

	int i = 0;
	int flag = 0;
	while (arr[i])
	{
		if (nNumb == i)
		{
			puts("�ҵ����£�");
			printf("arr[%d] = %d\n", i, arr[i]);
			puts("�������µ����֣�");
			fflush(stdin);
			scanf_s("%d", &arr[i]);
			flag = 1;
			Browse();
			return;
		}
		++i;
	}
	if (flag != 1)
		puts("û�ҵ�Ҫ���ҵ�Ԫ�ء�����");

	system("pause");
}

void Search()
{
	int nNumb = 0;
	puts("������Ҫ���ҵ�Ԫ�أ�");
	fflush(stdin);
	scanf_s("%d", &nNumb);

	int i = 0;
	int flag = 0;
	while (arr[i])
	{
		if (nNumb == i)
		{
			puts("�ҵ����£�");
			printf("arr[%d] = %d\n", i, arr[i]);
			flag = 1;
			break;
		}
		++i;
	}
	if (flag != 1)
		puts("û�ҵ�Ҫ���ҵ�Ԫ�ء�����");

	system("pause");
}

char Menu()
{
	system("cls");
	puts("1.Browse");
	puts("2.Add");
	puts("3.Delete");
	puts("4.Mudify");
	puts("5.Search");
	puts("0.Exit");
	char c = 0;
	printf("��ѡ��");
	fflush(stdin);
	scanf_s("\n%c", &c, sizeof(c));
	switch (c)
	{
	case '1':
		Browse();
		break;
	case '2':
		Add();
		break;
	case '3':
		Delete();
		break;
	case '4':
		Modify();
		break;
	case '5':
		Search();
		break;
	case '0':
		puts("�˳�������");
		break;
	default:
		puts("������Ч��");
	}
	return c;
}
int main()
{
	int *p = NULL;
	p = (int*)malloc(sizeof(int));
	memset(p, 0, sizeof(int));
	
	
	//�ȶ���1����Ԫ�أ��Ժ�ÿ��һ��Ԫ��֮ǰ��������һ��Ԫ�صĳ���
	//��֤�����������һ����λ��Ҳ�Ƿ����ҵ���β������ѭ����
	arr = (int*)calloc(1, sizeof(int));


	FILE* pf = NULL;
	fopen_s(&pf, "arr.orlando", "a");
	if (!pf)
	{
		puts("�ļ���ʼ��ʧ�ܣ�");
		return;
	}
	fclose(pf);

	Load();

	while (Menu() != '0');

	system("pause");
	return 0;
}