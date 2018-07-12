将一个真分数分解成如下形式：7/8=1/2+1/3+1/24
#include"iostream"
using namespace std;
int EgyptianFraction(int a,int b,int D[20])
{
	int n=0,j,u,c;
	j=b;
	for(;;){
		c=b/a+1;
		if(c>100000000||c<0)return 0;
		if(c==b)c++;
		D[++n]=c;
		a=a*c-b;b=b*c;
		for(u=2;u<=a;u++)
			while(a%u==0&&b%u==0)
				a=a/u,b=b/u;
		if(a==1&&b!=j)
		{D[++n]=b;break;}
	}
	return n;
}
int main()
{
	int a,b,n,i,D[20];
	cout<<"请输入分子和分母:";
	cin>>a>>b;
	n=EgyptianFraction(a,b,D);
	if(n>0){
		cout<<a<<"/"<<b<<"=1/"<<D[1];
		for(i=2;i<=n;i++)cout<<"+1/"<<D[i];
		cout<<endl;
	}
	return 0;
}