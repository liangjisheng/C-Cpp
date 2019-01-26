#include"iostream"
#include"STACK.H"
using namespace std;
int main(int argc,char *argv[])
{
	Stack<int> intSt;//整型栈
	Stack<char> charSt;
	int i;
	for(i=0;i<5;i++)
		intSt.push(i);
	while(!intSt.empty()){
		i=intSt.top();intSt.pop();
		cout<<i<<" ";
	}
	cout<<endl;
	for(char ch='A';ch<='E';ch++)
		charSt.push(ch);
	charSt.display(cout);
	return 0;
}