
#include<iostream>

using std::cout;
using std::endl;


class CExample 
{
private:
	int a;
public:
	//构造函数
	CExample(int b)
	{ 
		a = b;
		cout<<"creat: "<<a<<endl;
	}
	//拷贝构造
	CExample(const CExample& C)
	{
		a = C.a;
		cout<<"copy"<<endl;
	}
	//析构函数
	~CExample()	{ cout << "delete: "<< a << endl; }

	void Show () { cout << a << endl; }
};

void g_Fun(CExample C) { cout<<"test"<<endl; }

CExample g_Fun1() { CExample tmp(0); return tmp; }

int main()
{
	// CExample test(1);
	// g_Fun(test);

	// 出现两次delete 0，因为返回对象的时候，会先创建已临时对象X，tmp copy 给X,
	// 然后delete tmp, g_Func1结束后，delete X
	g_Fun1();

	system("pause");
	return 0;
}