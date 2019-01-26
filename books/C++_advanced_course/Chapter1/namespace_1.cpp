
// ���ֿռ��ʹ��

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
	// ��Ϊ�ڲ�ͬ�����ֿռ��У��������ֿ�������ͬ��
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
	
	// ���ض��������Ŀ��Ը������ؼ���һ����Լ򵥵�������
	namespace sp = MyNewlyCreatedSpaced;
	sp::show();

	system("pause");
	return 0;
}


