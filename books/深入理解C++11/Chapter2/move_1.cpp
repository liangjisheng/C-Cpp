#include <iostream>
#include <utility>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string str = "hello";
    vector<string> vec_str;
    // 调用常规的拷贝构造函数，新建字符数据，拷贝数据
    vec_str.push_back(str);
    cout << "After copy, str is \"" << str << "\"" << endl;

    // 调用移动构造函数，掏空str，掏空后，最好不要使用str
    vec_str.push_back(move(str));
    cout << "After copy, str is \"" << str << "\"" << endl;
    cout << "The content of the vector are \"" << vec_str[0]
         << "\", \"" << vec_str[1] << "\"" << endl;
}
