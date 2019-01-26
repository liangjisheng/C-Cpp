#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
    // [\\w]+,w��ʾ�����ַ���+��ʾһ�������ַ���
    // ��������ʽ����һ����������
    regex reg("[\\w]+");

    while(true)
    {
        cout << "Enter a string to split (q = quit):";
        string str;
        if(!getline(cin, str) || str == "q")
            break;

        // regex_iterator��β��������ͨ����stl������ͬ��
        // һ������£���ҪΪĳ���ض�������ָ��β������
        // ��regex_iterator��ֻ��һ��endֵ��ֻҪͨ��Ĭ��
        // ���캯�������Ϳ��Ի�����β������������ʽ��
        // ��ʼ��endֵ
        const sregex_iterator end;

        // sregex_iterator�������е�ƥ�䡣ͨ��������sregex_iterator
        // ���Եõ�һ��smatch���󡣷����������ĵ�һ��Ԫ��[0]�õ�
        // ƥ����ַ���
        for(sregex_iterator iter(str.begin(), str.end(), reg);
            iter != end; ++iter)
            {
                cout << "\"" << (*iter)[0] << "\"" << endl;
            }
    }

    return 0;
}
