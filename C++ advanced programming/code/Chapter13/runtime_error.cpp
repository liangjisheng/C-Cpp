#include <iostream>
#include <stdexcept>        // for invalid_argument and runtime_error
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
using namespace std;

void readIntegerFile(const string& fileName,vector<int>& dest)
{
    ifstream istr;
    int temp;
    istr.open(fileName.c_str());
    if(istr.fail()){
        // We failed to open the file: throw an exception
        throw invalid_argument("Unable to open the file.");
    }

    // Read the integer one by one and add them to the vector
    while(istr >> temp) {       // 返回流的引用，用来判断输入是否成功
        dest.push_back(temp);
    }

    if(istr.eof()) {
        // reach the end-of-file,throw an exception
        throw runtime_error("Error reading the file.");
    }
}
// invalid_argument 和 runtime_error 没有公共默认构造函数，只有用
// 字符串做参数的构造函数。

// 如果存在未捕获的异常，会调用内建的 terminate() 函数，这个函数调用
// <cstdlib>中的abort()来终止程序，可调用set_terminate()函数设置自己
// 的terminate_handler,这个函数采用指向回调函数(既没有参数，也没有返回值)
// 的指针做参数。
// #include <exception>     // for terminate(),set_terminate(),terminate_handler

void myTerminate(){
    cout << "Uncaught exception" << endl;
    exit(1);
}

int main()
{
    string fileName = "test.txt";
    vector<int> dest;
    set_terminate(myTerminate);     // 返回旧的 terminate_handle

    try{
        readIntegerFile(fileName.c_str(),dest);
    }catch(const invalid_argument& e) {
        cerr << e.what() << endl;
    }catch (const runtime_error& e) {
        cerr << e.what() << endl;
        return 1;
    }catch (...) {
        // Handle all other exception
    }

    return 0;
}
