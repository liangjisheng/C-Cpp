#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
    // [\\w]+,w表示单个字符，+表示一个或多个字符，
    // 此正则表达式搜索一个或多个单词
    regex reg("[\\w]+");

    while(true)
    {
        cout << "Enter a string to split (q = quit):";
        string str;
        if(!getline(cin, str) || str == "q")
            break;

        // regex_iterator的尾迭代器与通常的stl迭代不同，
        // 一般情况下，需要为某个特定的容器指定尾迭代器
        // 但regex_iterator，只有一个end值。只要通过默认
        // 构造函数声明就可以获得这个尾迭代器，会隐式的
        // 初始化end值
        const sregex_iterator end;

        // sregex_iterator遍历所有的匹配。通过解引用sregex_iterator
        // 可以得到一个smatch对象。访问这个对象的第一个元素[0]得到
        // 匹配的字符串
        for(sregex_iterator iter(str.begin(), str.end(), reg);
            iter != end; ++iter)
            {
                cout << "\"" << (*iter)[0] << "\"" << endl;
            }
    }

    return 0;
}
