#include"Student.h"
void Puts_Title()
{
	puts("\n\tNumb\tName\tChin\tMath\tEngl");
}
void Printf_Message(SNode* p)
{
	printf("\t%d\t%s\t%.1f\t%.1f\t%.1f\n",
		p->data.nNum, p->data.sName,
		p->data.Chin, p->data.Math, p->data.Engl);
}


void Browse()
{
	SNode* p = GetHead();
	if (!p)
	{//如果没有数据
		puts("没有数据……");
		return;
	}
	int Count = 0;
	while (p)
	{//如果有数据
		if (!Count)
		{
			Puts_Title();
		}
		Printf_Message(p);
		++Count;
		p = p->pNext;
	}
	printf("\n\t共计%d条学生信息……\n\n", Count);
}


void Add(int n)
{
	DATA stu;
	while (1)
	{
		puts("请输入要新建的学生学号（按0退出）：");
		scanf_s("%d", &stu.nNum);
		if (0 == stu.nNum)
		{//输入0 退出
			puts("取消输入并退出……");
			system("pause");
			return;
		}
		SNode* p = FindNumber(stu.nNum);
		if (p)
		{//检测是否存在重复
			Puts_Title();
			Printf_Message(p);
			printf("如上，您输入的学号已经存在，请重新输入\n");
			continue;
		}
		puts("请继续输入余下内容：");
		Puts_Title();
		printf("\t%d\t", stu.nNum);
		scanf_s("%s%f%f%f", stu.sName, sizeof(stu.sName),
			&stu.Chin, &stu.Math, &stu.Engl);
		if (n == 1)
			AddHead(stu);
		else
			AddTail(stu);
		Save();
		system("cls");
		Browse();
		system("pause");
		break;
	}
}
char Menu_Add()
{
	system("cls");
	puts("\t***********增加信息菜单***********\n\n");
	puts("\t\t1、从头部添加信息\n");
	puts("\t\t2、从尾部添加信息\n");
	puts("\t\t0、返回主菜单\n");
	puts("\n\t**********************************");
	printf("请选择：");
	char c = 0;
	c = _getch();
	puts("");
	switch (c)
	{
	case '1':
		Add(1);
		break;
	case '2':
		Add(2);
		break;
	case '0':
		puts("返回主菜单……");
		break;
	default:
		puts("输入无效，请重新输入……");
	}
	return c;
}


void Delete()
{
	DATA stu;
	while (1)
	{
		puts("请输入要删除的学生学号（按0退出）：");
		scanf_s("%d", &stu.nNum);
		if (0 == stu.nNum)
		{//输入0 退出
			puts("取消删除并退出……");
			system("pause");
			return;
		}
		SNode* p = FindNumber(stu.nNum);
		if (!p)
		{//检测是否存在重复
			printf("您输入的学号并不存在，请重新输入\n");
			continue;
		}
		char c = 0;
		while (1)
		{//删除确认环节
			Puts_Title();
			Printf_Message(p);
			printf("\n确定删除此条信息吗?[Y/n]:");
			scanf_s("\n%c", &c, sizeof(c));
			/*fflush(stdin);
			c = getchar();*/

			if (tolower(c) == 'n')//n退出循环
			{
				puts("\t取消，我不想删除了...");
				break;
			}
			else if (tolower(c) == 'y')//y继续向下执行
			{
				DeleteNode(p);
				Save();
				puts("\tSuccessful removed!");
				system("pause");
				system("cls");
				Browse();
				break;
			}
			else//其它非法输入，继续循环
				continue;
		}
		system("pause");
		break;
	}
}


