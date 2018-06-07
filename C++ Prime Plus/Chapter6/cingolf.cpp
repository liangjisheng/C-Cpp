// non-numeric input skipped
#include"iostream"
using namespace std;
const int Max=5;

int main() {
	int golf[Max];
	cout<<"Please Enter your golf scores.\n";
	cout<<"You must enter "<<Max<<" roudns.\n";
	int i;
	for(i=0;i<Max;i++) {
		cout<<"round# "<<i+1<<":";
		while(!(cin>>golf[i])) {
			cin.clear(); // reset input
			while(cin.get()!='\n')
				continue; // get rid of bad input
			cout<<"Please enter a number: ";
		}
	}
	cout<<"input successed\n";

	return 0;
}