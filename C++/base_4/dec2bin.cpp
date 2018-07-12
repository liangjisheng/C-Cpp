#include"iostream"
using namespace std;

int main()
{
	char result[32]={0};
	int num,i=0;
	cout<<"input a number to binary:";
	cin>>num;

	while(num) {
		result[i]=num%2;
		i++;
		num/=2;
	}

	int j=i-1;
	int count=0;
	cout<<"\nbianry :"<<endl;
	for(;j>=0;j--) {
		cout<<(int)result[j];
		if((int)result[j]==1)
			count++;
	}
	cout<<endl;
	cout<<"num of 1 have:"<<count<<endl;

	system("pause");
	return 0;
}