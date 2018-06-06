#include"iostream"

template<typename T>
class myclass {
	T value;
public:
	myclass() { value=0; }
	myclass(T x) : value(x) {}
	template<typename X>
	void assign(const myclass<X>& x)
	{ value=x.getvalue(); }
	T getvalue() const
	{ return value; }
};

int main()
{
	myclass<double> d(4);
	myclass<int> i(2);

	d.assign(d);
	std::cout<<d.getvalue()<<std::endl;

	// 当assign不是成员函数模板时，会发生类型转换错误
	d.assign(i);
	std::cout<<d.getvalue()<<std::endl;

	system("pause");
	return 0;
}