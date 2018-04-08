#include"Student.h"

DATA nNewdata;

int CheckDuplicate(int nNumb)//duplicate 二重的
{
	int nIndex = 0;
	while (nIndex < GetCount())
	{
		if (nNumb == GetHead()[nIndex].nNumb)
			return 1;	//1 为有重复的情况
		++nIndex;
	}
	return 0;			//0 没有重复
}

void Add()
{
	int nNumb = 0;
	puts("Input the Number(0 to exit):\n");
	scanf_s("%d", &nNumb);
	//char c  = _getche();//想用无回显
	//nNumb = atoi(&c);//输入字符‘0’就转换成数字0
	if (nNumb == 0)
		return;
	else if (CheckDuplicate(nNumb) == 1)
	{
		puts("\nThis number is exist already!\n");
		system("pause");
		return;
	}
	nNewdata.nNumb = nNumb;
	printf("Num\tName\tChin\tMath\tEngl\n%d\t",nNewdata.nNumb);
	scanf_s("%s%f%f%f",
		nNewdata.sName, sizeof(nNewdata.sName),
		&nNewdata.fChin, &nNewdata.fMath, &nNewdata.fEngl);
	AddData(nNewdata);
	Save();
	system("cls");
	Print();
	system("pause");
}

void Insert()
{
	int nIndex = 0, nNumb = 0, flag = 0;
	puts("Input the index number (0 to exit):");
	scanf_s("%d", &nNumb);	
	if (nNumb == 0)
		return;

	while (nIndex < GetCount())
	{//通过输入要删除的学号，找到索引nIndex
		if (nNumb == GetAt(nIndex)->nNumb)
		{
			flag = 1;
			break;
		}
		++nIndex;
	}
	if (!flag)
	{
		puts("Invalid input!\n");
		system("pause");
		return;
	}

	puts("Input the new message :");
	puts("Num\tName\tChin\tMath\tEngl\n");
	scanf_s("%d%s%f%f%f",
		&nNewdata.nNumb, nNewdata.sName, sizeof(nNewdata.sName),
		&nNewdata.fChin, &nNewdata.fMath, &nNewdata.fEngl);

	InsertAt(nIndex, nNewdata);
	Save();
	system("cls");
	Print();
	system("pause");
}

//通过输入的信息找到与之对应的索引
int Get_Index(const void* data)
{
	int nIndex = 0;
	int nNumb = *(int*)data;

	while (nIndex < GetCount())
	{//输入学号后，搜索与之相对应的索引
		if (nNumb == GetAt(nIndex)->nNumb)
			return nIndex;
		++nIndex;
	}
	//没找到
	puts("Invalid input!");
	system("pause");
	return -1;
}

void Remove()
{
	int nIndex = 0, nNumb = 0;
	puts("Please input the student number to delete(0 to exit):");

	scanf_s("%d", &nNumb);
	if (nNumb == 0)
		return;
	if ((nIndex = Get_Index(&nNumb)) == -1)
		return;

	printf("%d\t%s\t%.1f\t%.1f\t%.1f\n",
		GetAt(nIndex)->nNumb, GetAt(nIndex)->sName,
		GetAt(nIndex)->fChin, GetAt(nIndex)->fMath, GetAt(nIndex)->fEngl);

	char c = 0;
	while (1)
	{//删除确认环节
		printf("\nAre you sure to remove?[Y/n]:");
		c = _getche();

		if (tolower(c) == 'n')//n退出循环
		{
			puts("\tRemove canceled...");
			break;
		}
		else if (tolower(c) == 'y')//y继续向下执行
		{
			RemoveAt(nIndex);
			puts("\tSuccessful removed!");
			Save();
			system("pause");
			system("cls");
			Print();
			break;
		}
		else//其它非法输入，继续循环
			continue;
	}
	system("pause");
	return;
}

void GetData()
{
	int nIndex = 0;
	int nNumb = 0;

	puts("Please input the student number to read(0 to exit):");
	scanf_s("%d", &nNumb);

	if (0 == nNumb)
		return;

	if (-1 == (nIndex = Get_Index(&nNumb)))
		return;

	DATA* pt = GetAt(nIndex);
	printf("%d\t%s\t%.1f\t%.1f\t%.1f\n", pt->nNumb, pt->sName, pt->fChin, pt->fMath, pt->fEngl);
	system("pause");
}

