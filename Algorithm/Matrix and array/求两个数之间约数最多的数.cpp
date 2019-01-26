// 找出两个整数之间约数最多的整数

#include"iostream"
#include"cmath"
using namespace std;
#include"algorithm"
#include"vector"
vector<int> max_div;

int num_of_div(int n) {
	int count=2,i=2;
	for(;i<=n/2;i++) {
		if(n%i==0) count++;
	}
	return count;
}

void maxnum_of_div(int a,int b,int* count) {
	int temp,max,re;
	if(a>b) 
		temp=a,a=b,b=temp;
	max=num_of_div(a);
	re=a;
	for(temp=a+1;temp<=b;temp++) {
		if( max<num_of_div(temp) )
			max=num_of_div(temp),re=temp;	
	}
	for(temp=a+1;temp<=b;temp++) {
		if( max==num_of_div(temp) )
			max_div.push_back(temp);
	}
	sort(max_div.begin(),max_div.end());
	*count=max;
}

int main() {
	cout<<"此程序用于求两个整数之间约数最多的数."<<endl;
	cout<<"input two numbers:";
	int a,b,count;
	cin>>a>>b;
	cout<<a<<"与"<<b<<"之间约数最多的数是:"<<endl;
	maxnum_of_div(a,b,&count);
	for(vector<int>::iterator it=max_div.begin();it<max_div.end();it++)
		cout<<*it<<" ";
	cout<<endl;
	cout<<"共有约数:"<<count<<"个"<<endl;

	return 0;
}