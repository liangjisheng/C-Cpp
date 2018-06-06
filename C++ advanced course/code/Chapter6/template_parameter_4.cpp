
#include <iostream>

using std::cout;
using std::endl;

template<class T, int a>
class X
{
public:
	T valX[a];
};

template<class T, int a>
class Y
{
	X<T, a> valY;
public:
	void Set(T t) { valY.valX[0] = t; }
	void ShowFirst() { cout << valY.valX[0] << endl; }
};


int main()
{
	Y<double, 3> y;
	y.Set(0.8);
	y.ShowFirst();

	system("pause");
	return 0;
}

