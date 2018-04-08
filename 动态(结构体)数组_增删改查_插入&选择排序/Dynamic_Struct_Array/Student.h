#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#include<conio.h>
#include <locale>

struct _SStudent
{
	int nNumb;
	char sName[20];
	float fChin;
	float fMath;
	float fEngl;
};

typedef struct _SStudent DATA;

void Load();
void Save();

void Initialize();
void Print();
void AddData(DATA);//正常添加数据
void InsertAt(int, DATA);//insert
int RemoveAt(int);//remove
DATA* GetAt(int);//get
void SetAt(int, DATA);//put

DATA* FindNumb(int);//seac-rch
DATA* FindName(char*);
void GetRank(float*, float*);
int GetCount();//size
DATA* GetHead();
//sort
//void Selection_sort();
void Selection_sort(void *pHead, size_t num, size_t width, int((__cdecl*comp)(const void *a, const void *b)));
void Insertion_Sort(void *pHead, size_t num, size_t width, int((__cdecl*comp)(const void *a, const void *b)));
