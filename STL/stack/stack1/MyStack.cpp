#include"iostream"
#include"MyStack.h"

int main()
{
	Stack<int> intStack;
	Stack<double> dblStack;

	intStack.push(1);
	intStack.push(2);
	dblStack.push(3.0);
	dblStack.push(4.0);
	
	// cout dblStack
	while(!dblStack.empty()) {
		cout<<dblStack.top()<<' ';
		dblStack.pop();
	}
	cout<<endl;
	
	dblStack.push(3.0);
	dblStack.push(4.0);
	
	dblStack=intStack;
	
	// cout dblStack
	while(!dblStack.empty()) {
		cout<<dblStack.top()<<' ';
		dblStack.pop();
	}
	cout<<endl;

	system("pause");
	return 0;
}
