#include<sstream>
#include<iostream>
#include"string"

int main()
{
	using namespace std;
	
	stringstream stream;
	int first,second;	
	stream<<"456";		//插入字符串
	stream>>first;		//转换成int
	cout<<first<<endl;
	stream.clear();		//在进行多次转换前，必须清除stream
	stream<<true;		//插入bool值
	stream>>second;		//提取出int
	cout<<second<<endl;

	stream.clear();
	string str="I am a boy";
	stream<<str;	// Initialize
	// stream.str(str);	// 与上一行等效
	string s;
	while(stream>>s)
		cout<<s<<endl;

	system("pause");
	return 0;
}