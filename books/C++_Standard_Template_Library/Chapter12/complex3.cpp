
#include <iostream>
#include <complex>
#include <math.h>

using namespace std;

int main()
{
	cout << "�����������" << endl;
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

	// �ѿ�������ϵ�ͼ�����ϵ���йغ���
	cout << "�ѿ�������ϵ�ͼ�����ϵ���йغ���" << endl;
	cout << "c5.real(): " << c5.real() << endl;
	cout << "c5.imag(): " << c5.imag() << endl;
	cout << "c5��ģֵ: " << abs(c5) << endl;
	cout << "c5��ģֵƽ��: " << norm(c5) << endl;
	cout << "c5�ķ���arg: " << arg(c5) << endl;
	cout << "c5�����conj: " << conj(c5) << endl;
	complex<double> z = polar(1.0, 3.14 / 6);
	cout << "���������궨��poloar: " << z << endl << endl;

	cout << "��������أ���������" << endl;  
	cout << "c2 + c5 = " << c2 + c5 << endl;  
	cout << "c2 - c5 = " << c2 - c5 << endl;  
	cout << "c2 * c5 = " << c2 * c5 << endl;  
	cout << "c2 / c5 = " << c2 / c5 << endl << endl; 

	system("pause");
	return 0;
}