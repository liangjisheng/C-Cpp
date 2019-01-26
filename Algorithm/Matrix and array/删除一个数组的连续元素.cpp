#include"iostream"
#define size 10
using namespace std;
//main
int main()
{
	int a[size],i;
	cout<<"Please input the data:"<<endl;
	for(i=0;i<size;i++)
		cin>>a[i];
	int pos,num;
	cout<<"Please input the position and num:";
	cin>>pos>>num;
	for(i=0;i<num;i++){
		a[i+pos-1]=0;
	}
	cout<<"Output the deleted data:"<<endl;
	for(i=0;i<size;i++)
		if(a[i]!=0)cout<<a[i]<<",";
	cout<<endl;
	return 0;
}