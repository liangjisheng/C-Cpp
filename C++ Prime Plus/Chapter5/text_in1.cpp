// text_in1.cpp -- reading chars with a while loop
// 输入此字符串中的空格不会被打印出来

#include"iostream"
using namespace std;

int main()
{
	char ch;
	int count=0;
	cout<<"Enter a string,enter # to quit:";
	cin>>ch;
	while(ch!='#')
	{
		cout<<ch;
		count++;
		cin>>ch;
	}
	cout<<endl;
	cout<<count<<" characters read\n";

	return 0;
}