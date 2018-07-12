//分解一个偶数为两个素数之和
#include"iostream"
using namespace std;
bool isPrime(int n)
{
	int i=2;
	for(;i<=n/2;i++){
		if(n%i==0)return false;
	}
	return true;
}
int main(int argc,char *argv[])
{
	int num,i,sum=0;
	cout<<"input a number(偶数):";
	cin>>num;
	if(num==4)
		cout<<"4=2+2"<<endl;
	else{
	for(i=3;i<=num/2;i+=2){
		if(isPrime(i)&&isPrime(num-i))
			cout<<num<<"="<<i<<"+"<<num-i<<endl;
	}
	}
	return 0;
}