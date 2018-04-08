#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

typedef int DATA;

DATA* g_pData;//首地址
int g_nCount = 0;//数据数目
int g_nSize = 4;//资源数目 

void Initialize()
{
	g_pData = (int*)malloc(sizeof(int)*g_nSize);
}

void ReAlloc()
{
	DATA* p = (DATA*)malloc(sizeof(DATA)*g_nSize * 2);
	memcpy(p, g_pData, sizeof(DATA)*g_nCount);
}

void Add(DATA d)
{
	if (g_nCount >= g_nSize)
	{
		ReAlloc();
	}
	g_pData[g_nCount++] = d;
}
void Delete(int nIndex)
{

}
DATA GetAt(int nIndex)
{
	return g_pData[nIndex];
}
void SetAt(int nIndex, DATA newData)
{
	g_pData[nIndex] = newData;
}
void Print()
{

}
int main()
{
	Initialize();
	int i = -1;
	while (++i < 10)
		Add(i + 13 - 25);
	
	Print();

	return 0;
}