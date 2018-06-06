#include <iostream>
#include <string>
#include <regex>
#include <vector>

using namespace std;

int main()
{
    // ？匹配0个或1个字符
    // ^n表示匹配任何以n开头的字符串
    // n$表示匹配任何以n结尾的字符串
    // 此正则表达式用于匹配日期，年用4个数字表示 2017/4/6
    regex reg("^(\\d{4}) / (0?[1-9] | 1[0-2]) / (0?[1-9] | [1-2][0-9] | 3[0-1])$");

    // 通过vector指定需要遍历的捕捉组索引
    while(true)
    {
        cout << "Enter a data (year/month/day) (q = quit): ";
        string str;
        if(!getline(cin, str) || str == "q")
            break;

        vector<int> index{2, 3};
        const sregex_token_iterator end;
        cout << str << endl;
        for(sregex_token_iterator iter(str.begin(), str.end(), reg, index);
            iter != end; ++iter)
            {
                cout << "\"" << *iter << "\"" << endl;
            }
    }

    return 0;
}
