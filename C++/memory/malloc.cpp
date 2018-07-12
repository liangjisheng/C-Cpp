#include"iostream"
#include"string.h"
using namespace std;

int main()
{
	char *ptr;
	if((ptr=(char*)malloc(0))==NULL)
		printf("Got a null pointer\n");
	else 
		printf("Got a valid pointer\n");

	if(int pp=(strlen(ptr=(char*)malloc(0)))==0)
		printf("Got a null pointer\n");
	else 
		printf("Got a valid pointer\n");

	if(int pp=(sizeof(ptr=(char*)malloc(0)))==4)
		printf("Got a null pointer\n");
	else 
		printf("Got a valid pointer\n");

	system("pause");
	return 0;
}