// strout.cpp -- incore formatting (output) �ں˸�ʽ��
#include"iostream"
#include"sstream"
#include"string"

int main()
{
	using namespace std;
	ostringstream outstr;	// manages a string stream
	string hdisk;
	cout<<"What's the name of your hard disk?";
	getline(cin,hdisk);
	int cap;
	cout<<"What's its capacity in GB? ";
	cin>>cap;
	// write formatted information to string stream
	outstr<<"The hard disk "<<hdisk<<" has s capacity of "
		<<cap<<" gigabytes.\n";
	// str()��������һ������ʼ��Ϊ�ַ������������ݵ��ַ�������
	// str()��������ö��󣬲��ܽ���Ϣд��ö���
	string result=outstr.str();	// save result;
	cout<<result<<endl;	// show contents

	ostringstream outstr1;
	char * p="lishuyu";
	int n=100;
	outstr1<<"Name: "<<p<<",scores: "<<n<<endl;
	string s=outstr1.str();
	cout<<s<<endl;

	system("pause");
	return 0;
}
