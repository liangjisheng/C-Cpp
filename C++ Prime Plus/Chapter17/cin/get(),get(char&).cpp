// input.cpp -- using cin.get() cin.get(ch),
// cin.get(char * ,int ,char),cin.getline(char*,int,char)
#include"iostream"

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	int ct=0;
	char ch;
	cout<<"input a string:\n";

	// cin.get(ch);  
	// 返回cin对象,可以拼接 cin.get(ch1).get(ch2)>>ch3;
	// 到达文件尾转换为 false

	ch=cin.get();	 
	// 返回一个int值，不可以拼接 ,到达文件尾返回eof

	while(ch!='\n') {
		cout<<ch;
		ct++;
		// cin.get(ch);
		ch=cin.get();
	}
	cout<<endl;
	cout<<"Num is:"<<ct<<endl;

	system("pause");
	return 0;
}