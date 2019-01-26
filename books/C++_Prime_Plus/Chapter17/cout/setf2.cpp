// setf2.cpp
#include"iostream"
#include"iomanip.h"

int main()
{
	using std::cout;
	using std::endl;
	using std::ios_base;

	cout.setf(ios_base::showpoint);
	double x=9.0;
	cout<<"x="<<x<<endl;
	cout.unsetf(ios_base::showpoint);
	cout<<"x="<<x<<endl;

	cout<<true<<" "<<false<<endl;
	cout.setf(ios_base::boolalpha);
	cout<<true<<" "<<false<<endl;
	cout.unsetf(ios_base::boolalpha);
	cout<<true<<" "<<false<<endl;

	double y=3.0;
	cout<<"y="<<y<<endl;
	cout.setf(ios_base::left,ios_base::adjustfield);
	cout.width(4);
	cout.fill('$');
	cout<<"y="<<y<<endl;
	cout.width(4);
	cout.fill('%');
	cout<<"y="<<y<<endl;
	cout.unsetf(ios_base::floatfield); // go to default mode
	cout<<"y="<<y<<endl;

	system("pause");
	return 0;
}