#include"iostream"
#define n 10
using namespace std;
int main()
{
	int a[n],i,j;
	cout<<"Please input the a[10]:"<<endl;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n;i++){
		if(a[i]==0)i++;
		for(j=i+1;j<n;j++)
			if(a[j]==a[i])a[j]=0;
	}
	cout<<"Output the a[10]:"<<endl;
	for(i=0;i<n;i++)
		if(a[i]!=0)cout<<a[i]<<",";
	cout<<endl;
	return 0;
}