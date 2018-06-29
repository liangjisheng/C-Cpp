#include"iostream"
#include"cstring"
#define square(a) ((a)*(a))
using namespace std;

int main()
{
	char* src="hello,world";
	char* dest=NULL;
	int len=strlen(src);
	cout<<len<<endl;
	dest=new char[len+1];
	char* d=dest;
	char* s=&src[len-1];
	while(len--!=0)
		*d++=*s--;
	*d='\0';
	cout<<src<<endl;
	cout<<dest<<endl;
	delete []dest;

	int a=5;
	int b=square(a++);
	cout<<b<<endl;

	system("pause");
	return 0;
}