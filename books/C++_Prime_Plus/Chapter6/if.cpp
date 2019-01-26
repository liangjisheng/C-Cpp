#include"iostream"
using namespace std;

int main()
{
	int space=0,count=0;
	char ch;
	cout<<"input a parament of word (exit for \".\"):"<<endl;
	cin.get(ch);
	while(ch!='.')
	{
		if(ch==' ')
			space++;
		count++;
		cin.get(ch);
	}
	cout<<"\nsapce has :"<<space<<endl;
	cout<<"count is :"<<count<<endl;
	return 0;
}