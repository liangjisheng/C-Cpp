// truncate.cpp -- using get() to truncate input line,if necessary
#include"iostream"
const int LIM=20;
inline void eatline() { while(std::cin.get()!='\n')continue; }

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	char name[LIM];
	char title[LIM];
	cout<<"Enter your name: ";
	cin.get(name,LIM);
	if(cin.peek()!='\n')	// 获取下一个字符，但不抽取
		cout<<"Sorry,we only have enough room for "
		<<name<<endl;
	eatline();
	cout<<"Dear "<<name<<",enter your title:\n";
	cin.get(title,LIM);
	if(cin.peek()!='\n')
		cout<<"We were forced to truncate your title.\n";
	eatline();
	cout<<"Name: "<<name<<"\nTitle: "<<title<<endl;

	return 0;
}