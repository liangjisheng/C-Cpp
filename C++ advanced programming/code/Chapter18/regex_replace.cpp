#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
    // .表示查找单个字符，出来换行和行结束符
    // n*表示匹配任何包含0个或多个n的字符串
    // $1表示替换时引用第一个捕捉组的内容
    // $2表示替换时引用第二个捕捉组的内容

    const string str("<body><h1>Header</h1><p>Some text</p></body>");
    regex r("<h1>(.*)</h1><p>(.*)</p>");
    const string format("H1=$1 and P=$2");
    string result = regex_replace(str, r, format);
    cout << "Original string: '" << str << "'" << endl;
    cout << "New string     : '" << result << "'" << endl;


    // regex_replace()算法接受一系列控制工作方式的标志，下面为最重要的方式
    // format_default 默认操作是替换模式的所有实例，并将所有不匹配模式的内容复制到结果字符串
    // format_no_copy 默认操作是替换模式的所有实例，但是不将所有不匹配模式的内容复制到结果字符串
    // format_first_only 只替换模式的第一个实例
    const string str1("<body><h1>Header</h1><p>Some text</p></body>");
    regex r1("<h1>(.*)</h1><p>(.*)</p>");
    const string format1("H1=$1 and P=$2");
    string result1 = regex_replace(str1, r1, format1,
                    regex_constants::format_no_copy);
    cout << "Original string: '" << str1 << "'" << endl;
    cout << "New string     : '" << result1 << "'" << endl;

    return 0;
}
