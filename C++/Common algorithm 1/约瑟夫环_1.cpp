//有n个人围成一圈，顺序排号。从第一个人开始报数（从1到3报数），凡报到3的人退出
//圈子，问最后留下的是原来第几号的那位。
#include"iostream"
using namespace std;
int main(int argc,char *argv[])
{
	int n,*p,i;
	cout<<"input people numbers:";
	cin>>n;
	p=new int[n];//分配内存
	for(i=0;i<n;i++)//初始化
		p[i]=i+1;
	cout<<"people numbers:";//输出
	for(i=0;i<n;i++)
		cout<<p[i]<<" ";
	cout<<endl;
	int key=1,count=n;//key是使人退出的数，本例中是3，key从1循环到3
	while(1){
		for(i=0;i<n;i++){
			if(p[i]!=0){
				if(key!=3)key++;
				else {key=1;p[i]=0;count--;}//每退出一个人，count--
			}
		}
		if(count==1)break;//剩下一个人就推出循环
	}
	for(i=0;i<n;i++)
		if(p[i]!=0)break;
	cout<<i+1<<endl;
	return 0;
}