#include <iostream>
#include <string>
#include <regex>

using namespace std;

// ������ʽ��ץȡһ����ҳ�ϵ���������
// ��cmd������ xxx.exe < test.html

int main()
{
    string tmp, html;
    while(getline(cin, tmp))
    {
        tmp += '\n';
        html += tmp;
    }

    string pattern("http(s)?://([\\w-]+\\.)+[\\w-]+(/[\\w- ./?%&=]*)?");
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
    regex r(pattern);
    for(sregex_iterator it(html.begin(), html.end(), r), end;
        it != end; ++it)
        {
            cout << it->str() << endl;
        }

    return 0;
}
