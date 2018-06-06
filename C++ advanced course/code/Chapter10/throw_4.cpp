
// 对象从函数的调用处传递到函数参数里与从异常抛出点传递到catch子句里所采用的
// 方法不同，这只是参数传递与异常传递的区别的一个方面，第二个差异是在函数调用
// 者或抛出异常者与被调用者或异常捕获者之间的类型匹配的过程不同

#include <iostream>
#include <math.h>

using namespace std;

void throwint()
{
	int i = 5;
	throw i;
}

double Sqrt(double d) { return sqrt(d); }

int main()
{
	int i = 5;
	// int to double
	cout << "sqrt(5) = " << Sqrt(i) << endl;

	try{
		throwint();
	}
	// C++允许进行从int到double的隐式类型转换，上面的Sqrt(i)
	// 但是在catch子句的匹配异常类型是不会进行这样的转换
	// 下面的catch只能捕获真正为double类型的异常，不进行类型转换
	// 要想捕获int异常，必须使用带有int或int&参数的catch子句
	catch(double){
		cout << "catched" << endl;
	}
	catch(...){
		cout << "not catched" << endl;
	}
	
	system("pause");
	return 0;
}