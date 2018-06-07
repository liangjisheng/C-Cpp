// usetime0.cpp -- using the first draft of Time class
// compile usetime0.cpp and mytime0.cpp together
#include"iostream"
#include"mytime0.h"

int main() {
	using std::cout;
	using std::endl;
	Time planning,coding(2,40),fixing(5,55),total;

	cout<<"planning time = "<<planning<<endl;
	cout<<"coding time = "<<coding<<endl;
	cout<<"fixing time = "<<fixing<<endl;
	cout<<"total time = "<<total<<endl;

	Time li=1.5 * coding;
	cout<<"li time = "<<li<<endl;

	cout<<"planning time = ";
	planning.show();
	cout<<endl;

	cout<<"coding time = ";
	coding.show();
	cout<<endl;

	cout<<"fixing time = ";
	fixing.show();
	cout<<endl;

	total=coding.sum(fixing);
	cout<<"coding.sum(fixing) = ";
	total.show();
	cout<<endl;

	Time sum;
	sum=coding+fixing;
	cout<<"coding+fixing = ";
	sum.show();
	cout<<endl;

	sum=coding.operator +(fixing);
	cout<<"coding+fixing = ";
	sum.show();
	cout<<endl;

	Time a(4,50),b(3,10),diff,result;

	cout<<"a = ";
	a.show();
	cout<<endl;

	cout<<"b = ";
	b.show();
	cout<<endl;

	diff=a-b;
	cout<<"a - b = ";
	diff.show();
	cout<<endl;

	result=a * 1.5;
	cout<<"a * 1.5 = ";
	result.show();
	cout<<endl;

	return 0;
}