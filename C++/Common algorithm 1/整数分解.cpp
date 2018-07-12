整数分解
#include"iostream"
using namespace std;
int main(int argc,char *argv[])
{
	int i,n;
	cout<<"请输入要分解的整数:";
	cin>>n;
	cout<<n<<"=";
	for(i=2;i<=n/2;i++){
		while(n%i==0){
			cout<<i<<"*";
			n/=i;
		}
	}
	cout<<n<<endl;
	return 100;
}