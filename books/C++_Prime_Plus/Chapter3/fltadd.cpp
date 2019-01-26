// fltadd.cpp -- precision problems with float
#include"iostream"
using namespace std;
int main() {
	float a=2.34e+22f;
	float b=a+1.0f;
	cout<<"a="<<a<<endl;
	cout<<"b="<<b<<endl;
	cout<<"b-a="<<b-a<<endl;
	return 0;
}