// strgfun.cpp -- functions with a string argument
/*#include"iostream"
using namespace std;

int c_in_str(const char*,char);
char* builder(char,int);

int main() {
	char mmm[]="minimum";
	int ms=c_in_str(mmm,'m');
	cout<<ms<<" m characters in "<<mmm<<endl;

	char ch;
	int times;
	cout<<"Enter a character: ";
	cin>>ch;
	cout<<"Enter an integer: ";
	cin>>times;
	char *ps=builder(ch,times);
	cout<<ps<<endl;
	delete []ps;

	return 0;
}

char* builder(char ch,int times) {
	char *ps=new char[times+1];
	ps[times]='\0';
	while(times-->0)	// times 在本行代码执行完之后，会自动减1
		ps[times]=ch;	// 本行times 比上行times 小1，成功赋值
	return ps;
}

int c_in_str(const char* str,char ch) {
	int count=0;
	while(*str) {
		if(*str==ch)
			count++;
		str++;
	}
	return count;
}*/