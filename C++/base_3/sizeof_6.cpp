#include"iostream"
#include"memory.h"
#include"assert.h"
using namespace std;

class A{};
class A2{};
class B : public A {};
class C : public virtual B {};
class D : public A,public A2 {};

int main()
{
	cout<<"sizeof(A): "<<sizeof(A)<<endl;	// 1
	cout<<"sizeof(B): "<<sizeof(B)<<endl;	// 1
	cout<<"sizeof(C): "<<sizeof(C)<<endl;	// 4 包含虚函数表指针
	// 一个空类所占空间为1，多重继承所占空间还是1
	cout<<"sizeof(D): "<<sizeof(D)<<endl;	// 1

	system("pause");
	return 0;
}