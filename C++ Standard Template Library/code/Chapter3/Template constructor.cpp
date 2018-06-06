
// Template constructor是member template的一种特殊形式,通常用于
// 在复制对象时实现隐式类别转换。注意，template constructor并不遮蔽(hide)
// implicit copy constructor.如果型别完全吻合，implicit copy constructor
// 就会被产出出来并被调用

#include"iostream"
using namespace std;

template<typename T>
class MyClass
{
	public:
		MyClass()
		{

		}
		template<typename U>
		MyClass(const MyClass<U>& x)
		{
			cout<<"template constructor"<<endl;
		}
		MyClass(const MyClass& x)
		{
			cout<<"built-in copy constructor"<<endl;
		}
};


int main()
{
	MyClass<double> xd;
	MyClass<double> xd2(xd);	// calls built-in copy
	MyClass<int> xi(xd);		// calls template constructor

	system("pause");
	return 0;
}