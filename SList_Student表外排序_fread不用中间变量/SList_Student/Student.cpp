#include"Student.h"

SNode *g_pHead;

size_t g_Count;

SNode* GetHead()
{
	return g_pHead;
}

size_t GetCount()
{
	return g_Count;
}

void Save()
{
	FILE* pf = NULL;
	fopen_s(&pf, ".\\student.orlando", "wb");
	if (!pf)
	{
		puts("文件保存失败！");
		system("pause");
		exit(0);
	}
	SNode* p = g_pHead;
	while (p)
	{
		fwrite(p, 1, sizeof(DATA), pf);
		p = p->pNext;
	}
	fclose(pf);
}

void Load()
{
	FILE* pf = nullptr;
	fopen_s(&pf, ".\\student.orlando", "rb");
	if (!pf)
	{
		puts("文件读取失败！");
		system("pause");
		exit(0);
	}
	SNode* pStay = nullptr;
	while (1)
	{//fread不用AddTail，并且直接写入 新建堆空间 的写法
		SNode*pNew = (SNode*)malloc(sizeof(SNode));
		if (fread(&pNew->data, 1, sizeof(DATA), pf) != sizeof(DATA))
		{
			free(pNew);//最后多新建一个堆空间，需要free掉
			break;
		}
		if (!g_pHead)
			g_pHead = pNew;//g_pHead赋初值
		else
			pStay->pNext = pNew;//将新地址写入堆空间的链表主线的pNext
		pStay = pNew;
		++g_Count;
	}
	if (pStay->pNext)//只要赋值一次就够了，不必每次循环
		pStay->pNext = nullptr;

	fclose(pf);
}

void AddHead(DATA data)
{
	SNode* p = (SNode*)malloc(sizeof(SNode));
	p->data = data;
	p->pNext = g_pHead;

	g_pHead = p;
	++g_Count;
}

void AddTail(DATA data)
{
	SNode* p = (SNode*)malloc(sizeof(SNode));
	p->data = data;
	p->pNext = nullptr;

	if (!g_pHead)
		g_pHead = p;
	else
	{
		SNode* pt = g_pHead;
		while (pt->pNext)
			pt = pt->pNext;
		pt->pNext = p;
	}
	++g_Count;
}

SNode* FindNumber(int nNumb)
{
	SNode* p = g_pHead;
	while (p)
	{
		if (nNumb == p->data.nNum)
			return p;
		p = p->pNext;
	}
	return 0;
}

SNode* FindName(char* sName)
{
	SNode* p = g_pHead;
	while (p)
	{
		if (strcmp(sName, p->data.sName) == 0)
			return p;
		p = p->pNext;
	}
	return 0;
}

