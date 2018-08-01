#include <iostream>
#include <string>
using namespace std;

int main()
{
    // string1 will be a const char*
    auto string1 = "hello,world";

    // string2 will be an std::string
    auto string2 = "hello,world";

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
    int i = stoi(s);    // i will be 1234


    // string str = "hello,"world"; // Error!
    string str = "hello,\"world";
    // 对于原始字符串字面量，就不需要转义引号了
    string str1 = R"(hello,"world)";

    // 普通字符串不可以跨越多行代码
    // string str2 = "Line 1
    // Line 2 with \t";
    // 原始字符串字面量可以跨越多行代码
    string str2 = R"(Line 1
                     Line2 with\t)";

    return 0;
}






