#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    int a;
    string Str1, Str2;
    string Input = "abc 123 bcd 456 sss 999";
   
    //ostringstream �����������и�ʽ������������Է����
	// ����������ת��Ϊstring����
    // ostringstream ֻ֧�� << ������
    ostringstream oss;
    oss << 3.14;
    oss << "  ";
    oss << 55555555;
    oss << endl;
    cout  << oss.str();
   
	//ÿ��ʹ��ǰ��գ�oss.clear() ����������ڴ�
    oss.str("");	
    oss << 3.1234234234;
    Str2 = oss.str();
    cout << Str2 << endl;
    oss.str("");
    oss << 1234567;
    Str2 = oss.str();
    cout << Str2 << endl;
   
    istringstream iss(Input);
    //iss.str("ccc 555 aaa 333");
    //��չ,iss����֧�ֶ�C�������Ĳ���������Ҳ���Խ������µĸ�ֵ
    //iss.str(Input.c_str());
    while(iss >> Str1 >> a)
        cout << Str1 << "  " << a << endl;

    stringstream ss;
    ss << Input;
    while(ss >> Str1 >> a)
        cout << Str1 << " " << a << endl;
   
    // .Str()�������ṩC�е��ַ���ͷָ�룬���������ڴ��׵�ַ
    //1. ͨ��.str()�õ�һ�ݿ���
    //eg. Str1 = iss.str(), Str1 = oss.str(), Str1 = ss.str();
    // ��Ȼ�����Ҳ�ṩC���ԵĽӿ�
    //  printf("%s", iss.str().c_str()),  printf("%s", oss.str().c_str()),  
	// printf("%s", ss.str().c_str())
    //2. >>������, iss��ss֧�ָò���
    //ss.str(""), iss.str(""), oss.str("")����ʱû�з�����������շ���

	system("pause");
    return 0;
}