#include"iostream"
#include"cstring"
#include"cassert"
using namespace std;

class Complex1;
ostream & operator <<(ostream &,const Complex1 &);

class Complex1{
	double re,im;
public:
	Complex1();
	Complex1(double,double);
	Complex1(const Complex1 &);
	Complex1 & operator =(const Complex1 &);
	~Complex1();
	double real() const { return re; }
	double imag() const { return im; }
	friend ostream & operator <<(ostream &,const Complex1 &);
};

Complex1::Complex1() : re(0),im(0) { cout<<"constructor"<<endl; }

Complex1::Complex1(double r,double i) : re(r),im(i) { cout<<"constructor"<<endl; }

Complex1::Complex1(const Complex1 & c) : re(c.re),im(c.im) { cout<<"constructor"<<endl; }

Complex1 & Complex1::operator =(const Complex1 & c) {
	cout<<"constructor"<<endl;
	if(this==&c)
		return *this;
	re=c.re; im=c.im;
	return *this;
}

Complex1::~Complex1() { cout<<"destructor"<<endl; }

ostream & operator <<(ostream & os,const Complex1 & c) {
	if(c.imag()>0)
		os<<c.real()<<"+"<<c.imag()<<"i";
	else if(c.imag()==0)
		os<<c.real();
	else 
		os<<c.real()<<c.imag()<<"i";
	return os;
}

int main() {
	Complex1 c1(2,3),c2,c3;
	c2=c3=c1;
	cout<<c1<<endl;
	cout<<c2<<endl;
	cout<<c3<<endl;
	return 0;
}