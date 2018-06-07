// stacktem.cpp -- testing the template stack class
#include"iostream"
#include"string"
#include"cctype"
#include"stacktp.h"
using std::cout;
using std::cin;
using std::string;

int main() 
{
	Stack<string> st;
	char ch;
	string po;
	cout<<"Please Enter A to add a purchase order.\n"
		<<"P to process a PO,or Q to quit.\n";
	while(cin>>ch && toupper(ch)!='Q') {
		while(cin.get()!='\n')
			continue;
		if(!isalpha(ch)) {
			cout<<'\a';
			continue;
		}
		switch(ch) {
		case 'a':
		case 'A':
			cout<<"Enter a PO string to add: ";
			cin>>po;
			if(st.isfull())
				cout<<"stack already full\n";
			else
				st.push(po);
			break;
		case 'p':
		case 'P':
			if(st.isempty())
				cout<<"stack already empty\n";
			else {
				st.pop(po);
				cout<<"po: "<<po<<" popped\n";
			}
			break;
		}
		cout<<"\nPlease enter A to add a purchase order.\n"
			<<"P to process a pop,or Q to quit.\n";
	}
	cout<<"Bye!\n";
	return 0;
}