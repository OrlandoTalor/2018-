#include"Student.h"

DATA* g_pHead;//�׵�ַ
int g_nCount = 0;//������Ŀ
int g_nSize = 2;//��Դ��Ŀ 

int GetCount()
{
	return g_nCount;
}

void Load()
{
	FILE* pf = NULL;
	fopen_s(&pf, ".\\Student.Orlando", "rb");
	if (!pf)
	{
		puts("Load error!");
		system("pause");
		exit(0);
	}
	DATA data;

	while (sizeof(data) == fread(&data, 1, sizeof(data), pf))
		AddData(data);

	fclose(pf);
}

void Save()
{
	FILE* pf = NULL;
	fopen_s(&pf, ".\\Student.Orlando", "wb");
	if (!pf)
	{
		puts("Save error!");
		system("pause");
		exit(0);
	}
	int nIndex = 0;
	while (g_pHead[nIndex].nNumb && nIndex < g_nCount)
	{
		fwrite(&g_pHead[nIndex], 1, sizeof(g_pHead[nIndex]), pf);
		++nIndex;
	}
	fclose(pf);
}

void Initialize()
{
	g_pHead = (DATA*)malloc(sizeof(DATA)*g_nSize);
	memset(g_pHead, 0, sizeof(DATA)*g_nSize);//�ѿռ��ʼ��Ϊ0
}

void Print()
{

	int nIndex = 0;
	if (g_pHead[0].nNumb == 0)
	{
		puts("No Data!");
		return;
	}
	puts("\n\tNum\tName\tChin\tMath\tEngl");
	while (nIndex < g_nCount)
	{
		printf("\n\t%d\t%s\t%.1f\t%.1f\t%.1f\n",
			g_pHead[nIndex].nNumb, g_pHead[nIndex].sName,
			g_pHead[nIndex].fChin, g_pHead[nIndex].fMath, g_pHead[nIndex].fEngl);
		++nIndex;
	}
	printf("\n\tThe size of the heap-space we created is %d bytes\n\n", g_nSize);;;;;;;;;
}

void Realloc()
{
	DATA* pNew = NULL;
	int NewSize = g_nSize * 2;
	pNew = (DATA*)malloc(sizeof(DATA)*NewSize);
	memset(pNew, 0, sizeof(DATA)*NewSize);//�ѿռ��ʼ��Ϊ0
	memcpy(pNew, g_pHead, sizeof(DATA)*g_nSize);
	g_nSize = NewSize;//�����µ�sizeֵ
	free(g_pHead);//�ͷžɵĶѿռ�
	g_pHead = pNew;//�µĶѿռ��ַ��ֵ��ԭ����ͷָ��
	pNew = NULL;//�����µ�ָ��
}

void AddData(DATA New_Data)
{
	if (g_nCount >= g_nSize)
		Realloc();
	g_pHead[g_nCount++] = New_Data;
}
//�������������������ͺ������Ϣ����1����λ����������Ϣ
void InsertAt(int nIndex, DATA New_Data)
{
	if (g_nCount >= g_nSize)
		Realloc();
	DATA* p = &g_pHead[nIndex];//��pָ��Ҫ�������ݵ�λ��

	memcpy(p + 1, p, sizeof(DATA)*(g_nCount - nIndex));
	//�Ӹ�λ���Ժ�����ݣ���������ƶ�1��DATA�ĳ���
	g_pHead[nIndex] = New_Data;//����Ӧλ��д��������
	++g_nCount;
}

int RemoveAt(int nIndex)
{
	DATA* pFlag = &g_pHead[nIndex];
	memcpy(pFlag, pFlag + 1, sizeof(DATA)*(g_nCount - nIndex));
	--g_nCount;
	return 1;
}

DATA* GetHead()
{
	return g_pHead;
}

DATA* GetAt(int nIndex)//����ֵ����ΪDATA
{
	return &g_pHead[nIndex];
}

void SetAt(int nIndex, DATA NewData)
{
	g_pHead[nIndex] = NewData;
}
//����ѧ�ţ��õ�����Ŀ��Ϣ
DATA* FindNumb(int nNumb)
{
	int nIndex = 0;
	while (nIndex < g_nCount)
	{
		if (nNumb == g_pHead[nIndex].nNumb)
			return &g_pHead[nIndex];
		++nIndex;
	}
	return 0;
}

DATA* FindName(char*sName)
{
	int nIndex = 0;
	while (nIndex < g_nCount)
	{
		if (strcmp(sName, g_pHead[nIndex].sName) == 0)
			return &g_pHead[nIndex];
		++nIndex;
	}
	return 0;
}

void GetRank(float *m, float *n)
{
	if (*m < *n)
	{
		float t = *m;
		*m = *n;
		*n = t;
	}
}

void Swap(void *a, void *b, size_t width)
{
	char *pa = (char*)a;
	char *pb = (char*)b;
	char tmp;
	if (pa != pb)
	{
		while (width--)
		{
			tmp = *pa;
			*pa++ = *pb;
			*pb++ = tmp;
		}
	}
}



void Selection_sort(void *pHead, size_t num, size_t width, int((__cdecl*comp)(const void *a, const void *b)))
{//ѡ������
	char *lo = (char *)pHead;//����ͷָ��
	char *hi = (char *)pHead+(num - 1)*width;//����βָ��

	char *max, *p;
	while (hi > lo)
	{
		max = lo;
		for (p = lo + width; p <= hi; p += width)
		{
			//if (((DATA*)p)->nNumb > ((DATA*)max)->nNumb)
			if (comp(p, max)>0)
				max = p;
		}
		Swap(max, hi, width);
		hi -= width;
	}
}
//void Selection_sort()
//{//ѡ������
//	char *lo = (char *)g_pHead;
//	char *hi = (char *)&g_pHead[g_nCount - 1];
//	int width = sizeof(g_pHead[0]);
//
//	char* max, *p;
//	while (hi > lo)
//	{
//		max = lo;
//		for (p = lo + width; p <= hi; p += width)
//		{
//			if (((DATA*)p)->nNumb > ((DATA*)max)->nNumb)
//				max = p;
//		}
//		Swap(max, hi, width);
//		hi -= width;
//	}
//}

void Insertion_Sort(void *pHead, size_t num, size_t width, int((__cdecl*comp)(const void *a, const void *b)))
{//��������
	char *p_Head = (char*)pHead;
	char *p_Move = p_Head + width;
	char *p_Reverse = p_Move;
	for (; p_Move < p_Head + num * width; p_Move += width)
	{
		//Reverse������p_Move��ǰλ�÷���ѭ��������С������
		for (p_Reverse = p_Move; p_Reverse > p_Head; p_Reverse -= width)
		{
			////////////////////�����ֵΪ����0������0��С��0����if(comp())�Ǵ�ģ�Ҫ�ж��Ƿ����0
			if (comp(p_Reverse - width, p_Reverse) > 0)
				Swap(p_Reverse - width, p_Reverse, width);
		}
	}
}