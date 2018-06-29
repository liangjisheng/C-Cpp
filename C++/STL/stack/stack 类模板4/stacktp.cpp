// tempparm.cpp -- template as parameters
#include"iostream"
#include"stacktp.h"

template< template<class T> class Thing>
class Crab
{
private:
	Thing<int> s1;
	Thing<double> s2;
public:
	Crab() {}
	bool push(int a,double x) 
	{ return s1.push(a) && s2.push(x); }
	bool pop(int & a,double & x) 
	{ return s1.pop(a) && s2.pop(x); }
};

int main() 
{
	using std::cout;
	using std::cin;
	using std::endl;
	Crab<Stack> ne;
	int ni;
	double nb;
	cout<<"Enter int double pairs(0 0 to end):";
	while(cin>>ni>>nb && ni>0 && nb>0) {
		if(!ne.push(ni,nb))
			break;
	}
	while(ne.pop(ni,nb))
		cout<<ni<<","<<nb<<endl;
	cout<<"Bye!\n";
	return 0;
}