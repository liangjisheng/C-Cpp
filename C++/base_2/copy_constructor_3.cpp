
// 类的复制构造函数的调用大多发生在进行值传递的时候,为了防止类对象
// 按值传递，可以将此类的复制构造函数声明为私有的,甚至可以不必去
// 定义这个私有的复制构造函数,如果试图按值传递或函数返回该类对象,
// 将得到一个编译错误,从而避免按值传递或返回对象

// 在一个类中,复制构造函数可以存在多个,对于一个类X,如果一个构造函数的
// 第一个参数是下列之一:
// X&
// const X&
// volatile X&
// const Volatile X&
// 且没有其它参数或者其他参数都有默认值,那么这个函数是复制构造函数
// X::X(X&);			// 是复制构造函数
// X::X(const X&)		// 是
// X::X(X&, int a = 1)	// 是
// X::X(X&, int a = 1, int b = 2)	// 是

#include <iostream>

using std::cout;
using std::endl;

class CExample   
{  
private:
	int a;  
public:  
	CExample(int b)  
	{   
		a = b;  
		cout<<"creat: "<<a<<endl;  
	}
private:  
	//拷贝构造，只是声明  
	CExample(const CExample& C);  
public:  
	~CExample()	{ cout << "delete: " << a << endl; }

	void Show () { cout<<a<<endl; }
};  

void g_Fun(CExample C) { cout<<"test"<<endl; }  

int main()  
{  
	CExample test(1);  
	// g_Fun(test);			// 按值传递将编译出错

	system("pause");
	return 0;  
}   