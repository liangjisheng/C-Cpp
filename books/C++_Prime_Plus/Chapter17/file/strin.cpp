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
	while(instr>>word) // ��ʽ�����룬ÿ�ζ�ȡһ�����ʣ�
		cout<<word<<endl;

	system("pause");
	return 0;
}