void Modify()
{
	DATA stu;
	while (1)
	{
		puts("请输入要更改的学生学号（按0退出）：");
		scanf_s("%d", &stu.nNum);
		if (0 == stu.nNum)
		{//输入0 退出
			puts("取消更改并退出……");
			system("pause");
			return;
		}
		SNode* p = FindNumber(stu.nNum);
		if (!p)
		{//检测是否存在重复
			printf("您输入的学号并不存在，请重新输入\n");
			continue;
		}
		char c = 0;
		while (1)
		{//更改确认环节
			Puts_Title();
			Printf_Message(p);
			printf("\n确定更改此条信息吗?[Y/n]:");
			scanf_s("\n%c", &c, sizeof(c));
			/*fflush(stdin);
			c = getchar();*/

			if (tolower(c) == 'n')//n退出循环
			{
				puts("\t取消，我不想更改了...");
				break;
			}
			else if (tolower(c) == 'y')//y继续向下执行
			{
				puts("请输入新内容：");
				Puts_Title();
				printf("\t");
				scanf_s("%d%s%f%f%f", &p->data.nNum,
					p->data.sName, sizeof(p->data.sName),
					&p->data.Chin, &p->data.Math, &p->data.Engl);
				Save();
				puts("\tSuccessful modified!");
				system("pause");
				system("cls");
				Browse();
				break;
			}
			else//其它非法输入，继续循环
				continue;
		}
		system("pause");
		break;
	}
}


void SearchByNumb()
{
	DATA stu;
	while (1)
	{
		printf("\n请输入要搜索的学生学号（按0退出）：");
		scanf_s("%d", &stu.nNum);
		if (0 == stu.nNum)
		{//输入0 退出
			puts("取消搜索并退出……");
			system("pause");
			break;
		}
		SNode* p = FindNumber(stu.nNum);
		if (!p)
		{//检测是否存在重复
			printf("您输入的学号并不存在，请重新输入\n");
			continue;
		}
		//显示查找结果
		puts("查找信息如下：");
		Puts_Title();
		Printf_Message(p);
		system("pause");
		break;
	}
}
void SearchByName()
{
	DATA stu;
	while (1)
	{
		printf("\n请输入要搜索的学生姓名（按0退出）：");
		scanf_s("%s", &stu.sName, sizeof(stu.sName));
		if (stu.sName[0] == '0')
		{//输入0 退出
			puts("取消搜索并退出……");
			system("pause");
			break;
		}
		SNode* p = FindName(stu.sName);
		if (!p)
		{//检测是否存在重复
			printf("您输入的姓名并不存在，请重新输入\n");
			continue;
		}
		//显示查找结果
		puts("查找信息如下：");
		Puts_Title();
		Printf_Message(p);
		system("pause");
		break;
	}
}
void SearchByScoreSection(char Course)
{
	while (1)
	{
		float max = 0., min = 0.;
		printf("\n请输入要搜索的分数段（按0退出）：");
		scanf_s("%f%f", &max, &min);
		GetRank(&max, &min);

		SNode*p = GetHead();
		int total = 0;
		while (p)
		{
			if (Course == '3' && p->data.Chin >= min &&  p->data.Chin <= max ||
				Course == '4' &&  p->data.Math >= min &&p->data.Math <= max ||
				Course == '5' && p->data.Engl >= min && p->data.Engl <= max)
			{
				if (!total)//有数据才需要打印
				{//初次进入循环打印表头
					if (Course == '3')
						printf("语文成绩在 %.1f to %.1f之间的学生信息如下:\n", min, max);
					else if (Course == '4')
						printf("数学成绩在 %.1f to %.1f之间的学生信息如下:\n", min, max);
					else if (Course == '5')
						printf("英语成绩在 %.1f to %.1f之间的学生信息如下:\n", min, max);
					Puts_Title();
				}
				Printf_Message(p);
				++total;
			}
			p = p->pNext;
		}

		if (!total)
			puts("该科成绩的此分数段查无结果!");
		else
			printf("共%d人的成绩在此区间范围内。", total);
		system("pause");
		return;
	}
}
char Menu_Search()
{
	system("cls");
	puts("\n\t************* 查找菜单 *************\n");
	puts("\t\t1.  通过学号查找");
	puts("\t\t2.  通过姓名查找");
	puts("\t\t3.  通过语文分数段查找");
	puts("\t\t4.  通过数学分数段查找");
	puts("\t\t5.  通过英语分数段查找");
	puts("\t\t0.  返回主菜单");
	puts("\n\t**********************************************");

	printf("\n\t请选择：");

	char c = 0;
	c = _getche();
	switch (c)
	{
	case '1':
		SearchByNumb();
		break;
	case '2':
		SearchByName();
		break;
	case '3':
	case '4':
	case '5':
		SearchByScoreSection(c);
		break;

	case '0':
		puts("返回主菜单……\n\n");
		break;

	default:
		puts("\n输入无效，请重新输入……\n");
		system("pause");
	}

	return c;
}


