#include"iostream"
#define an 5
#define bn 5
#define cn 10
using namespace std;
int main()
{
	int a[an],b[bn],c[cn],i,j,k;
	cout<<"Please input a[5]:"<<endl;
	for(i=0;i<an;i++)cin>>a[i];
	cout<<"Please input b[5]:"<<endl;
	for(i=0;i<bn;i++)cin>>b[i];
	i=0;j=0;k=0;
	while(i<an&&j<bn){
		if(a[i]<b[j])c[k++]=a[i++];
		else c[k++]=b[j++];
	}
	while(i<an)c[k++]=a[i++];
	while(j<bn)c[k++]=b[j++];
	cout<<"合并后的数组为:"<<endl;
	for(k=0;k<cn;k++)
		cout<<c[k]<<",";
	cout<<endl;
	return 0;
}