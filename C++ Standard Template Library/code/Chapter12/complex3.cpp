
#include <iostream>
#include <complex>
#include <math.h>

using namespace std;

int main()
{
	cout << "复数类对象定义" << endl;
	double r = 1.0;
	double x = 1.0;
	complex<double> c1;
	complex<double> c2(1, 1);
	complex<double> c3(r, x);
	complex<double> c4 = 2.0;
	complex<double> c5 = c4 + complex<double>(2, 1);

	cout << "c1 = " << c1 << endl;
	cout << "c2 = " << c2 << endl;
	cout << "c3 = " << c3 << endl;
	cout << "c4 = " << c4 << endl;
	cout << "c5 = " << c5 << endl << endl;

	// 笛卡尔坐标系和极坐标系下有关函数
	cout << "笛卡尔坐标系和极坐标系下有关函数" << endl;
	cout << "c5.real(): " << c5.real() << endl;
	cout << "c5.imag(): " << c5.imag() << endl;
	cout << "c5的模值: " << abs(c5) << endl;
	cout << "c5的模值平方: " << norm(c5) << endl;
	cout << "c5的幅角arg: " << arg(c5) << endl;
	cout << "c5共轭复数conj: " << conj(c5) << endl;
	complex<double> z = polar(1.0, 3.14 / 6);
	cout << "复数极坐标定义poloar: " << z << endl << endl;

	cout << "运算符重载，四则运算" << endl;  
	cout << "c2 + c5 = " << c2 + c5 << endl;  
	cout << "c2 - c5 = " << c2 - c5 << endl;  
	cout << "c2 * c5 = " << c2 * c5 << endl;  
	cout << "c2 / c5 = " << c2 / c5 << endl << endl; 

	system("pause");
	return 0;
}