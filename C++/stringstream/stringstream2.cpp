#include<sstream>
#include<iostream>
#include"string"

int main()
{
	using namespace std;
	
	stringstream stream;
	int first,second;	
	stream<<"456";		//�����ַ���
	stream>>first;		//ת����int
	cout<<first<<endl;
	stream.clear();		//�ڽ��ж��ת��ǰ���������stream
	stream<<true;		//����boolֵ
	stream>>second;		//��ȡ��int
	cout<<second<<endl;

	stream.clear();
	string str="I am a boy";
	stream<<str;	// Initialize
	// stream.str(str);	// ����һ�е�Ч
	string s;
	while(stream>>s)
		cout<<s<<endl;

	system("pause");
	return 0;
}