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
	// ����cin����,����ƴ�� cin.get(ch1).get(ch2)>>ch3;
	// �����ļ�βת��Ϊ false

	ch=cin.get();	 
	// ����һ��intֵ��������ƴ�� ,�����ļ�β����eof

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