void SetData()
{
	int nIndex = 0;
	int nNumb = 0;
	puts("Please input the student number to modify(0 to exit):");
	scanf_s("%d", &nNumb);
	if (0 == nNumb)
		return;
	if (-1 == (nIndex = Get_Index(&nNumb)))
		return;

	puts("Now is:");
	printf("%d\t%s\t%.1f\t%.1f\t%.1f\n",
		GetAt(nIndex)->nNumb, GetAt(nIndex)->sName,
		GetAt(nIndex)->fChin, GetAt(nIndex)->fMath, GetAt(nIndex)->fEngl);
	puts("Input new data:");
	DATA t;
	scanf_s("%d%s%f%f%f", &t.nNumb, t.sName, sizeof(t.sName), &t.fChin, &t.fMath, &t.fEngl);


	SetAt(nIndex, t);

	Save();
	system("cls");
	Print();
	system("pause");
}

int  FindByNumb()
{
	int nNumb = 0;
	puts("\nInput the number you want to find:");
	scanf_s("%d", &nNumb);

	DATA* p = FindNumb(nNumb);
	if (!p)
	{
		puts("Invalid input!");
		return 0;
	}
	puts("Result as below:");
	puts("\n\tNum\tName\tChin\tMath\tEngl\n");
	printf("\t%d\t%s\t%.1f\t%.1f\t%.1f\n\n", p->nNumb, p->sName, p->fChin, p->fMath, p->fEngl);

	system("pause");
	return 1;
}

int FindByName()
{
	char sName[20] = { 0 };
	puts("\nInput the name you want to find:");
	scanf_s("%s", &sName, sizeof(sName));

	DATA* p = FindName(sName);
	if (!p)
	{
		puts("Invalid input!");
		return 0;
	}
	puts("Result as below:");
	puts("\n\tNum\tName\tChin\tMath\tEngl\n");
	printf("\t%d\t%s\t%.1f\t%.1f\t%.1f\n\n", p->nNumb, p->sName, p->fChin, p->fMath, p->fEngl);

	system("pause");
	return 1;
}

void FindByScoreSection(char Course)//Course 课程
{
	float max = 0., min = 0.;
	puts("\nInput the section you want to search in:");
	scanf_s("%f%f", &max, &min);

	GetRank(&max, &min);

	int nIndex = 0, total = 0;
	while (nIndex < GetCount())
	{
		if (Course == '3' && GetAt(nIndex)->fChin >= min && GetAt(nIndex)->fChin <= max ||
			Course == '4' && GetAt(nIndex)->fMath >= min && GetAt(nIndex)->fMath <= max ||
			Course == '5' && GetAt(nIndex)->fEngl >= min && GetAt(nIndex)->fEngl <= max)
		{
			if (!total)//有数据才需要打印
			{//初次进入循环打印表头
				if (Course == '3')
					printf("Score between %.1f to %.1f in Chinese as below:\n", min, max);
				else if (Course == '4')
					printf("Score between %.1f to %.1f in Math as below:\n", min, max);
				else if (Course == '5')
					printf("Score between %.1f to %.1f in English as below:\n", min, max);
				puts("\n\tNum\tName\tChin\tMath\tEngl\n");
			}

			printf("\t%d\t%s\t%.1f\t%.1f\t%.1f\n\n",
				GetAt(nIndex)->nNumb, GetAt(nIndex)->sName,
				GetAt(nIndex)->fChin, GetAt(nIndex)->fMath, GetAt(nIndex)->fEngl);

			++total;
		}
		++nIndex;
	}

	if (!total)
		puts("No one in this score section!");
	system("pause");
	return;
}

char FindMenu()
{
	system("cls");
	puts("\n\t************* F i n d    M e n u *************\n");
	puts("\t\t1.  Find by number");
	puts("\t\t2.  Find by name");
	puts("\t\t3.  Find by Chinese score section");
	puts("\t\t4.  Find by Math score section");
	puts("\t\t5.  Find by English score section");
	puts("\t\t0.  Exit");
	puts("\n\t**********************************************");

	printf("\n\tPlease enter 0-5:");

	char c = 0;
	c = _getche();
	switch (c)
	{
	case '1':
		while (!FindByNumb());
		break;
	case '2':
		while (!FindByName());
		break;
	case '3':
	case '4':
	case '5':
		FindByScoreSection(c);
		break;

	case '0':
		puts("Back to main menu...\n\n");
		break;

	default:
		puts("\nInvalid enter,choose again.\n");
		system("pause");
	}

	return c;
}

int SortByNumb(const void *a, const void *b)
{
	return ((DATA*)a)->nNumb - ((DATA*)b)->nNumb;
}

int SortByName(const void *a, const void *b)
{
	if (strcmp(((DATA*)a)->sName, ((DATA*)b)->sName) == 0)
		return ((DATA*)a)->nNumb - ((DATA*)b)->nNumb;
	return strcmp(((DATA*)a)->sName, ((DATA*)b)->sName);
}

