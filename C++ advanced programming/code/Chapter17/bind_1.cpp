#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

void func(int num, const string& str)
{
    cout << "func(" << num << "," << str << ")" << endl;
}

void increment(int& value)
{
    ++value;
}

void overload(int num) {}

void overload(float f) {}

bool greaterthan100(int num)
{
    return num > 100;
}

int main()
{
    string str = "abc";
    // placeholders::_1 ������std::placeholders���ƿռ���
    // _1ָ���˵���func()ʱ��f1()�ĵ�һ������Ӧ�ó��ֵ�λ��
    // ֮�󣬾Ϳ�����һ�����Ͳ�������f1()
    auto f1 = bind(func, placeholders::_1, str);
    f1(12);

    // bind()�����������������в�����˳��
    auto f2 = bind(func, placeholders::_2, placeholders::_1);
    f2("test", 32);


    // <functional>ͷ�ļ�������std::ref()��std::cref()����������
    // �ֱ����ڰ����û���const���á�
    int index = 0;
    increment(index);
    cout << index << endl;

    // �����bind()���ã�index��ֵ�Ͳ���������Ϊ������index��һ��
    // ����������������������ð󶨵�increment()�����ĵ�һ��������
    index = 0;
    auto incr = bind(increment,index);
    incr(index);
    cout << index << endl;

    // ʹ��std::ref()����ȷ���ݶ�Ӧ�����ã������index
    index = 0;
    auto incr1 = bind(increment, ref(index));
    incr1(index);
    cout << index << endl;


    // �����غ����ǣ�������ʾ��ָ���������������е���һ��
    auto f4 = bind((void(*)(float))overload, placeholders::_1);


    // ʹ��bind()��greater_equal()�ĵڶ��������󶨵��̶�ֵ100
    vector<int> vec{1,5,20,50,101};
    auto it = find_if(vec.begin(), vec.end(),
                      bind(greater_equal<int>(), placeholders::_1, 100));
    if(it == vec.end())
        cout << "No number greater than 100." << endl;
    else
        cout << "Found a number greater than 100 is :" << *it << endl;

    // ȡ����������ν�ʽ���ķ����
    // not1(),��ʾ���������������һԪ����(������һ�������ĺ���)
    // ����������Ƕ�Ԫ����(���������������ĺ���)����ô�������not2()
    function<bool(int)> f5 = greaterthan100;
    it = find_if(vec.begin(), vec.end(), not1(f5));
    if(it == vec.end())
        cout << "All numbers is greater than 100." << endl;
    else
        cout << "Found a number less than 100 is :" << *it << endl;
    // ���Ͽ������º�����ʹ�û�ʹ�ñ��ʽ�ǳ����ӣ����龡��ʹ��lambda
    // ���ʽ�������Ƿº���

    return 0;
}
