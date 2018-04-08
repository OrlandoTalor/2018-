#include"Student.h"

DATA* g_pHead;//首地址
int g_nCount = 0;//数据数目
int g_nSize = 2;//资源数目 

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
	memset(g_pHead, 0, sizeof(DATA)*g_nSize);//堆空间初始化为0
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
	memset(pNew, 0, sizeof(DATA)*NewSize);//堆空间初始化为0
	memcpy(pNew, g_pHead, sizeof(DATA)*g_nSize);
	g_nSize = NewSize;//覆盖新的size值
	free(g_pHead);//释放旧的堆空间
	g_pHead = pNew;//新的堆空间地址赋值给原来的头指针
	pNew = NULL;//清理新的指针
}

void AddData(DATA New_Data)
{
	if (g_nCount >= g_nSize)
		Realloc();
	g_pHead[g_nCount++] = New_Data;
}
//输入索引，将该索引和后面的信息后移1个单位，插入新信息
void InsertAt(int nIndex, DATA New_Data)
{
	if (g_nCount >= g_nSize)
		Realloc();
	DATA* p = &g_pHead[nIndex];//令p指向要插入数据的位置

	memcpy(p + 1, p, sizeof(DATA)*(g_nCount - nIndex));
	//从该位置以后的数据，整体向后移动1个DATA的长度
	g_pHead[nIndex] = New_Data;//在相应位置写入新数据
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

DATA* GetAt(int nIndex)//返回值类型为DATA
{
	return &g_pHead[nIndex];
}

void SetAt(int nIndex, DATA NewData)
{
	g_pHead[nIndex] = NewData;
}
//输入学号，得到该条目信息
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
{//选择排序
	char *lo = (char *)pHead;//定义头指针
	char *hi = (char *)pHead+(num - 1)*width;//定义尾指针

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
//{//选择排序
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
{//插入排序
	char *p_Head = (char*)pHead;
	char *p_Move = p_Head + width;
	char *p_Reverse = p_Move;
	for (; p_Move < p_Head + num * width; p_Move += width)
	{
		//Reverse用于在p_Move当前位置反向循环，送最小的数据
		for (p_Reverse = p_Move; p_Reverse > p_Head; p_Reverse -= width)
		{
			////////////////////这里的值为大于0，等于0，小于0。用if(comp())是错的！要判断是否大于0
			if (comp(p_Reverse - width, p_Reverse) > 0)
				Swap(p_Reverse - width, p_Reverse, width);
		}
	}
}