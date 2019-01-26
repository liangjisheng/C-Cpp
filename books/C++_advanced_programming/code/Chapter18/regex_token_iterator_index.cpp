#include <iostream>
#include <string>
#include <regex>
#include <vector>

using namespace std;

int main()
{
    // ��ƥ��0����1���ַ�
    // ^n��ʾƥ���κ���n��ͷ���ַ���
    // n$��ʾƥ���κ���n��β���ַ���
    // ��������ʽ����ƥ�����ڣ�����4�����ֱ�ʾ 2017/4/6
    regex reg("^(\\d{4}) / (0?[1-9] | 1[0-2]) / (0?[1-9] | [1-2][0-9] | 3[0-1])$");

    // ͨ��vectorָ����Ҫ�����Ĳ�׽������
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
