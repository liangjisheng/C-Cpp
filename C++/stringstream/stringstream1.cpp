#include"iostream"
#include"string"
#include"sstream"
#include"algorithm"
using namespace std;

void print(int n) { cout<<n<<' '; }
class Print {
public:
	void operator() (int n) { cout<<n<<' '; }
};

int main()
{
	stringstream sstr;
	// int to string
	int a=100;
	string str;
	sstr<<a;
	sstr>>str;
	cout<<str<<endl;
	char *p;
	for(p=str.begin();p!=str.end();p++)
		cout<<*p;
	cout<<endl;

	for_each(str.begin(),str.end(),Print());	// output Error
	cout<<endl;
	for_each(str.begin(),str.end(),print);		// output Error
	cout<<endl;

	// �������ͨ��ʹ��ͬһstringstream����ʵ�ֶ������͵�ת����
	//��ע����ÿһ��ת��֮�󶼱������clear()��Ա������
	sstr.clear();
	string name="li";
	char cname[20];
	sstr<<name;
	sstr>>cname;
	cout<<cname<<endl;


	system("pause");
	return 0;
}