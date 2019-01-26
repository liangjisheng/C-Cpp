#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
    // \s查找空白符，n*表示匹配任何包含0个或多个n的字符串
    regex reg(R"(\s*[,;]\s*)");

    // regex_token_iterator可用于执行字段分解(field splitting)
    // 或标记化(tokenization)任务，比C中旧式strtok()更加安全
    // 和灵活。标记化是在regex_token_iterator构造函数中通过将
    // 要遍历的捕捉组索引指定为-1触发的。
    // 在标记模式中，迭代器会遍历源字符串中不匹配
    // 正则表达式的所有子字符串，
    // 下面这段代码根据前后带有任意数量的空白字符的分隔符,和;
    // 对一个字符串进行标记化操作

    while(true)
    {
        cout << "Enter a string to split on ',' and ';' (q = quit): ";
        string str;
        const sregex_token_iterator end;
        for(sregex_token_iterator iter (str.begin(), str.end(), reg, -1);
            iter != end; ++iter)
            {
                cout << "\"" << *iter << "\"" << endl;
            }
    }

    return 0;
}
