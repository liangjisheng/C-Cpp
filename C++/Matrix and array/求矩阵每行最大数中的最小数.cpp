#include"iostream"
#define m 4
#define n 4
using namespace std;
void main()
{
	int a[m][n],i,j,b[m];
	int t;
	for(i=0;i<m;i++)
		b[i]=0;
	cout<<"Please input the a[m][n]:"<<endl;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			cin>>a[i][j];
	for(i=0;i<m;i++){
		t=a[i][0];
		for(j=1;j<n;j++)
		{if(a[i][j]>t)t=a[i][j];}
		b[i]=t;
	}
	t=b[0];
	for(i=1;i<m;i++)
	{if(b[i]<t)t=b[i];}
	cout<<"每行最大数中的最小数为:"<<t<<endl;
}