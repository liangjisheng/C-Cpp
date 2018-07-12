#include"iostream"
#include"string"

int main()
{
	using std::cout;
	using std::cin;
	using std::string;

	int num,temp;
	cout<<"input a num:";
	cin>>num;
	temp=num;
	string str;
	char ch;
	while(temp>0) {
		int i=temp%10;
		ch='0';
		ch=ch+i;	// num 最后一位的ASCII码值
		str+=(char)ch;
		temp/=10;
	}
	cout<<"num:"<<num<<std::endl;
	cout<<"str:";
	for(int i=str.size()-1;i>=0;i--) 
		cout<<str[i];
	cout<<std::endl;

	return 0;
}