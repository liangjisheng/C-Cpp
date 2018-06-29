#include"iostream"
using namespace std;
int main()
{
	char str1[50]="liangaaaaa",str2[10]="ng";
    char *p1=str1,*p2=str2,*p,*pos;
	int count=0;
	cout<<"str1="<<str1<<",str2="<<str2<<endl;
	while(*p1!='\0'){
		p=p1;
		while(*p==*p2&&*p&&*p2)p++,p2++;
		if(*p2=='\0')count++;
		pos=p1;p2=str2;p1++;
	}
	cout<<"the count is:"<<count<<endl;
	return 0;
}