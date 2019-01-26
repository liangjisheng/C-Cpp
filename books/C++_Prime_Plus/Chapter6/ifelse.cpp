#include"iostream"
using namespace std;

int main()
{
	char ch;
	cout<<"input a string(exit for \".\"):"<<endl;
	cin.get(ch);
	while(ch!='.')
	{
		if(ch=='\n')
			cout<<ch;
		else
			cout<<++ch;
		cin.get(ch);
	}
	cout<<endl;
	return 0;
}