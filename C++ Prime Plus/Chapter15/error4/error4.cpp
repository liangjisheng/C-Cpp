// error4.cpp -- using exception class
#include"iostream"
#include"cmath"
#include"exe_mean.h"

double hmean(double,double);
double gmean(double,double);

int main() 
{
	double x,y,z,z1;
	std::cout<<"Enter two numbers(q to exit):";
	while(std::cin>>x>>y) {
		try{
			z=hmean(x,y);
			std::cout<<"hmean("<<x<<","<<y<<") = "<<z<<std::endl;
			z1=gmean(x,y);
			std::cout<<"gmean("<<x<<","<<y<<") = "<<z1<<std::endl;
			std::cout<<"\nEnter two numbers(q to exit):";
		}
		catch(bad_gmean & bg) {
			bg.mesg();
			std::cout<<"\nEnter two numbers(q to exit):";
			continue;
		}
		catch(bad_hmean & bh) {
			bh.mesg();
			std::cout<<"\nEnter two numbers(q to exit):";
			continue;
		}
	}
	return 0;
}

double hmean(double x,double y) {
	if(x==-y) throw(bad_hmean(x,y));
	return 2.0 * x * y / (x + y);
}

double gmean(double x,double y) {
	if(x<=0 || y<=0) throw(bad_gmean(x,y));
	return sqrt(x * y);
}