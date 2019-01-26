#include"iostream"

using namespace std;

void hanoi(int n,char A,char B,char C)
{
	if(n==1)
		cout<<A<<"->"<<C<<" ";
	else
	{
		hanoi(n-1,A,C,B);
		cout<<A<<"->"<<C<<" ";
		hanoi(n-1,B,A,C);
	}
}

int main()
{
	int n;
	cout<<"input n:";
	cin>>n;
	hanoi(n,'A','B','C');
	cout<<endl;
	
	getchar();
	return 0;
}

