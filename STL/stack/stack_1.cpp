#include"iostream"
#include"stack"
using namespace std;
int main()
{
	stack<int>S;
	for(int i=1;i<=6;i++)
		S.push(i);
	while(!S.empty())
	{cout<<S.top()<<" ";S.pop();}
	cout<<endl;
	return 0;
}