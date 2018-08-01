#include"iostream"
#include"string"
#include"cstdlib"
#include"vector"
#include"MyStack.h"

int main()
{
	try{
		Stack<int> intStack;
		Stack<double> dblStack;

		intStack.push(42);
		intStack.push(7);

		dblStack.push(7.7);
		dblStack.push(7.8);

		// cout dblSTack
		while(!dblStack.empty()) {
			cout<<dblStack.top()<<' ';
			dblStack.pop();
		}
		cout<<endl;
		
		dblStack=intStack;
		
		// cout dblSTack
		while(!dblStack.empty()) {
			cout<<dblStack.top()<<' ';
			dblStack.pop();
		}
		cout<<endl;
	}
	catch(exception const& ex) {
		cerr<<"Exception: "<<ex.what()<<endl;
	}
	
	Stack<int,vector> vStack;
	vStack.push(42);
	vStack.push(7);
	cout<<vStack.top()<<endl;
	vStack.pop();

	system("pause");
	return 0;
}