void Sort(char SortBy)
{//选择排序
	system("cls");
	if ('1' == SortBy)
	{
		puts("Sort By Numb:");
		//Insertion_Sort(GetHead(),  sizeof(DATA), SortByNumb);
		Selection_sort(GetHead(),  sizeof(DATA), SortByNumb);
	}
	if ('2' == SortBy)
	{
		puts("Sort By Name:");
		//Insertion_Sort(GetHead(),  sizeof(DATA), SortByName);
		Selection_sort(GetHead(), sizeof(DATA), SortByName);
	}
	if ('3' == SortBy)
	{
		puts("Sort By Chinese:");
		//Insertion_Sort(GetHead(), sizeof(DATA), SortByChinese);
		Selection_sort(GetHead(),  sizeof(DATA), SortByChinese);
	}
	if ('4' == SortBy)
	{
		puts("Sort By Math:");
		//Insertion_Sort(GetHead(), sizeof(DATA), SortByMath);
		Selection_sort(GetHead(),  sizeof(DATA), SortByMath);
	}
	if ('5' == SortBy)
	{
		puts("Sort By English:");
		//Insertion_Sort(GetHead(),sizeof(DATA), SortByEnglish);
		Selection_sort(GetHead(),  sizeof(DATA), SortByEnglish);
	}
	Save();
	Browse();
	system("pause");

}
char Menu_Sort()
{
	system("cls");
	puts("\t*************排序菜单*************\n\n");
	puts("\t\t1、按学号排序\n");
	puts("\t\t2、按姓名排序\n");
	puts("\t\t3、按语文成绩排序\n");
	puts("\t\t4、按数学成绩排序\n");
	puts("\t\t5、按英语成绩排序\n");
	puts("\t\t0、退出程序\n");
	puts("\n\n\t********************************");
	printf("请选择：");
	char c = 0;
	c = _getch();
	puts("");
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
		puts("退出程序……");
		break;
	default:
		puts("输入无效，请重新输入……");
	}
	return c;
}


char Menu_Main()
{
	system("cls");
	puts("\t*************主菜单*************\n\n");
	puts("\t\t1、浏览所有信息\n");
	puts("\t\t2、新增学生信息\n");
	puts("\t\t3、删除学生信息\n");
	puts("\t\t4、修改学生信息\n");
	puts("\t\t5、查找菜单\n");
	puts("\t\t6、排序菜单\n");
	puts("\t\t0、退出程序\n");
	puts("\n\n\t********************************");
	printf("请选择：");
	char c = 0;
	c = _getch();
	puts("");
	switch (c)
	{
	case '1':
		system("cls");
		Browse();
		system("pause");
		break;
	case '2':
		while (Menu_Add() != '0');
		break;
	case '3':
		Delete();
		break;
	case '4':
		Modify();
		break;
	case '5':
		while (Menu_Search() != '0');
		break;
	case '6':
		while (Menu_Sort() != '0');
		break;
	case '0':
		puts("退出程序……");
		break;
	default:
		puts("输入无效，请重新输入……");
	}
	return c;
}

int main()
{
	FILE* pf = nullptr;
	fopen_s(&pf, ".\\student.orlando", "ab");
	if (!pf)
	{
		puts("文件初始化失败！");
		system("pause");
		exit(0);
	}
	fclose(pf);

	Load();

	while (Menu_Main() != '0');


	system("pause");
	RemoveAll();
	return 0;
}