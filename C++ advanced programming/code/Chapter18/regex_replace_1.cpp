#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
    // ��������ǽ���һ�������ַ�����Ȼ��ÿ�����ʱ߽��滻Ϊ
    // һ�����з���ʹĿ���ַ�����ÿһ��ֻ����һ�����ʡ������
    // ����û��ʹ���κ�ѭ��������������ַ�����
    // ���ȴ���һ��ƥ�䵥�����ʵ�������ʽ��������һ��ƥ��ʱ��
    // ƥ���ַ������滻Ϊ$1\n,����$1����ƥ��ĵ����������Ҫע��
    // ����ʹ��format_no_copy��־�����˴�Դ�ַ��������ַ���
    // ���ƿհ��ַ��������ǵ����ַ�

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
