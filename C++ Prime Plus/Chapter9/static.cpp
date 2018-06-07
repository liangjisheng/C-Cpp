// static.cpp -- using a static local variable
#include"iostream"
using namespace std;
const int ArSize=200;

// function prototype
void strcount(const char * str);

int main()
{
	char input[ArSize];
	char next;
	cout<<"Enter a line:\n";
	cin.get(input,ArSize);
	while(cin){
		cin.get(next);
		while(next!='\n')
			cin.get(next);
		strcount(input);
		cout<<"Enter next line(empty line to quit):\n";
		cin.get(input,ArSize);
	}
	cout<<"Bye\n";

	return 0;
}

void strcount(const char * str)
{
	static int total=0;
	int count=0;
	cout<<"\""<<str<<"\"contains ";
	while(*str)
		count++,str++;
	total+=count;
	cout<<count<<" characters\n";
	cout<<total<<" characters total\n";
}