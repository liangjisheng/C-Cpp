// error2.cpp -- using an exception
#include"iostream"
double hmean(double,double);

int main() 
{
	double x,y,z;
	std::cout<<"Enter tow numbers(q to exit):";
	while(std::cin>>x>>y) {
		try {
			z=hmean(x,y);
		}
		catch(const char * s) {
			std::cout<<s<<std::endl;
			std::cout<<"Enter tow numbers(q to exit):";
			continue;
		}
		std::cout<<"z="<<z<<std::endl;
		std::cout<<"\nEnter tow numbers(q to exit):";
	}
	return 0;
}

double hmean(double x,double y) {
	if(x==-y) 
		throw "bad hmean() arguments:x = -y not allowed";
	return 2.0 * x * y / (x + y);
}