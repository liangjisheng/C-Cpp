#include"iostream"
using namespace std;

class A1{
public:
	int a;
	static int b;

	A1();
	~A1();
};

class A2{
public:
	int a;
	char c;
	A2();
	~A2();
};

class A3{
public:
	float a;
	char c;
	A3();
	~A3();
};

class A4{
public:
	float a;
	int b;
	char c;
	A4();
	~A4();
};

class A5{
public:
	double d;
	float a;
	int b;
	char c;
	A5();
	~A5();
};

int main()
{
	// 静态变量存放在全局区，sizeof计算栈中分配的大小
	// static int b;不会计算在内，所有sizeof(A1)=4
	cout<<sizeof(A1)<<endl;		// 4
	cout<<sizeof(A2)<<endl;		// 8
	cout<<sizeof(A3)<<endl;		// 8
	cout<<sizeof(A4)<<endl;		// 12
	cout<<sizeof(A5)<<endl;		// 24

	system("pause");
	return 0;
}