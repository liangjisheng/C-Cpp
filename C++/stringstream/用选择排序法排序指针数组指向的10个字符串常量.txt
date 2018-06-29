#include"iostream"
#include"cstring"
using namespace std;
int main()
{
	char *p[10]={"a","d","g","r","b","c","z","h","l","j"};
	int i,j,k;char *t;
	cout<<"before sorting:"<<endl;
	for(i=0;i<10;i++)cout<<p[i]<<" ";
	cout<<endl;
	for(i=0;i<10;i++){
		k=i;
		for(j=i+1;j<10;j++)
		{if(strcmp(p[j],p[k])<0)k=j;}
		if(k!=i)t=p[k],p[k]=p[i],p[i]=t;
	}
	cout<<"sorting result:"<<endl;
	for(i=0;i<10;i++)cout<<p[i]<<" ";
	cout<<endl;
	return 0;
}