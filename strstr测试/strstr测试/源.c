//strstr
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
	char str[] = "lazy";
	char string[] = "The quick brown dog jumps over the lazy fox";
	char fmt1[] = "         1         2         3         4         5";
	char fmt2[] = "12345678901234567890123456789012345678901234567890";

	char* pdest = 0;
	int result = 0;

	printf("String to be searched:\n     %s\n", string);
	printf("     %s\n     %s\n\n", fmt1, fmt2);

	pdest = strstr(string, str);
	result = (int)(pdest - string + 1);
	if (pdest != NULL)
		printf("%s found at position %d\n", str, result);
	else
		printf("%s not found\n", str);
	system("pause");
	return 0;
}