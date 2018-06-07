// 解决打印空格问题
// cin.get(ch) 返回cin对象

#include"iostream"
using namespace std;

int main()
{
	char ch;
	int count=0;
	cout<<"Enter a string,enter # to quit:";
	cin.get(ch);
	while(ch!='#')
	{
		cout<<ch;
		count++;
		cin.get(ch);
	}
	cout<<endl;
	cout<<count<<" characters read\n";

	return 0;
}