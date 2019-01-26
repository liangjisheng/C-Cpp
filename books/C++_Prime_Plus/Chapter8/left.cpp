// left.cpp -- string function with a default argument
#include"iostream"
#include"cstring"
using namespace std;
const int ArSize=80;
char * left(const char * str, int n = 1);
char * left1(const char * str, int n = 1);
char * left2(const char * str, int n = 1);

int main() 
{
	char sample[ArSize];
	cout<<"Enter a string: \n";
	cin.get(sample,ArSize);
	int num;
	cout<<"Enter the left number of the string:";
	cin>>num;
	cout<<"The first "<<num<<" characters in the string\n";
	char * ps=left(sample,num);
	cout<<ps<<endl;
	delete []ps;
	cout<<"The only has one character.\n";
	ps=left(sample);
	cout<<ps<<endl;
	delete []ps;

	ps=left1(sample,4);
	cout<<"use left1 to get first 4 characters is "<<ps<<endl;
	delete [] ps;

	ps=left2(sample,4);
	cout<<"use left2 to get first 4 characters is "<<ps<<endl;
	delete [] ps;

	return 0;
}

char * left(const char * str, int n) 
{
	if(n<0) n = 0;
	char * p = new char[n+1];
	int i;
	for(i = 0; i < n && str[i]; i++)
		p[i] = str[i];
	while(i <= n)
		p[i++] = '\0';
	return p;
}

char * left1(const char * str, int n)
{
	if(n < 0) n=0;
	else {
		int len=strlen(str);
		n = (n < len) ? n : len;
	}
	char * p = new char[n+1];
	int i;
	for(i = 0;i < n; i++)
		p[i]=str[i];
	p[n]='\0';
	return p;
}

char * left2(const char * str,int n)
{
	int m=0;
	if(n<0) n=0;
	else {
		while(m<n && str[m]!='\0')
			m++;
	}
	char * p=new char[m+1];
	int i;
	for(i=0;i<m;i++) 
		p[i]=str[i];
	p[m]='\0';
	return p;
}