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
		puts("�ļ�����ʧ�ܣ�");
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
		puts("�ļ���ȡʧ�ܣ�");
		system("pause");
		exit(0);
	}
	SNode* pStay = nullptr;
	while (1)
	{//fread����AddTail������ֱ��д�� �½��ѿռ� ��д��
		SNode*pNew = (SNode*)malloc(sizeof(SNode));
		if (fread(&pNew->data, 1, sizeof(DATA), pf) != sizeof(DATA))
		{
			free(pNew);//�����½�һ���ѿռ䣬��Ҫfree��
			break;
		}
		if (!g_pHead)
			g_pHead = pNew;//g_pHead����ֵ
		else
			pStay->pNext = pNew;//���µ�ַд��ѿռ���������ߵ�pNext
		pStay = pNew;
		++g_Count;
	}
	if (pStay->pNext)//ֻҪ��ֵһ�ξ͹��ˣ�����ÿ��ѭ��
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
{//������������
	int i = 0;
	puts("\n\tNumb\tName\tChin\tMath\tEngl");
	while (num--)
	{
		printf("\t%d\t%s\t%.1f\t%.1f\t%.1f\n", pSort[i]->nNum, pSort[i]->sName, pSort[i]->Chin, pSort[i]->Math, pSort[i]->Engl);
		++i;
	}
}
void Selection_sort(void *pHead, size_t num, size_t width, int((__cdecl*comp)(const void *a, const void *b)))
{//ѡ������
	SNode* pBase = (SNode*)pHead;
	DATA** pSort = (DATA **)malloc(sizeof(DATA*)*num);//ֻ����DATA����
	size_t n = 0;
	while (pBase)
	{
		pSort[n++] = &pBase->data;//����ǰ����������ÿ���ڵ��ַ˳��д��ָ�����飬�������ָ����������ָ�������
		pBase = pBase->pNext;
	}

	size_t nOrigin = 0;//ѭ�����
	size_t nRound = 0;//ѭ���α�
	size_t nMin = 0;//��ʱ�洢���С����־

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
		Swap(&(pSort[nOrigin]), &(pSort[nMin]), sizeof(pSort[0]));//  &( pSort[nOrigin] )��Ҫ����ָ�������е�Ԫ��
		 ////////////////////////////////////////////////////////////////
		++nOrigin;
	}
	Out_List_Sort_browse(pSort, num);
}
//
//void Selection_sort(void *pHead, size_t width, int((__cdecl*comp)(const void *a, const void *b)))
//{//ѡ������
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
//{//��������
//	char *p_Head = (char*)pHead;
//	char *p_Move = p_Head + width;
//	char *p_Reverse = p_Move;
//	for (; p_Move < p_Head + num * width; p_Move += width)
//	{
//		//Reverse������p_Move��ǰλ�÷���ѭ��������С������
//		for (p_Reverse = p_Move; p_Reverse > p_Head; p_Reverse -= width)
//		{
//			////////////////////�����ֵΪ����0������0��С��0����if(comp())�Ǵ�ģ�Ҫ�ж��Ƿ����0
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