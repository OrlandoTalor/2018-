/*strstr function*/
#include<string.h> 
char *(strstr)(const char *s1, const char *s2)
{                           /* find first occurrence of s2[] in s1[] */
	if (*s2 == '\0')
		return ((char*)s1);
	for (; (s1 = strchr(s1, *s2)) != NULL; ++s1) {/*match rest of prefix*/
		const char *sc1, *sc2;
		for (sc1 = s1, sc2 = s2;;)
			if (*++sc2 == '\0')
				return ((char *)s1);
			else if (*++sc1 != *sc2)
				break;
	}
	return (NULL);
}
/*strchr function*/
#include<string.h> 
char *(strchr)(const char *s, int c)
{                       /* find first occurrence of c in char s[] */
	const char ch = c;
	for (; *s != ch; ++s)
		if (*s == '\0')
			return (NULL);
	return ((char*)s);
}

int main()
{

	return 0;
}