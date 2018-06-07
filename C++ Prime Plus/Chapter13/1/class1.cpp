// class1.cpp -- base and deirved classes methods
#include"class1.h"
#include"iostream"

// base class method
base::base() : n(0),x(0.0) {}

base::base(int nn) : n(nn),x(0.0) {}

base::base(int nn,double xx) : n(nn),x(xx) {}

base::base(const base & b) : n(b.n),x(b.x) {}

base & base::operator =(const base & b) {
	n=b.n,x=b.x;
	return *this;
}

base::~base() {}

void base::Show() const 
{ std::cout<<"n="<<n<<",x="<<x<<std::endl;}

std::ostream & operator<<(std::ostream & os,const base & b)
{
	os<<"n="<<b.n<<",x="<<b.x;
	return os;
}

// derived class method
derived::derived() : base(),n1(0),x1(0.0) {}

derived::derived(int nn) : base(nn,0.0),n1(0),x1(0.0) {}

derived::derived(int nn,double xx) : base(nn,xx),n1(0),x1(0.0) {}

derived::derived(int nn,int nn1,double xx) : base(nn,xx),n1(nn1),x1(0.0) {}

derived::derived(int nn,int nn1,double xx,double xx1) 
: base(nn,xx),n1(nn1),x1(xx1) {}

derived::derived(const derived & d) 
: base(d.getn(),d.getx()), n1(d.getn1()), x1(d.getx1()) {}

derived & derived::operator =(const derived & d)
{
	setn(d.getn());
	setx(d.getx());
	n1=d.getn1();
	x1=d.getx1();
	return *this;
}

derived::~derived() {}

void derived::Show() const {
	std::cout<<"n="<<getn()<<",n1="<<n1;
	std::cout<<",x="<<getx()<<",x1="<<x1<<std::endl;
}

std::ostream & operator<<(std::ostream & os,const derived & d) {
	os<<"n="<<d.getn()<<",n1="<<d.n1
		<<",x="<<d.getx()<<",x1="<<d.x1;
	return os;
}