#include"iostream"
#include"cassert"
using namespace std;
int main()
{
	int *intptr1,i,num;
	cout<<"请输入数组的个数:";
	cin>>num;
	intptr1=new int[num];
	assert(intptr1!=0);
	cout<<"input "<<num<<" numbers:";
	for(i=0;i<num;i++)
		cin>>intptr1[i];
	cout<<"the "<<num<<" numbers:";
	for(i=0;i<num;i++)
		cout<<intptr1[i]<<" ";
	cout<<endl;
	delete []intptr1;
	intptr1=0;
	return 0;
}