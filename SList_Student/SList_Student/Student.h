#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<locale>
struct SStu
{
	int nNum;
	char sName[32];
	float Chin;
	float Math;
	float Engl;
};

typedef SStu DATA;

struct SNode
{
	DATA data;
	SNode *pNext;
};

SNode* GetHead();

void Save();

void Load();

void AddHead(DATA data);

void AddTail(DATA data);

SNode* FindNumber(int nNumb);

SNode* FindName(char* sName);

void DeleteNode(SNode* p);

void GetRank(float *m, float *n);

int SortByNumb(const void *a, const void *b);
int SortByName(const void *a, const void *b);
int SortByChinese(const void *a, const void *b);
int SortByMath(const void *a, const void *b);
int SortByEnglish(const void *a, const void *b);

void Selection_sort(void *pHead, size_t width, int((__cdecl*comp)(const void *a, const void *b)));

//void Insertion_Sort(void *pHead,size_t width, int((__cdecl*comp)(const void *a, const void *b)));

void RemoveAll();