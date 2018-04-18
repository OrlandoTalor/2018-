#include<process.h>		//Ïß³Ì


void print_SYSTEMTIME(void * p);
void print_Localtime(void* p);
void both();
int main()
{

	//_beginthread(print_SYSTEMTIME,0,0);
	//_beginthread(print_Localtime, 0, 0);
	both();

	system("pause");
	return 0;
}