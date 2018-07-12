#include"iostream"
using namespace std;
template<typename Item>
void Swap(Item &a,Item &b)
{
	Item temp=a;
	a=b;b=temp;
}
int main(int argc,char *argv[])
{
	int a=1,b=0;
	char ch1='z',ch2='a';
	double x=2.2,y=3.3;
	cout<<"a="<<a<<",b="<<b<<endl;
	Swap(a,b);
	cout<<"a="<<a<<",b="<<b<<endl;
	cout<<"ch1="<<ch1<<",ch2="<<ch2<<endl;
	Swap(ch1,ch2);
	cout<<"ch1="<<ch1<<",ch2="<<ch2<<endl;
	cout<<"x="<<x<<",y="<<y<<endl;
	Swap(x,y);
	cout<<"x="<<x<<",y="<<y<<endl;
	return 0;
}