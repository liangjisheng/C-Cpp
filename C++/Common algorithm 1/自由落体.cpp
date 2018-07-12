//一球从100米高度自由落下，每次落地后反跳回原高度的一半；再落下，求它在
//第10次落地时，共经过多少米？第10次反弹多高？
#include"iostream"
using namespace std;
int main(int argc,char *argv[])
{
	double height=100.0,sum=0.0;
	int n=10,i;
	for(i=1;i<=n;i++){
		cout<<"第"<<i<<"次高度为:"<<height<<endl;
		sum+=height;
		height/=2;
	}
	cout<<"共经过"<<sum<<"米"<<endl;
	return 0;
}