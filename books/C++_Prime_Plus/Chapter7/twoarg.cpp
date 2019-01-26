#include"iostream"
#include"cctype"
using namespace std;

void n_char(char,int);

int main() {
	char ch=' ';
	int times;

	cout<<"Enter char untile @ to exit:";
	cin>>ch;
	while(ch!='@') {
		while(!isalpha(ch)) {
			cin.clear();
			while(cin.get()!='\n')
				continue;
			cout<<ch<<" is not a char\n"
				"Please reinput the char:";
			cin>>ch;
		}
		while(cin.get()!='\n')
			continue;
		
		cout<<"input times:";
		while(!(cin>>times)) {
			cin.clear();
			while(cin.get()!='\n')
				continue;
			cout<<times<<" is not a number\n"
				"Please reinput the times:";
		}
		
		n_char(ch,times);
		cout<<"\nEnter char untile @ to exit:";
		cin>>ch;
	}

	return 0;
}

void n_char(char ch,int n) {
	while(n-->0)
		cout<<ch<<" ";
	cout<<endl;
}