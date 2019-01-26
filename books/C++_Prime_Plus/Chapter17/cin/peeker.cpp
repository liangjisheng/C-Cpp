// peeker.cpp -- some istream methods
// peek() 获取下一个将要读取的字符
// putback(ch) 将ch插入到输入字符串中

#include"iostream"
#include"cstdlib"

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	char ch;
	while(cin.get(ch)) {
		if(ch!='#')
			cout<<ch;
		else
		{ cin.putback(ch); break; }
	}

	if(!cin.eof()) {
		cin.get(ch);
		cout<<endl<<ch<<" is next input character.\n";
	}
	else {
		cout<<"End of file reached.\n";
		exit(0);
	}

	while(cin.peek()!='#') {
		cin.get(ch);
		cout<<ch;
	}
	if(!cin.eof()) {
		cin.get(ch);
		cout<<endl<<ch<<" is next input character.\n";
	}
	else 
		cout<<"End of file reached.\n";

	return 0;
}