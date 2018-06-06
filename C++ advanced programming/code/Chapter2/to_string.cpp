#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()
{
//	int i=123;
//
//	//aastring s=to_string(134) + "abc";
//	string s = to_string(i) + "abc";
//    cout << s << endl;
//    
//    long double d = 3.14L;
//    string sd = to_string(d);
//    cout << sd << endl;
//    
//    auto str1 = "hello,world";
//    cout << str1 << endl;



	    // string1 will be a const char*
    auto string1 = "hello,world";
    cout << "string1: " << string1 << endl;
    cout << "string1 type is :" << typeid(string1).name() << endl;

    // string2 will be an std::string
    auto string2 = "hello,world";
    cout << "string2: " << string2 << endl;
    cout << "string2 type is :" << typeid(string2).name() << endl;

    // 数值转换成字符串,下列这些函数作为辅助函数放在std中
    // string to_string(int val);
    // string to_string(unsigned val);
    // string to_string(long val);
    // string to_string(unsigned long val);
    // string to_string(long long val);
    // string to_string(unsigned long long val);
    // string to_string(float val);
    // string to_string(double val);
    // string to_string(long double val);
    long double d = 3.14L;
    string sd = to_string(d);
    cout << d << endl;
    cout << sd << endl;

    // 字符串转换为数值,放在std中
    // 表示要转换的string,idx接收第一个未转换字符的索引,base表示转换过程中使用的进制
    // int stoi(const string& str,size_t* idx =0,int base =10);
    // long stol(const string& str,size_t* idx =0,int base =10);
    // unsigned long stoul(const string& str,size_t* idx =0,int base =10);
    // long long stoll(const string& str,size_t* idx =0,int base =10);
    // unsigned long long stoull(const string& str,size_t* idx =0,int base =10);
    // float stof(const string& str,size_t* idx =0);
    // double stod(const string& str,size_t* idx =0);
    // long double stold(const string& str,size_t* idx =0);
    const string s1 = "1234";
    int i = stoi(s1);    // i will be 1234
    cout << "s1 = " << s1 << endl;
    cout << "i = " << i << endl; 


    // string str = "hello,"world"; // Error!
    string str = "hello,\"world";
    cout << "str = " << str << endl;
    // 对于原始字符串字面量，就不需要转义引号了
    string str1 = R"(hello,"world)";
    cout << "str1 = " << str1 << endl;

    // 普通字符串不可以跨越多行代码
    // string str2 = "Line 1
    // Line 2 with \t";
    // 原始字符串字面量可以跨越多行代码
    string str2 = R"(Line 1
                     Line2 with\t)";
    cout << "str2 = " << str2 << endl;

	
	system("pause");
	return 0;
}



