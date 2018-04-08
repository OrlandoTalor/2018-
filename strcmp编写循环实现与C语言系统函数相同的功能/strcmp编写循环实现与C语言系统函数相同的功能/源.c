#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int Strcmp(char* sDestination,
	int n,
	const char* sResource)
{
	int i = 0;
	//任意一个（合法的）数组循环结束即可得出结果（不合法数组不会编译通过，不予考虑）
	//实际上在短数组的循环到结尾之前，即可得出结果
	while (i < n)
	{
		if ((unsigned)sDestination[i] > (unsigned)sResource[i])
			return 1;
		else if ((unsigned)sDestination[i] < (unsigned)sResource[i])
			return -1;
		i++;
	}
	return 0;
}

int main()
{
	char sDes[10] = "ABCD";
	char sRes[20] = "ABCD";
	int m = strcmp(sDes, sRes);
	int n = Strcmp(sDes, _countof(sDes), sRes);



	system("pause");
	return 0;
}