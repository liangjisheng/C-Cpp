// complex.cpp -- use complex template
#include"iostream"
#include"complex"
#include"cmath"

int main()
{
	using namespace std;
	complex<int> com1(1,2);
	complex<double> com2(3.3,4.4);
	cout<<"com1: "<<com1.real()<<"+"<<com1.imag()<<"i"<<endl;
	cout<<"com1: "<<com2.real()<<"+"<<com2.imag()<<"i"<<endl;
	cout<<"com1: "<<com1<<endl;
	cout<<"com2: "<<com2<<endl;
	complex<double> com3;
	cout<<"com3: "<<com3<<endl;
	com3=1.0+com2;
	cout<<"com3: "<<com3<<endl;

	cout<<"com1*com1="<<com1*com1<<endl;
	cout<<"pow(2,10)="<<pow(2,10)<<endl;
	cout<<"com1*com1="<<com2*com2<<endl;

	return 0;
}