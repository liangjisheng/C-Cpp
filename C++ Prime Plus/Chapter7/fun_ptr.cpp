// fun_ptr.cpp -- pointers to functions
#include"iostream"
using namespace std;
double betsy(int);
double pam(int);

void estimate(int,double(*pf)(int));

int main() {
	int code;
	cout<<"How many lines of code do you need?";
	cin>>code;
	cout<<"Here's Besyt's estimate:\n";
	estimate(code,betsy);

	return 0;
}

double betsy(int line) {
	return 0.005*line/100;
}

void estimate(int lines,double(*pf)(int)) {
	cout<<lines<<" lines will take: ";
	cout<<(*pf)(lines)<<" hour(s)\n";
}