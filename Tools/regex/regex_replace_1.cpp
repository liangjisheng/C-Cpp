#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
    // 这个例子是接受一个输入字符串。然后将每个单词边界替换为
    // 一个换行符，使目标字符串在每一行只包含一个单词。下面的
    // 例子没有使用任何循环来处理给定的字符串。
    // 首先创建一个匹配单个单词的正则表达式。当发现一个匹配时，
    // 匹配字符串被替换为$1\n,其中$1将被匹配的单词替代。还要注意
    // 这里使用format_no_copy标志避免了从源字符串向结果字符串
    // 复制空白字符和其它非单词字符

    regex reg("([\\w]+)");
    const string format("$1\n");

    while(true)
    {
        cout << "Enter a string to split over multiple lines (q = quit): ";
        string str;
        if(!getline(cin, str) || str == "q")
            break;
        cout << regex_replace(str, reg,format,
                regex_constants::format_no_copy) << endl;
    }

    return 0;
}
