#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	istringstream iss;
	string istr1,istr2,istr3;
	int a;
	
	iss.str("I love Ziyu");
	iss>>istr1>>istr2>>istr3;
	cout<<istr1<<" "<<istr2<<" "<<istr3<<endl;
	
	iss.clear();
	iss.str("1534");
	iss>>a;
	cout<<a<<endl;
	//��C����ת��
	printf("%d\n",a);
	
	ostringstream oss;
	string ostr1,ostr2,ostr3;
	string ostr;
	string strFromInt;
	string strFromDouble;
	
	//����ַ���
	ostr1="My ";
	ostr2="Name's ";
	ostr3="Steve";
	oss<<ostr1;
	oss<<ostr2;
	oss<<ostr3;
	cout<<oss.str()<<endl;
	ostr=oss.str(); 
	cout<<ostr<<endl;
	//int ת��Ϊstring
	oss.str("");
	oss<<23412;
	strFromInt=oss.str();
    cout<<strFromInt<<endl;
	//double ת��Ϊstring
	oss.str("");
	oss<<1.2345;
	strFromDouble=oss.str();
	cout<<strFromDouble<<endl;
	
	//��string�͸���char�͡��ؼ���c_str�����ķ���ֵ��const char*�ģ�
	// ����ֱ�Ӹ�ֵ��char*,���븳��const char*
	const char *I=strFromInt.c_str();
	const char *D=strFromDouble.c_str();
	printf("%s,%s\n",I,D);

	system("pause");
	return 0;
}