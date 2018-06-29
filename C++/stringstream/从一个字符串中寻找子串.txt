#include"iostream"
using namespace std;
const char *stringstr(const char *s1,const char *s2)
{
	const char *p=s1,*r=s2;
	while(*p!='\0'){
		while(*p++==*r++);
		if(*r=='\0')return p;
		r=s2;p=++s1;
	}
	return NULL;
}
int main()
{
	char s1[80]="*a*ab*abc*abcd",s2[80]="ab";
	const char *p;
	p=(char*)stringstr(s1,s2);
	if(p)cout<<p<<endl;
	return 0;
}