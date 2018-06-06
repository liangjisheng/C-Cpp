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

        // sregex_token_iterator,ʹ��submatchĬ��ֵ0���Ǻ�
        // ���������Զ���������Ϊ0�����в�׽�飬��˿���
        // *iter���sregex_iteratorʾ���е�(*iter)[0].

        const sregex_token_iterator end;
        for(sregex_token_iterator iter(str.begin(), str.end(), reg);
            iter != end; ++iter)
            {
                cout << "\"" << *iter << "\"" << endl;
            }
    }

    return 0;
}
