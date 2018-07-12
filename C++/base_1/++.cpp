#include"iostream"
using namespace std;

int main()
{
	int a=4;
	a+=(a++);
	cout<<"a+=(a++)="<<a<<endl;

	a=4;
	a+=(++a);
	cout<<"a+=(++a)="<<a<<endl;

	a=4;
	(++a)+=(a++);
	cout<<"(++a)+=(a++)="<<a<<endl;

	char str[]="lishuyu";
	cout<<"sizeof(str)="<<sizeof(str)<<endl;
	char *p=str;
	int n=10;
	cout<<"sizeof(p)="<<sizeof(p)<<endl;
	cout<<"sizeof(n)="<<sizeof(n)<<endl;

	int arr[]={6,7,8,9,10};
	int * ptr=arr;
	*(ptr++)+=123;
	printf("%d,%d\n",*ptr,*(++ptr));

	system("pause");
	return 0;
}