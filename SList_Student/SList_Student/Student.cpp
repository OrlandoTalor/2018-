#include"Student.h"

SNode *g_pHead;

SNode* GetHead()
{
	return g_pHead;
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
	DATA stu;
	SNode* pNew = nullptr;
	SNode* pStay = nullptr;
	while (fread(&stu, 1, sizeof(DATA), pf) == sizeof(DATA))
	{//fread不用AddTail的写法
		pNew = (SNode*)malloc(sizeof(SNode));		
		pNew->data = stu;		
		pNew->pNext = nullptr;		
		if (!g_pHead)
		{
			g_pHead = pNew;//g_pHead赋初值
			pStay = pNew;//pStay赋初值
		}
		else
		{
			pStay->pNext = pNew;//将新地址写入堆空间的链表主线的pNext
			pStay = pStay->pNext;//pStay后移
		}
	}
	fclose(pf);
}

void AddHead(DATA data)
{
	SNode* p = (SNode*)malloc(sizeof(SNode));
	p->data = data;
	p->pNext = g_pHead;

	g_pHead = p;
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

void Selection_sort(void *pHead, size_t width, int((__cdecl*comp)(const void *a, const void *b)))
{//选择排序
	SNode* pBase = (SNode*)pHead;
	SNode *max, *pMove;
	while (pBase)
	{
		max = pBase;
		pMove = pBase->pNext;
		while (pMove)
		{
			if (comp(max, pMove) > 0)
				max = pMove;
			pMove = pMove->pNext;
		}
		Swap(pBase, max, width);

		pBase = pBase->pNext;
	}
}

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
}