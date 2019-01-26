#include"iostream"
using namespace std;
int f(int n)
{
	if(n==1)return 1;
	else return (1+f(n-1))*2;
}
int main()
{
	int n;
	cout<<"input n:";
	cin>>n;
	cout<<"第一天共摘了"<<f(n)<<"个"<<endl;
	return 0;
}
