// 筛选法查找100以内的素数
#include"iostream"
using namespace std;

int main()
{
	int a[101],i,j,sum=0;
	for(i=0;i<101;i++)
		a[i]=1;

	//for(i=2;i<101;i++) {
	//	if(a[i]!=0) {
	//		for(j=i+i;j<101;)
	//			a[j]=0,j+=i;
	//	}
	//}

	// 上面注释的方法同样有效，充分运用了循环变量i
	for(j=4;j<101;j+=2)
		a[j]=0;
	for(j=9;j<101;j+=3)
		a[j]=0;
	for(j=25;j<101;j+=5)
		a[j]=0;
	for(j=49;j<101;j+=7)
		a[j]=0;
	

	for(j=2;j<101;j++) {
		if(a[j]!=0) {
			cout<<j<<' ';
			sum++;
		}
	}
	cout<<endl<<endl;
	cout<<"100以内总共有"<<sum<<"个素数"<<endl;

	system("pause");
	return 0;
}