// strin.cpp -- formatted reading from a char array
#include"iostream"
#include"sstream"
#include"string"

int main()
{
	using namespace std;
	string lit="It was a dark and stormy day,and "
		" the full moon glowed brilliantly. ";
	istringstream instr(lit);
	string word;
	while(instr>>word) // 格式化输入，每次读取一个单词，
		cout<<word<<endl;

	system("pause");
	return 0;
}