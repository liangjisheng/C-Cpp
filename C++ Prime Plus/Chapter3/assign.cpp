// assign.cpp -- type changes on assignment
#include"iostream"
using namespace std;

int main() {
	cout.setf(ios_base::fixed,ios_base::floatfield);
	float tree=3;	// int invert to float 
	int guess=3.9832;	// float to int
	int debt=7.2e12;	// result not define in C++
	long double debt1=7.2e12;	// result is correct
	// long double and double have the same bytes in memory
	double debt2=7.2e12;		// result is correct
	cout<<"tree="<<tree<<endl;
	cout<<"guess="<<guess<<endl;
	cout<<"debt="<<debt<<endl;
	cout<<"debt1="<<debt1<<endl;
	cout<<"debt2="<<debt2<<endl;
	cout<<"long double has :"<<sizeof(long double)<<" bytes"<<endl;
	cout<<"double has :"<<sizeof(double)<<" bytes"<<endl;

	return 0;
}