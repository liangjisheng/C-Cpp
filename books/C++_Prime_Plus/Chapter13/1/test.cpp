#include"iostream"
#include"class1.h"
using std::cout;
using std::endl;

int main() {
	base b1,b2(2),b3(3,4);
	derived d1,d2(4),d3(4,5),d4(4,5,6),d5(4,5,6,7);
	//b1.Show();
	//b2.Show();
	//b3.Show();
	cout<<b1<<endl;
	cout<<b2<<endl;
	cout<<b3<<endl;
	//d1.Show();
	//d2.Show();
	//d3.Show();
	//d4.Show();
	//d5.Show();
	cout<<d1<<endl;
	cout<<d2<<endl;
	cout<<d3<<endl;
	cout<<d4<<endl;
	return 0;
}