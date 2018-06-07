// using the ctype.h library
#include"iostream"
using namespace std;
#include"cctype"

int main() {
	cout<<"Enter text for analysis,and type @"
		"to terminate input.\n";
	char ch;
	cin.get(ch);
	int whitespace =0,digits=0,chars=0,punct=0,others=0;
	while(ch!='@') {
		if(isalpha(ch)) chars++;
		else if(isspace(ch)) whitespace++;
		else if(isdigit(ch)) digits++;
		else if(ispunct(ch)) punct++;
		else others++;
		cin.get(ch);
	}
	cout<<chars<<" letters.\n"
		<<whitespace<<" whitespace.\n"
		<<punct<<" punct.\n"
		<<digits<<" digits.\n"
		<<others<<" others.\n";

	return 0;
}