// output2.cpp -- default format
#include"iostream"

int main()
{
	using std::cout;
	using std::endl;
	using std::ios_base;

	double d1=1.200;
	cout<<d1<<":\n";
	cout<<(d1+1.0/9.0)<<":\n";
	cout.precision(3);	
	cout<<(d1+1.0/9.0)<<":\n";

	double d2=1.67E2;
	cout<<d2<<":\n";
	d2+=1.0/9.0;
	cout<<d2<<":\n";
	cout<<(d2*1.0e4)<<":\n";

	double d3=2.3e-4;
	cout<<d3<<":\n";
	cout<<d3/10<<":\n";
	
	cout<<'#';
	cout.width(10);		// width() 只会影响接下来的一个项目
	cout.fill('%');		// fill()	一直有效
	cout<<12<<'#'<<24<<"#\n";
	cout.width(20);
	cout<<5<<endl;

	// showpoint
	float price1=20.40;
	float price2=1.9+8.0/9.0;
	cout<<"price1 is: "<<price1<<endl;
	cout<<"price2 is: "<<price2<<endl;
	cout.setf(ios_base::showpoint);
	cout.precision(2);
	cout<<"price1 is: "<<price1<<endl;
	cout<<"price2 is: "<<price2<<endl;

	int temp=63;
	cout<<"temp="<<temp<<endl;
	cout.setf(ios_base::showpos);	// 显示正负号
	cout<<"temp="<<temp<<endl;
	cout<<std::hex<<"temp="<<temp<<endl;
	cout.setf(ios_base::uppercase);	// 显示基数的字母大写
	cout.setf(ios_base::showbase);	// 显示基数
	cout<<"temp="<<temp<<endl;

	cout<<true<<' '<<false<<endl;
	cout.setf(ios_base::boolalpha);
	cout<<true<<' '<<false<<endl;

	system("pause");
	return 0;
}