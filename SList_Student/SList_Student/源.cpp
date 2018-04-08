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
	{//���û������
		puts("û�����ݡ���");
		return;
	}
	int Count = 0;
	while (p)
	{//���������
		if (!Count)
		{
			Puts_Title();
		}
		Printf_Message(p);
		++Count;
		p = p->pNext;
	}
	printf("\n\t����%d��ѧ����Ϣ����\n\n", Count);
}


void Add(int n)
{
	DATA stu;
	while (1)
	{
		puts("������Ҫ�½���ѧ��ѧ�ţ���0�˳�����");
		scanf_s("%d", &stu.nNum);
		if (0 == stu.nNum)
		{//����0 �˳�
			puts("ȡ�����벢�˳�����");
			system("pause");
			return;
		}
		SNode* p = FindNumber(stu.nNum);
		if (p)
		{//����Ƿ�����ظ�
			Puts_Title();
			Printf_Message(p);
			printf("���ϣ��������ѧ���Ѿ����ڣ�����������\n");
			continue;
		}
		puts("����������������ݣ�");
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
	puts("\t***********������Ϣ�˵�***********\n\n");
	puts("\t\t1����ͷ�������Ϣ\n");
	puts("\t\t2����β�������Ϣ\n");
	puts("\t\t0���������˵�\n");
	puts("\n\t**********************************");
	printf("��ѡ��");
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
		puts("�������˵�����");
		break;
	default:
		puts("������Ч�����������롭��");
	}
	return c;
}


void Delete()
{
	DATA stu;
	while (1)
	{
		puts("������Ҫɾ����ѧ��ѧ�ţ���0�˳�����");
		scanf_s("%d", &stu.nNum);
		if (0 == stu.nNum)
		{//����0 �˳�
			puts("ȡ��ɾ�����˳�����");
			system("pause");
			return;
		}
		SNode* p = FindNumber(stu.nNum);
		if (!p)
		{//����Ƿ�����ظ�
			printf("�������ѧ�Ų������ڣ�����������\n");
			continue;
		}
		char c = 0;
		while (1)
		{//ɾ��ȷ�ϻ���
			Puts_Title();
			Printf_Message(p);
			printf("\nȷ��ɾ��������Ϣ��?[Y/n]:");
			scanf_s("\n%c", &c, sizeof(c));
			/*fflush(stdin);
			c = getchar();*/

			if (tolower(c) == 'n')//n�˳�ѭ��
			{
				puts("\tȡ�����Ҳ���ɾ����...");
				break;
			}
			else if (tolower(c) == 'y')//y��������ִ��
			{
				DeleteNode(p);
				Save();
				puts("\tSuccessful removed!");
				system("pause");
				system("cls");
				Browse();
				break;
			}
			else//�����Ƿ����룬����ѭ��
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
		puts("������Ҫ���ĵ�ѧ��ѧ�ţ���0�˳�����");
		scanf_s("%d", &stu.nNum);
		if (0 == stu.nNum)
		{//����0 �˳�
			puts("ȡ�����Ĳ��˳�����");
			system("pause");
			return;
		}
		SNode* p = FindNumber(stu.nNum);
		if (!p)
		{//����Ƿ�����ظ�
			printf("�������ѧ�Ų������ڣ�����������\n");
			continue;
		}
		char c = 0;
		while (1)
		{//����ȷ�ϻ���
			Puts_Title();
			Printf_Message(p);
			printf("\nȷ�����Ĵ�����Ϣ��?[Y/n]:");
			scanf_s("\n%c", &c, sizeof(c));
			/*fflush(stdin);
			c = getchar();*/

			if (tolower(c) == 'n')//n�˳�ѭ��
			{
				puts("\tȡ�����Ҳ��������...");
				break;
			}
			else if (tolower(c) == 'y')//y��������ִ��
			{
				puts("�����������ݣ�");
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
			else//�����Ƿ����룬����ѭ��
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
		printf("\n������Ҫ������ѧ��ѧ�ţ���0�˳�����");
		scanf_s("%d", &stu.nNum);
		if (0 == stu.nNum)
		{//����0 �˳�
			puts("ȡ���������˳�����");
			system("pause");
			break;
		}
		SNode* p = FindNumber(stu.nNum);
		if (!p)
		{//����Ƿ�����ظ�
			printf("�������ѧ�Ų������ڣ�����������\n");
			continue;
		}
		//��ʾ���ҽ��
		puts("������Ϣ���£�");
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
		printf("\n������Ҫ������ѧ����������0�˳�����");
		scanf_s("%s", &stu.sName, sizeof(stu.sName));
		if (stu.sName[0] == '0')
		{//����0 �˳�
			puts("ȡ���������˳�����");
			system("pause");
			break;
		}
		SNode* p = FindName(stu.sName);
		if (!p)
		{//����Ƿ�����ظ�
			printf("������������������ڣ�����������\n");
			continue;
		}
		//��ʾ���ҽ��
		puts("������Ϣ���£�");
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
		printf("\n������Ҫ�����ķ����Σ���0�˳�����");
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
				if (!total)//�����ݲ���Ҫ��ӡ
				{//���ν���ѭ����ӡ��ͷ
					if (Course == '3')
						printf("���ĳɼ��� %.1f to %.1f֮���ѧ����Ϣ����:\n", min, max);
					else if (Course == '4')
						printf("��ѧ�ɼ��� %.1f to %.1f֮���ѧ����Ϣ����:\n", min, max);
					else if (Course == '5')
						printf("Ӣ��ɼ��� %.1f to %.1f֮���ѧ����Ϣ����:\n", min, max);
					Puts_Title();
				}
				Printf_Message(p);
				++total;
			}
			p = p->pNext;
		}

		if (!total)
			puts("�ÿƳɼ��Ĵ˷����β��޽��!");
		else
			printf("��%d�˵ĳɼ��ڴ����䷶Χ�ڡ�", total);
		system("pause");
		return;
	}
}
char Menu_Search()
{
	system("cls");
	puts("\n\t************* ���Ҳ˵� *************\n");
	puts("\t\t1.  ͨ��ѧ�Ų���");
	puts("\t\t2.  ͨ����������");
	puts("\t\t3.  ͨ�����ķ����β���");
	puts("\t\t4.  ͨ����ѧ�����β���");
	puts("\t\t5.  ͨ��Ӣ������β���");
	puts("\t\t0.  �������˵�");
	puts("\n\t**********************************************");

	printf("\n\t��ѡ��");

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
		puts("�������˵�����\n\n");
		break;

	default:
		puts("\n������Ч�����������롭��\n");
		system("pause");
	}

	return c;
}


