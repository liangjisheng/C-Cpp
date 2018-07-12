#include"iostream"
using namespace std;

class A{};

class A2{
	char d,e;
};

struct B{};
struct C{
	char b,c;
};

struct D{
	int x,y;
};

int main()
{
	cout<<sizeof(A)<<endl;		// 1
	cout<<sizeof(A2)<<endl;		// 2
	A *p1=new A();
	A p2;
	A * p3;
	cout<<sizeof(p1)<<endl;		// 4
	cout<<sizeof(p2)<<endl;		// 1
	cout<<sizeof(p3)<<endl;		// 4
	cout<<sizeof(B)<<endl;		// 1
	cout<<sizeof(C)<<endl;		// 2
	cout<<sizeof(D)<<endl;		// 8

	system("pause");
	return 0;
}