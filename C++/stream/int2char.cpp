#include"iostream"
using namespace std;

void int2char(char* pstr,int num) 
{
	int len=0;
	int n=num;
	while(n) {
		n=n/10;
		len++;
	}
	int i=0;
	n=num;
	while(n) {
		pstr[i++]=n%10+'0';
		n=n/10;
	}
	pstr[i]='\0';
	i=0;
	char ch;
	while(i<len/2){
		ch=pstr[i];
		pstr[i]=pstr[len-i-1];
		pstr[len-i-1]=ch;
		i++;
	}
}

int main()
{
	int num;
	cout<<"input a number to string:";
	cin>>num;
	int len=0;
	int n=num;
	while(n) {
		n=n/10;
		len++;
	}
	char* pstr;
	pstr=new char[len+1];
	int2char(pstr,num);
	cout<<"转换成字符串:";
	cout<<pstr<<endl;

	system("pause");
	return 0;
}