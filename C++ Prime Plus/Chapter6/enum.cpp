// using enum
#include"iostream"
#include"cctype"
using namespace std;
// create named constants for 0-6
enum {red,orange,yellow,green,blue,violet,indigo};

int main() {
	cout<<"Enter color code(0-6): ";
	int code;
	cin>>code;
	while(code>=red && code<=indigo && !isalpha(code)) {
		switch(code) {
		case red: cout<<"red\n"; break;
		case orange: cout<<"orange\n"; break;
		case yellow: cout<<"yellow\n"; break;
		case green: cout<<"green\n"; break;
		case blue: cout<<"blue\n"; break;
		case violet: cout<<"voilet\n"; break;
		case indigo: cout<<"indigo\n"; break;
		}
		cout<<"Enter color code(0-6): ";
		cin>>code;
	}
	cout<<"Bye.\n";

	return 0;
}