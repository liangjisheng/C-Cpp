#include"iostream"
#include"tchar.h"
#include"iomanip"
using namespace std;

class Base{
public:
	double dvar;
	int ivar;
	Base(int i=0,double d=0) : ivar(i),dvar(d) {}
	void foo1() { cout<<ivar<<endl; }
	void foo2() { cout<<dvar<<endl; }
};

// 类成员函数指针
typedef void (Base::*CLASS_FUNC)();

int _tmain(int argc,_TCHAR* argv[]) 
{
	Base base;
	cout<<"类对象的地址:"<<&base<<endl;
	cout<<"double成员地址:"<<&(base.dvar);
	cout<<" 所占字节:"<<sizeof(double)<<endl;
	cout<<"int成员地址:"<<&(base.ivar);
	cout<<" 所占字节:"<<sizeof(int)<<endl;

	// member function address
	CLASS_FUNC pFunc=&(Base::foo1);
	unsigned* tmp=(unsigned*)&pFunc;
	cout<<"Base类第一个成员函数的地址为:"<<hex<<*tmp<<endl;
	pFunc=&(Base::foo2);
	tmp=(unsigned*)&pFunc;
	cout<<"Base类第二个成员函数的地址为:"<<hex<<*tmp<<endl;

	system("pause");
	return 0;
}