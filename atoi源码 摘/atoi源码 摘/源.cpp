#include<iostream>
using namespace std;

int isspace(int x)
{
	if (x == ' ' || x == '\t' || x == '\n' || x == '\f' || x == '\b' || x == '\r')
		return 1;
	else
		return 0;
}
int isdigit(int x)
{
	if (x <= '9'&&x >= '0')
		return 1;
	else
		return 0;

}
int atoi(const char *nptr)
{
	int c;              /* current char */
	int total;         /* current total */
	int sign;           /* if '-', then negative, otherwise positive */

	/* skip whitespace */
	/* Ìø¹ý¿Õ¸ñ */
	while (isspace((int)(unsigned char)*nptr))
		++nptr;



	c = (int)(unsigned char)*nptr++;
	sign = c;           /* save sign indication */
	if (c == '-' || c == '+')
		c = (int)(unsigned char)*nptr++;    /* skip sign */

	total = 0;

	while (isdigit(c)) 
	{
		total = 10 * total + (c - '0');     /* accumulate digit */
		//Èç321
		//0	= 10 * 0 +3 = 3
		//3	= 10 * 3 +2 = 32
		//32= 10 * 32+1 = 321

		c = (int)(unsigned char)*nptr++;    /* get next char */
	}

	if (sign == '-')
		return -total;
	else
		return total;   /* return result, negated if necessary */
}
int main()
{

	char s[20] = "weq123";
	int n = atoi(s);


	system("pause");
	return 0;
}