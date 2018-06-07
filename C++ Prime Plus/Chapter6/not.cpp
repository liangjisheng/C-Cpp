#include"iostream"
#include"climits"
using namespace std;
bool is_int(double);

int main() {
	double num;
	cout<<"Enter an integer value:";
	cin>>num;
	while(!is_int(num)) {
		cout<<"Out of range--please try agagin:";
		cin.get();
		cin>>num;
	}
	int val=(int)num;
	cout<<"The valu is:"<<val<<endl;
	return 0;
}

bool is_int(double num) {
	if(num<=INT_MAX && num>=INT_MIN)
		return true;
	return false;
}