#include <iostream>
#include <utility>      // for pair<>
#include <tuple>        // for tuple<>
#include <typeinfo>     // for typeid

using namespace std;

int main()
{
    // pair<>����Ա�������ֵ��ÿ��ֵ�����ض������͡�
    // ÿ��ֵ�������ڱ���ʱȷ��
    // ���û����string�������Ļ���������stringͷ�ļ�
    // ����Ҳ������ȷ�ı��룬���ӣ�����
    pair<int ,string> p1(16, "hello");
    pair<bool, float> p2(true, 1.23f);
    cout << "p1 = (" << p1.first << ", " << p1.second << ")" << endl;
    cout << "p2 = (" << p2.first << ", " << p2.second << ")" << endl;

    // tuple��pair�ķ���������洢����������ֵ��ÿ��ֵ�����Լ�
    // �ض������͡�Ҳ�Ǳ���ʱȷ��
    using myTuple = tuple<int, string, bool>;
    myTuple t1(1, "test", true);
    // std::get<i>��õ�i��Ԫ��
    cout << "t1 = (" << get<0>(t1) << ", " << get<1>(t1)
        << ", " << get<2>(t1) << ")" << endl;

    cout << "Type of get<1>(t1) = " << typeid(get<1>(t1)).name() << endl;

    return 0;
}
