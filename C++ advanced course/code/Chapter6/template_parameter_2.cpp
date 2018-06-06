
// 模板的模板参数
#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

template<typename T, int Length>
class Array
{
	int size;
	T Elements[Length];
public:
	int Size() { return size; }
	Array() : size(Length) {}
	// 返回数据类型的引用，因为[]操作的结果必须能过作为左值
	T& operator[](int i) { return Elements[i]; }
	// 此友元函数是一个模板
	template<typename T, int Length> friend ostream& operator<<(ostream&, 
		const Array<T, Length>&);
	// friend ostream& operator<<(ostream&, const Array<T, Length>&);
	void show();
};

template<typename T, int Length>
void Array<T, Length>::show()
{
	for(int i = 0; i < size; i++)
		cout << Elements[i] << " ";
	cout << endl;

	if(typeid(T) == typeid(int))
		cout << "Type is integer" << endl;
	if(typeid(T) == typeid(double))
		cout << "Type is double" << endl;

	if(typeid(Elements[0]) == typeid(int))
		cout << "Type is integer" << endl;
	if(typeid(Elements[0]) == typeid(double))
		cout << "Type is double" << endl;
}

template<typename T, int Length>
ostream& operator<<(ostream &out, const Array<T, Length> &a)
{
	for(int i = 0; i < a.size; i++)
		out << a.Elements[i] << " ";
	out << endl;

	if(typeid(T) == typeid(int))
		out << "Type is integer" << endl;
	if(typeid(T) == typeid(double))
		out << "Type is double" << endl;

	if(typeid(a.Elements[0]) == typeid(int))
		out << "Type is integer" << endl;
	if(typeid(a.Elements[0]) == typeid(double))
		out << "Type is double" << endl;

	return out;
}


int main()
{
	int i = 0, j = 0, k = 0;
	Array<double, 3> a1d;
	a1d[0] = 1.1;
	a1d[1] = 2.2;
	a1d[2] = 3.3;
	// a1d.show();
	cout << a1d << endl;

	Array<Array<int, 3>, 4> a2d;
	for(i = 0; i < a2d.Size(); i++)
		for(j = 0; j < a2d[i].Size(); j++)
			a2d[i][j] = ++k;
	cout << a2d << endl;

	system("pause");
	return 0;
}

