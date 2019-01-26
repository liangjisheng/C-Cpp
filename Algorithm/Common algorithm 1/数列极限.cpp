//编写一个函数，输入n为偶数时，调用函数求1/2+1/4+...+1/n,当输入n为奇数时，调用函数
//1/1+1/3+...+1/n(利用指针函数)
//不管是奇数数列还是偶数数列，数列是没有极限的
#include"iostream"
using namespace std;
double qi(int n)
{
	int i=1;
	double sum=0;
	while(i<=n){
		sum+=1.0/i;
		i+=2;
	}
	return sum;
}

double ou(int n)
{
	int i=2;
	double sum=0;
	while(i<=n){
		sum+=1.0/i;
		i+=2;
	}
	return sum;
}

int main(int argc,char *argv[])
{
	int n;
	cout<<"input a numbers:";
	cin>>n;
	if(n%2==0)
		cout<<"The result is:"<<ou(n)<<endl;
	else 
		cout<<"The result is:"<<qi(n)<<endl;
	return 0;
}