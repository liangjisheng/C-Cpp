#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
    // \s���ҿհ׷���n*��ʾƥ���κΰ���0������n���ַ���
    regex reg(R"(\s*[,;]\s*)");

    // regex_token_iterator������ִ���ֶηֽ�(field splitting)
    // ���ǻ�(tokenization)���񣬱�C�о�ʽstrtok()���Ӱ�ȫ
    // ������ǻ�����regex_token_iterator���캯����ͨ����
    // Ҫ�����Ĳ�׽������ָ��Ϊ-1�����ġ�
    // �ڱ��ģʽ�У������������Դ�ַ����в�ƥ��
    // ������ʽ���������ַ�����
    // ������δ������ǰ��������������Ŀհ��ַ��ķָ���,��;
    // ��һ���ַ������б�ǻ�����

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
