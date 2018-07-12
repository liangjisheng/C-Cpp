#include"iostream"
#include"memory.h"
#include"assert.h"
using namespace std;

class A{
	char k[3];
public:
	virtual void aa() {}
	// 加上下面这行不会对类的大小有任何改变
	virtual void aa1() {}
};

class B : public virtual A {
	char j[3];
public:
	virtual void bb() {}
	// 加上下面这两行不会对类的大小有任何改变
	virtual void bb1() {}
	virtual void bb2() {}
};

class C : public B {
	char i[3];
public:
	virtual void cc() {}
	// 加上下面这行不会对类的大小有任何改变
	virtual void cc1() {}
};

int main()
{
	cout<<"sizeof(A): "<<sizeof(A)<<endl;	// 8
	cout<<"sizeof(B): "<<sizeof(B)<<endl;	// 20
	cout<<"sizeof(C): "<<sizeof(C)<<endl;	// 24

	system("pause");
	return 0;
}
