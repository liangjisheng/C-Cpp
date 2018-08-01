#include"iostream"
#include"vector"
#include"stack_1.h"

int main()
{
	Stack<int,vector<int> > vStack;
	
	vStack.push(1);
	vStack.push(2);
	cout<<vStack.top()<<endl;

	system("pause");
	return 0;
}
