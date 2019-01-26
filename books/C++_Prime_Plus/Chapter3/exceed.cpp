// exceed.cpp -- exceeding some integer limits
#include"iostream"
using namespace std;
#include"climits"
#define ZERO 0

int main() {
	short sam=SHRT_MAX;
	unsigned short sue=sam;
	cout<<"sam has:"<<sam<<" dollars and Sue has:"<<sue
		<<" dollars deposited."<<endl;
	cout<<"Add $1 to each account."<<endl;
	sam+=1; sue+=1;
	cout<<"sam has:"<<sam<<" dollars and Sue has:"<<sue
		<<" dollars deposited."<<endl;
	sue=sam=ZERO;
	cout<<"sam has:"<<sam<<" dollars and Sue has:"<<sue
		<<" dollars deposited."<<endl;
	
	sam-=1; sue-=1;
	cout<<"sam has:"<<sam<<" dollars and Sue has:"<<sue
		<<" dollars deposited."<<endl;
	return 0;
}