void DeleteNode(SNode* p)
{
	if (p == g_pHead)
		g_pHead = p->pNext;
	else
	{
		SNode* pt = g_pHead;
		while (pt->pNext != p)
			pt = pt->pNext;
		pt->pNext = p->pNext;
	}
	free(p);
	--g_Count;
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

int SortByNumb(const void *a, const void *b)
{
	return ((SNode*)a)->data.nNum - ((SNode*)b)->data.nNum;
}

int SortByName(const void *a, const void *b)
{
	if (strcmp(((SNode*)a)->data.sName, ((SNode*)b)->data.sName) == 0)
		return  ((SNode*)a)->data.nNum - ((SNode*)b)->data.nNum;
	return strcmp(((SNode*)a)->data.sName, ((SNode*)b)->data.sName);
}

int SortByChinese(const void *a, const void *b)
{
	if (((SNode*)a)->data.Chin == ((SNode*)b)->data.Chin)
		return ((SNode*)a)->data.nNum - ((SNode*)b)->data.nNum;
	return (int)(((SNode*)b)->data.Chin - ((SNode*)a)->data.Chin);
}

int SortByMath(const void *a, const void *b)
{
	if (((SNode*)a)->data.Math == ((SNode*)b)->data.Math)
		return  ((SNode*)a)->data.nNum - ((SNode*)b)->data.nNum;
	return (int)(((SNode*)b)->data.Math - ((SNode*)a)->data.Math);
}

int SortByEnglish(const void *a, const void *b)
{
	if (((SNode*)a)->data.Engl == ((SNode*)b)->data.Engl)
		return  ((SNode*)a)->data.nNum - ((SNode*)b)->data.nNum;
	return (int)(((SNode*)b)->data.Engl - ((SNode*)a)->data.Engl);
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

void Out_List_Sort_browse(DATA** pSort, size_t num)
{//表外排序的浏览
	int i = 0;
	puts("\n\tNumb\tName\tChin\tMath\tEngl");
	while (num--)
	{
		printf("\t%d\t%s\t%.1f\t%.1f\t%.1f\n", pSort[i]->nNum, pSort[i]->sName, pSort[i]->Chin, pSort[i]->Math, pSort[i]->Engl);
		++i;
	}
}
void Selection_sort(void *pHead, size_t num, size_t width, int((__cdecl*comp)(const void *a, const void *b)))
{//选择排序
	SNode* pBase = (SNode*)pHead;
	DATA** pSort = (DATA **)malloc(sizeof(DATA*)*num);//只面向DATA操作
	size_t n = 0;
	while (pBase)
	{
		pSort[n++] = &pBase->data;//排序前，将链表中每个节点地址顺次写入指针数组，后面就在指针数组中做指针的排序
		pBase = pBase->pNext;
	}

	size_t nOrigin = 0;//循环起点
	size_t nRound = 0;//循环游标
	size_t nMin = 0;//临时存储最大（小）标志

	while (nOrigin < num - 1)
	{
		nMin = nOrigin;
		nRound = nOrigin + 1;
		while (nRound < num)
		{
			if (comp((pSort[nMin]), pSort[nRound]) > 0)
				nMin = nRound;
			++nRound;
		}
		////////////////////////////////////////////////////////////////
		Swap(&(pSort[nOrigin]), &(pSort[nMin]), sizeof(pSort[0]));//  &( pSort[nOrigin] )想要交换指针数组中的元素
		 ////////////////////////////////////////////////////////////////
		++nOrigin;
	}
	Out_List_Sort_browse(pSort, num);
}
//
//void Selection_sort(void *pHead, size_t width, int((__cdecl*comp)(const void *a, const void *b)))
//{//选择排序
//	SNode* pBase = (SNode*)pHead;
//	SNode *max, *pMove;
//	while (pBase)
//	{
//		max = pBase;
//		pMove = pBase->pNext;
//		while (pMove)
//		{
//			if (comp(max, pMove) > 0)
//				max = pMove;
//			pMove = pMove->pNext;
//		}
//		Swap(pBase, max, width);
//
//		pBase = pBase->pNext;
//	}
//}

//void Insertion_Sort(void *pHead, size_t width, int((__cdecl*comp)(const void *a, const void *b)))
//{//插入排序
//	char *p_Head = (char*)pHead;
//	char *p_Move = p_Head + width;
//	char *p_Reverse = p_Move;
//	for (; p_Move < p_Head + num * width; p_Move += width)
//	{
//		//Reverse用于在p_Move当前位置反向循环，送最小的数据
//		for (p_Reverse = p_Move; p_Reverse > p_Head; p_Reverse -= width)
//		{
//			////////////////////这里的值为大于0，等于0，小于0。用if(comp())是错的！要判断是否大于0
//			if (comp(p_Reverse - width, p_Reverse) > 0)
//				Swap(p_Reverse - width, p_Reverse, width);
//		}
//	}
//}

void RemoveAll()
{
	SNode *p = GetHead();
	SNode* pt = nullptr;
	while (p)
	{
		pt = p;
		p = p->pNext;
		free(pt);
	}
	g_Count = 0;
}