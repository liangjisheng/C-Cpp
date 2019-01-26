#include"iostream"
using namespace std;
int main(int argc,char *argv[])
{
	double sum=0;
	int i=1,j;
	//cout<<"input a numbers:";
	//cin>>n;
	for(j=1;j<=10000;j+=100){
	while(i<=j){
		sum+=1.0/i/i;
		i+=1;;
	}
	cout<<"The result is:"<<sum<<endl;
	}
	return 0;
}
//由此程序得1/(n*n)的极限是1.64493
