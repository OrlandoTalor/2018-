/*1、参照C语言库函数中的内存族函数，开发以下内存操作函数：
//内存拷贝函数，参照memcpy
void *MemoryCopy(void *dest, const void *src,size_t count);
//两段内存比较函数，参照memcmp
int MemoryCompare(const void *buf1, const void *buf2,size_t count); */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void* MemoryCopy(void *dest, const void *src, size_t count)
{
	void* ret = dest;
	while (count--)
	{
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}
	return (ret);
}

int MemoryCompare(const void *buf1, const void *buf2, size_t count)
{//源码
	if (!count)
		return 0;
	while (--count && *(char*)buf1 == *(char*)buf2)
	{
		buf1 = (char*)buf1 + 1;
		buf2 = (char*)buf2 + 1;
	}

	return *(unsigned char*)buf1 -  *(unsigned char* )buf2;
}
int main()
{
	char s1[20] = "abcde";
	char s2[20] = "ABCDEFG";
	//MemoryCopy(s1, s2, sizeof(s2));
	//memcpy(s1, s2, 20);
	//puts(s1);
	//puts(s2);
	char s3[20] = "abcdF";
	char s4[20] = "abcdf";
	puts(s3);
	puts(s4);
	//int n = memcmp(s3, s4, sizeof(s2));
	int n = MemoryCompare(s3, s4, sizeof(s3));
	printf("%d\n", n);
	system("pause");
	return 0;
}