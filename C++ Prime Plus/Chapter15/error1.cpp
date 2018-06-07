// error1.cpp -- using the abort() function
#include"iostream"
#include"cstdlib"
double hmean(double,double);

int main() 
{
	double x,y,z;
	std::cout<<"Input two numbers:";
	while(std::cin>>x>>y) {
		z=hmean(x,y);
		std::cout<<"z="<<z<<std::endl;
		std::cout<<"\nInput two numbers:";
	}
	return 0;
}

double hmean(double a,double b) {
	if(a==-b) {
		std::cout<<"Untenable arguments to hmean()\n";
		abort();
	}
	return 2.0 * a * b / (a + b);

}