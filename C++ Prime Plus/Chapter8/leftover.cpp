// leftover.cpp -- overloading the left() function
#include"iostream"
#include"cstring"
using namespace std;
unsigned long left(unsigned long num,unsigned ct);
char * left(const char * str,int n = 1);

int main() 
{
	char * trip="Hawaii!!a";
	unsigned long n=12345678;
	int i;
	char *temp;
	cout<<strlen(trip)<<endl;

	for(i=1;i<10;i++) {
		cout<<left(n,i)<<endl;
		temp=left(trip,i);
		cout<<temp<<endl;
		delete [] temp;
	}
	return 0;
}

unsigned long left(unsigned long num,unsigned ct)
{
	unsigned digits=1;
	unsigned long n=num;
	if(num==0 || ct==0)
		return 0;
	while(n/=10)
		digits++;
	if(digits>ct) {
		ct=digits-ct;
		while(ct--)
			num/=10;
		return num;
	}
	else 
		return num;
}

char * left (const char * str,int n) 
{
	if(n<0) n=0;
	int i,len;
	len=strlen(str);
	n=(n<len)? n : len;
	char * p=new char[n+1];
	for(i=0;i<n; i++)
		p[i]=str[i];
	p[n]='\0';
	return p;
}