#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
    regex reg("[\\w]+");
    while(true)
    {
        cout << "Enter a string to split (q = quit): ";
        string str;
        if(!getline(cin, str) || str == "q")
            break;

        // sregex_token_iterator,使用submatch默认值0，记号
        // 迭代器会自动遍历索引为0的所有捕捉组，因此可用
        // *iter替代sregex_iterator示例中的(*iter)[0].

        const sregex_token_iterator end;
        for(sregex_token_iterator iter(str.begin(), str.end(), reg);
            iter != end; ++iter)
            {
                cout << "\"" << *iter << "\"" << endl;
            }
    }

    return 0;
}
