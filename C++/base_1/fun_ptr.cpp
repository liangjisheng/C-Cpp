#include"iostream"
using namespace std;

int MAX(int a,int b)
{ return a>b?a:b; }
int MIN(int a,int b)
{ return a>b?b:a; }

int (*ptr)(int,int);	//定义指向函数的指针

int main() {
	int a=123,b=456;
	ptr=MAX;
	cout<<ptr(a,b)<<endl;
	ptr=MIN;
	cout<<ptr(a,b)<<endl;
	return 0;
}