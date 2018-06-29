#include"stack.h"

int main()
{
	stack s(20);
	s.push('a');
	cout<<s<<endl;
	s.push('b');
	s.push('c');
	s.push('d');
	s.push('e');
	cout<<s<<endl;

	char ch;
	ch=s.pop();
	cout<<ch<<endl;
	ch=s.pop();
	cout<<ch<<endl;
	cout<<s<<endl;

	return 0;
}
