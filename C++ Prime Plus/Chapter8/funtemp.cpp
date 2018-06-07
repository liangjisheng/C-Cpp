// funtemp.cpp -- using a function template
#include"iostream"
using namespace std;
template <class T>
void Swap(T& a,T& b);

int main() 
{
	int i=10,j=20;
	cout<<"i="<<i<<",j="<<j<<endl;
	Swap(i,j);
	cout<<"i="<<i<<",j="<<j<<endl;

	double x=1.2,y=2.3;
	cout<<"x="<<x<<",y="<<y<<endl;
	Swap(x,y);
	cout<<"x="<<x<<",y="<<y<<endl;

	return 0;
}

template <class T>
void Swap(T& a,T& b) 
{
	T temp=b;
	b=a;
	a=temp;
}