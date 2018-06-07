// error5.cpp -- unwinding the stack ∂—’ªΩ‚ÕÀ
#include"iostream"
#include"cmath"
#include"cstring"
#include"exe_mean.h"

class demo{
	char word[40];
public:
	demo(const char * str) {
		strcpy(word,str);
		std::cout<<"demo "<<word<<" created\n";
	}
	virtual ~demo() 
	{ std::cout<<"demo "<<word<<" destroyed\n"; }
	void show() const 
	{ std::cout<<"demo "<<word<<" lives.\n"; }
};

// function prototypes
double hmean(double,double) throw(bad_hmean);
double gmean(double,double) throw(bad_gmean);
double means(double,double) throw(bad_hmean,bad_gmean);

int main()
{
	using std::cout;
	using std::endl;
	using std::cin;
	double x,y,z;
	demo d1("found in main()");
	cout<<"Enter two numbers:";
	while(cin>>x>>y) {
		try {
			z=means(x,y);
			cout<<"z="<<z<<endl;
			cout<<"\nEnter two numbers:";
		}
		catch(bad_hmean & bh) {
			bh.mesg();
			cout<<"\nEnter two numbers:";
			continue;
		}
		catch(bad_gmean & bg) {
			bg.mesg();
			cout<<"\nEnter two numbers:";
			continue;
		}
	}
	d1.show();
	return 0;
}

double hmean(double x,double y) throw(bad_hmean) {
	if(x==-y) throw bad_hmean(x,y);
	return 2.0 * x * y / (x + y);
}

double gmean(double x,double y) throw(bad_gmean) {
	if(x<=0 || y<=0) throw bad_gmean(x,y);
	return sqrt(x * y);
}

double means(double x,double y) throw(bad_hmean,bad_gmean) {
	double am,hm,gm;
	demo d2("found in means()");
	am=(x + y) / 2.0;
	try{
		hm=hmean(x,y);
		gm=gmean(x,y);
	}
	catch(bad_hmean & bh) {
		bh.mesg();
		std::cout<<"Counth in means()\n";
		throw;
	}
	d2.show();
	return (am + hm + gm) / 3.0;
}