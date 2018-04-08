#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
void AddData(int, int);
int *arr;//数组首地址

void Save()
{
	FILE* pf = NULL;
	fopen_s(&pf, "arr.orlando", "w");
	if (!pf)
	{
		puts("写入失败！");
		return;
	}
	int i = 0;
	//++i写在上面，是为了将最后的0也写入，将来在Load时还带有0结尾。
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
		puts("写入失败！");
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
	printf("共计%d条元素。\n\n", i);
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
	printf("请输入新数据(输入#退出)：\n");
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
{//删除时写入-1，这里将-1元素摘除，并不在队列中存在，避免麻烦
	int arrCount = 0;
	while (arr[arrCount++]);//一直取到非0元素，得到总数arrCount(最后++，又把0元素加上了，所以是原数组长度）
	int *NewArr = NULL;
	NewArr = (int*)calloc(arrCount - 1, sizeof(int));//新建数组，比原数组少1，去掉要删除的元素，并保持队形
	int i = 0, j = 0;
	while (arr[i])
	{
		if (i == ToBeDelete)
			++i;//遇到要删除的元素，+1跳过
		NewArr[j++] = arr[i++];
	}
	arr = NewArr;
}

void Delete()
{
	int nNumb = 0;
	puts("请输入要删除的元素：");
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
		puts("删除成功！");
		Save();
	}
	else
		puts("没找到要删除的数据。。。");

	system("pause");
}

void Modify()
{
	int nNumb = 0;
	puts("请输入要查找的元素：");
	fflush(stdin);
	scanf_s("%d", &nNumb);

	int i = 0;
	int flag = 0;
	while (arr[i])
	{
		if (nNumb == i)
		{
			puts("找到以下：");
			printf("arr[%d] = %d\n", i, arr[i]);
			puts("请输入新的数字：");
			fflush(stdin);
			scanf_s("%d", &arr[i]);
			flag = 1;
			Browse();
			return;
		}
		++i;
	}
	if (flag != 1)
		puts("没找到要查找的元素。。。");

	system("pause");
}

void Search()
{
	int nNumb = 0;
	puts("请输入要查找的元素：");
	fflush(stdin);
	scanf_s("%d", &nNumb);

	int i = 0;
	int flag = 0;
	while (arr[i])
	{
		if (nNumb == i)
		{
			puts("找到以下：");
			printf("arr[%d] = %d\n", i, arr[i]);
			flag = 1;
			break;
		}
		++i;
	}
	if (flag != 1)
		puts("没找到要查找的元素。。。");

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
	printf("请选择：");
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
		puts("退出。。。");
		break;
	default:
		puts("输入无效！");
	}
	return c;
}
int main()
{
	int *p = NULL;
	p = (int*)malloc(sizeof(int));
	memset(p, 0, sizeof(int));
	
	
	//先定义1个空元素，以后每加一个元素之前，先增加一个元素的长度
	//保证数组最后总有一个空位，也是方便找到结尾，控制循环。
	arr = (int*)calloc(1, sizeof(int));


	FILE* pf = NULL;
	fopen_s(&pf, "arr.orlando", "a");
	if (!pf)
	{
		puts("文件初始化失败！");
		return;
	}
	fclose(pf);

	Load();

	while (Menu() != '0');

	system("pause");
	return 0;
}