void Sort(char SortBy)
{//ѡ������
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
	puts("\t*************����˵�*************\n\n");
	puts("\t\t1����ѧ������\n");
	puts("\t\t2������������\n");
	puts("\t\t3�������ĳɼ�����\n");
	puts("\t\t4������ѧ�ɼ�����\n");
	puts("\t\t5����Ӣ��ɼ�����\n");
	puts("\t\t0���˳�����\n");
	puts("\n\n\t********************************");
	printf("��ѡ��");
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
		puts("�˳����򡭡�");
		break;
	default:
		puts("������Ч�����������롭��");
	}
	return c;
}


char Menu_Main()
{
	system("cls");
	puts("\t*************���˵�*************\n\n");
	puts("\t\t1�����������Ϣ\n");
	puts("\t\t2������ѧ����Ϣ\n");
	puts("\t\t3��ɾ��ѧ����Ϣ\n");
	puts("\t\t4���޸�ѧ����Ϣ\n");
	puts("\t\t5�����Ҳ˵�\n");
	puts("\t\t6������˵�\n");
	puts("\t\t0���˳�����\n");
	puts("\n\n\t********************************");
	printf("��ѡ��");
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
		puts("�˳����򡭡�");
		break;
	default:
		puts("������Ч�����������롭��");
	}
	return c;
}

int main()
{
	FILE* pf = nullptr;
	fopen_s(&pf, ".\\student.orlando", "ab");
	if (!pf)
	{
		puts("�ļ���ʼ��ʧ�ܣ�");
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