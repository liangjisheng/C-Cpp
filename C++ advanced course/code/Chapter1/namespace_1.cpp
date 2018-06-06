
// 名字空间的使用

#include <iostream>

namespace myspace1
{
	int gvar;
	using std::cout;
	using std::endl;
	class myclass
	{
	public:
		void print() { cout << "in space1, gvar = " << gvar << endl; }
	};
}


namespace myspace2
{
	using std::cout;
	using std::endl;
	// 因为在不同的名字空间中，所以名字可以起相同的
	class myclass
	{
	public:
		void print() { cout << "in space2" << endl; }
	};
	namespace nestedspace
	{
		void ExternFunc() 
		{ cout << "you can reference a function within another namespace" << endl; }
	}
}


namespace MyNewlyCreatedSpaced
{
	void show() { std::cout << "a function within a namespace" << std::endl; }
}


int main()
{
	myspace1::myclass obj1;
	obj1.print();
	myspace2::myclass obj2;
	obj2.print();
	myspace2::nestedspace::ExternFunc();
	std::cout<< std::endl;
	
	// 在特定的上下文可以给命名控件起一个相对简单的上下文
	namespace sp = MyNewlyCreatedSpaced;
	sp::show();

	system("pause");
	return 0;
}


