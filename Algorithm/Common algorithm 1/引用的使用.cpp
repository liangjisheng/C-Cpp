// 使用1
#include"iostream"
using namespace std;
void swap(int &a,int &b)
{
	int t;
	t=a,a=b,b=t;
}
int main()
{
	int x=10,y=20;
	cout<<"x="<<x<<",y="<<y<<endl;
	swap(x,y);
	cout<<"x="<<x<<",y="<<y<<endl;
	return 0;
}
// 使用2
#include"iostream"
using namespace std;
double &min(double &a,double &b)
{return a>b?b:a;}
int main()
{
	double a,b;
	cout<<"input a,b:";cin>>a>>b;
	cout<<"min="<<min(a,b)<<endl;
	return 0;
}
// 使用3，将一个字符串中所以字符变成大写字符
#include"iostream"
#include"string"
using namespace std;
void strToUpper(string &s)
{
	int len=s.length(),i;
	for(i=0;i<len;i++)
	{if(s.at(i)>='a'&&s.at(i)<='z')s.at(i)-=32;}
}
int main()
{
	string str="liangjisheng";
	cout<<"before="<<str<<endl;
	strToUpper(str);
	cout<<"result="<<str<<endl;
	return 0;
}
使用4，编写函数find，返回n个元素的数组中第1个小于m的元素，若不存在，返回a[0]，在main函数中给这个元素赋值为0.
#include"iostream"
using namespace std;
int &find(int a[],int n,int m)
{
	int i;
	for(i=0;i<n;i++){
		if(a[i]<m)
		{return a[i];break;}
	}
	return a[0];
}
int main()
{
	int a[10]={4,7,9,6,8,1,3,2,5,10},m,i;
	cout<<"output a[10]:"<<endl;
	for(i=0;i<10;i++)cout<<a[i]<<",";
	cout<<endl;
	cout<<"input m:";cin>>m;
	int &f=find(a,10,m);//关键
	f=0;                //关键
	cout<<"output a[10]:"<<endl;
	for(i=0;i<10;i++)cout<<a[i]<<",";
	cout<<endl;
	return 0;
}