#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
    // .��ʾ���ҵ����ַ����������к��н�����
    // n*��ʾƥ���κΰ���0������n���ַ���
    // $1��ʾ�滻ʱ���õ�һ����׽�������
    // $2��ʾ�滻ʱ���õڶ�����׽�������

    const string str("<body><h1>Header</h1><p>Some text</p></body>");
    regex r("<h1>(.*)</h1><p>(.*)</p>");
    const string format("H1=$1 and P=$2");
    string result = regex_replace(str, r, format);
    cout << "Original string: '" << str << "'" << endl;
    cout << "New string     : '" << result << "'" << endl;


    // regex_replace()�㷨����һϵ�п��ƹ�����ʽ�ı�־������Ϊ����Ҫ�ķ�ʽ
    // format_default Ĭ�ϲ������滻ģʽ������ʵ�����������в�ƥ��ģʽ�����ݸ��Ƶ�����ַ���
    // format_no_copy Ĭ�ϲ������滻ģʽ������ʵ�������ǲ������в�ƥ��ģʽ�����ݸ��Ƶ�����ַ���
    // format_first_only ֻ�滻ģʽ�ĵ�һ��ʵ��
    const string str1("<body><h1>Header</h1><p>Some text</p></body>");
    regex r1("<h1>(.*)</h1><p>(.*)</p>");
    const string format1("H1=$1 and P=$2");
    string result1 = regex_replace(str1, r1, format1,
                    regex_constants::format_no_copy);
    cout << "Original string: '" << str1 << "'" << endl;
    cout << "New string     : '" << result1 << "'" << endl;

    return 0;
}
