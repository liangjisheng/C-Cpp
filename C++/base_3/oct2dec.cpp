#include"iostream"
using namespace std;

// 只能转换两位数的八进制到十进制
unsigned int oct2dec(unsigned int oct)
{ return oct/10*8+oct%10; }

int main()
{
	unsigned int oct=0;
	unsigned int dec=0;
	cout<<"Please input a octet number(Besure the number you"
		"input is begin with a '0'): "<<endl;
	cin>>oct;
	dec=oct2dec(oct);
	cout<<dec<<endl;

	system("pause");
	return 0;
}