int SortByChinese(const void *a, const void *b)
{
	if (((DATA*)a)->fChin == ((DATA*)b)->fChin)
		return ((DATA*)a)->nNumb - ((DATA*)b)->nNumb;
	return (int)(((DATA*)b)->fChin - ((DATA*)a)->fChin);
}

int SortByMath(const void *a, const void *b)
{
	if (((DATA*)a)->fMath == ((DATA*)b)->fMath)
		return ((DATA*)a)->nNumb - ((DATA*)b)->nNumb;
	return (int)(((DATA*)b)->fMath - ((DATA*)a)->fMath);
}

int SortByEnglish(const void *a, const void *b)
{
	if (((DATA*)a)->fEngl == ((DATA*)b)->fEngl)
		return ((DATA*)a)->nNumb - ((DATA*)b)->nNumb;
	return (int)(((DATA*)b)->fEngl - ((DATA*)a)->fEngl);
}

void Sort(char SortBy)
{//选择排序
	system("cls");
	if ('1' == SortBy)
	{
		puts("Sort By Numb:");
		//Insertion_Sort(GetHead(), GetCount(), sizeof(DATA), SortByNumb);
		Selection_sort(GetHead(), GetCount(), sizeof(DATA), SortByNumb);
	}
	if ('2' == SortBy)
	{
		puts("Sort By Name:");
		//Insertion_Sort(GetHead(), GetCount(), sizeof(DATA), SortByName);
		Selection_sort(GetHead(), GetCount(), sizeof(DATA), SortByName);
	}
	if ('3' == SortBy)
	{
		puts("Sort By Chinese:");
		//Insertion_Sort(GetHead(), GetCount(), sizeof(DATA), SortByChinese);
		Selection_sort(GetHead(), GetCount(), sizeof(DATA), SortByChinese);
	}
	if ('4' == SortBy)
	{
		puts("Sort By Math:");
		//Insertion_Sort(GetHead(), GetCount(), sizeof(DATA), SortByMath);
		Selection_sort(GetHead(), GetCount(), sizeof(DATA), SortByMath);
	}
	if ('5' == SortBy)
	{
		puts("Sort By English:");
		//Insertion_Sort(GetHead(), GetCount(), sizeof(DATA), SortByEnglish);
		Selection_sort(GetHead(), GetCount(), sizeof(DATA), SortByEnglish);
	}
	Save();
	Print();
	system("pause");
}

char SortMenu()
{
	system("cls");
	puts("\n\t************* S o r t    M e n u *************\n");
	puts("\t\t1.  Sort by number");
	puts("\t\t2.  Sort by name");
	puts("\t\t3.  Sort by Chinese record");
	puts("\t\t4.  Sort by Math record");
	puts("\t\t5.  Sort by English record");
	puts("\t\t0.  Exit");
	puts("\n\t**********************************************");

	printf("\n\tPlease enter 0-5:");

	char c = 0;
	c = _getche();
	switch (c)
	{
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
		Sort(c);
		break;
	case '0':
		puts("Back to main menu...\n\n");
		break;
	default:
		puts("\nInvalid enter,choose again.\n");
		system("pause");
	}
	return c;
}

char Menu()
{
	system("cls");
	puts("\n\t************* M a i n    M e n u *************\n");
	puts("\t\t\t1.  Print");
	puts("\t\t\t2.  Add");
	puts("\t\t\t3.  Insert");
	puts("\t\t\t4.  RemoveAt");
	puts("\t\t\t5.  SetAt");
	puts("\t\t\t6.  GetAt");
	puts("\t\t\t7.  FindMenu");
	puts("\t\t\t8.  Sort");
	puts("\t\t\t0.  Exit");
	puts("\n\t**********************************************");
	printf("\n\tPlease enter 0-6:");

	char c = 0;
	c = _getche();
	puts("\n");
	switch (c)
	{
	case '1':
		system("cls");
		Print();
		system("pause");
		break;
	case '2':
		Add();
		break;
	case '3':
		Insert();
		break;
	case '4':
		Remove();
		break;
	case '5':
		SetData();
		break;
	case '6':
		GetData();
		break;
	case '7':
		while (FindMenu() != '0');
		break;
	case '8':
		while (SortMenu() != '0');
		break;
	case '0':
		puts("Exit...\n\n");
		break;
	default:
		puts("\nInvalid enter,choose again.\n");
		system("pause");
	}
	return c;
}

int main()
{
	char ch[100] ="sda";
	gets_s(ch);
	puts(ch);
	
	Initialize();


	FILE* pf = NULL;
	fopen_s(&pf, ".\\student.orlando", "ab");
	if (!pf)
	{
		puts("Initialize failed！");
		system("pause");
		return -1;
	}
	fclose(pf);

	Load();

	while (Menu() != '0')
		;
	system("pause");
	return 0;
}