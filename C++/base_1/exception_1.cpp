#include"iostream"
using namespace std;

// double Divide(double a,double b) throw (char*,double)
// 表示Divide函数只能抛出char*或者double型类型的异常
// 若抛出其他异常，则会条用标准库函数unexcepted()来处理，
// unexcepted()函数默认调用terminate()函数来结束程序

// double Divide(double a,double b) throw ()
// 表明这个函数不会抛出任何类型的异常
double Divide(double a,double b) {
	if(b==0)
		throw "0不能作为除数";
	return a/b;
}

int main()
{
	try {
		double re=Divide(4,0);
	}
	catch(char* pMsg) {
		cout<<pMsg<<endl;
	}

	system("pause");
	return 0;
}