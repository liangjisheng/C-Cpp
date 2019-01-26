// arraynew.cpp -- using the new operator for arrays

#include"iostream"
using namespace std;

int main()
{
	double *p=new double[3];
	p[0]=0.2;
	p[1]=0.4;
	p[2]=0.8;
	cout<<"p[1] is :"<<p[1]<<endl;
	p=p+1;
	cout<<"Now p[0] is "<<p[0]<<" and ";
	cout<<"p[1] is "<<p[1]<<endl;
	p=p-1;
	delete []p;

	return 0;
}