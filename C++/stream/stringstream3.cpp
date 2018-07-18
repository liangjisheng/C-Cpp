#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    int a;
    string Str1, Str2;
    string Input = "abc 123 bcd 456 sss 999";
   
    //ostringstream 对象用来进行格式化的输出，可以方便的
	// 将各种类型转换为string类型
    // ostringstream 只支持 << 操作符
    ostringstream oss;
    oss << 3.14;
    oss << "  ";
    oss << 55555555;
    oss << endl;
    cout  << oss.str();
   
	//每次使用前清空，oss.clear() 并不能清空内存
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
    //扩展,iss对象支持对C语言流的操作，所以也可以进行如下的赋值
    //iss.str(Input.c_str());
    while(iss >> Str1 >> a)
        cout << Str1 << "  " << a << endl;

    stringstream ss;
    ss << Input;
    while(ss >> Str1 >> a)
        cout << Str1 << " " << a << endl;
   
    // .Str()函数，提供C中的字符串头指针，或者匿名内存首地址
    //1. 通过.str()得到一份拷贝
    //eg. Str1 = iss.str(), Str1 = oss.str(), Str1 = ss.str();
    // 显然，这个也提供C语言的接口
    //  printf("%s", iss.str().c_str()),  printf("%s", oss.str().c_str()),  
	// printf("%s", ss.str().c_str())
    //2. >>操作符, iss和ss支持该操作
    //ss.str(""), iss.str(""), oss.str("")，暂时没有发现其它的清空方法

	system("pause");
    return 0;
}