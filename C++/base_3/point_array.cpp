#include"iostream"
using namespace std;

int main()
{
	static int a[2]={1,2};
	int* ptr[5];	// ึธี๋สื้
	int p=5,p2=6,*page,*page2;
	page=&p;
	page2=&p2;
	
	ptr[0]=page;
	ptr[1]=page2;

	cout<<*ptr[0]<<endl;
	cout<<*page<<endl;
	cout<<*ptr[1]<<endl;
	cout<<*page2<<endl;

	system("pause");
	return 0;
}