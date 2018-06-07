// error2.cpp -- return an error code
#include"iostream"
#include"cfloat"	// for DBL_MAX
bool hmean(const double,const double,double *);

int main() 
{
	double x,y,z;
	double re=DBL_MAX;
	std::cout<<DBL_MAX<<std::endl;
	std::cout<<"Enter two numbers(q for exit):";
	while(std::cin>>x>>y) {
		while(std::cin.get()!='\n')
			continue;
		if(hmean(x,y,&z)) {
			std::cout<<"z="<<z<<std::endl;
			std::cout<<"\nEnter two numbers(q for exit):";
		} else {
			std::cout<<"error:"<<x<<"+"<<y<<"=0"<<std::endl;
			std::cout<<"\nEnter two numbers(q for exit):";
		}
	}
	return 0;
}

bool hmean(const double x,const double y,double * pz) {
	if(x==-y) return false;
	*pz=2.0 * x * y / (x + y);
	return true ;
}