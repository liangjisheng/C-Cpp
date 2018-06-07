// setf.cpp -- using setf with 2 arguements to control formatting
#include"iostream"
#include"cmath"

int main()
{
	using namespace std;
	cout.setf(ios_base::left,ios_base::adjustfield);	// 左对齐
	cout.setf(ios_base::showpos);	// 显示正负号
	cout.setf(ios_base::showpoint);
	cout.precision(3);
	// save old format setting
	ios_base::fmtflags old=cout.setf(ios_base::scientific,
		ios_base::floatfield);
	cout<<"Left Justification:\n";
	long n;
	for(n=1;n<=41;n+=10) {
		cout.width(4);
		cout<<n<<"|";
		cout.width(12);
		cout<<sqrt((double)n)<<"|\n";
	}

	// change to internal justification
	cout.setf(ios_base::internal,ios_base::adjustfield);
	// restore default float-point display style
	cout.setf(old,ios_base::floatfield);
	cout<<"Internal Justification:\n";
	for(n=1;n<=41;n+=10) {
		cout.width(4);
		cout<<n<<"|";
		cout.width(12);
		cout<<sqrt((double)n)<<"|\n";
	}

	// use right justification,fixed notation
	cout.setf(ios_base::right,ios_base::adjustfield);
	cout.setf(ios_base::fixed,ios_base::floatfield);
	cout<<"Rigth Justification:\n";
	for(n=1;n<=41;n+=10) {
		cout.width(4);
		cout<<n<<"|";
		cout.width(12);
		cout<<sqrt((double)n)<<"|\n";
	}
	
	system("pause");
	return 0;
}