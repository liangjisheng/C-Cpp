// iomanip.cpp -- using manipulatiors from iomanip
// some system require explicitly linking the math library
#include"iostream"
#include"iomanip"
#include"cmath"

int main()
{
	using namespace std;
	// use new stadard manipulators
	cout<<showpoint<<fixed<<right;
	// use iomanip manipulators
	cout<<setw(6)<<"N"<<setw(14)<<"square root"
		<<setw(15)<<"fourth root\n";
	double root;
	for(int n=10;n<=100;n+=10) {
		root=sqrt((double)n);
		cout<<setw(6)<<setfill('.')<<n<<setfill(' ')
			<<setw(12)<<setprecision(3)<<root
			<<setw(14)<<setprecision(4)<<sqrt(root)
			<<endl;
	}

	cout<<left;
	double x=9.0;
	cout<<setw(10)<<setfill('.')<<x<<endl;
	cout<<right;
	cout<<setw(10)<<setfill('^')<<x<<endl;

	cout<<boolalpha<<noboolalpha;
	cout.setf(ios_base::boolalpha);
	cout.unsetf(ios_base::boolalpha);

	cout<<showbase<<noshowbase;
	cout.setf(ios_base::showbase);
	cout.unsetf(ios_base::showbase);

	cout<<showpoint<<noshowpoint;
	cout.setf(ios_base::showpoint);
	cout.unsetf(ios_base::showpoint);

	cout<<showpos<<noshowpos;
	cout.setf(ios_base::showpos);
	cout.unsetf(ios_base::showpos);

	cout<<uppercase<<nouppercase;
	cout.setf(ios_base::uppercase);
	cout.unsetf(ios_base::uppercase);

	//cout<<iternal;
	cout.setf(ios_base::internal,ios_base::adjustfield);

	cout<<left<<right;
	cout.setf(ios_base::left,ios_base::adjustfield);
	cout.setf(ios_base::right,ios_base::adjustfield);

	cout<<dec<<hex<<oct;
	cout.setf(ios_base::dec,ios_base::basefield);
	cout.setf(ios_base::hex,ios_base::basefield);
	cout.setf(ios_base::oct,ios_base::basefield);

	cout<<fixed<<scientific;
	cout.setf(ios_base::fixed,ios_base::floatfield);
	cout.setf(ios_base::scientific,ios_base::floatfield);

	system("pause");
	return 0;
}