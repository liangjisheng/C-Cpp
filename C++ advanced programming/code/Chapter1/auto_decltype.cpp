#include <iostream>

using namespace std;

// C++11����������ͨ����β��������(trailing return type) ֧��һ������ĺ����﷨
// �������﷨����ͨ�������õĲ��࣬����ָ��ģ�庯���ķ��������Ƿǳ�����

auto func(int i) -> int
{
    return i + 2;
}


// C++14����Ҫ��������Զ��ƶϳ������ķ������ͣ�Ҫʹ��������ܣ���Ҫ��auto
// ָ��Ϊ�������ͣ�������������β��������
auto divideNumbers(double numerator,double denominator)
{
    if(denominator == 0)
    {
        // print some information
    }
    return numerator / denominator;
    // �����п����ж��return��䣬���������ǵݹ飬����һ��return�����Ƿǵݹ��
}

auto x = 123;  // x will be of type int
// auto �Խϸ��ӵ����ͻ�����ã�auto����������lambda���ʽ

// �ؼ���decltype�ѱ��ʽ��Ϊʵ�Σ�������ñ��ʽ������
int x1 = 123;
decltype(x1) y = 456;   // y will be of type int
// auto��decltype�����ƺ���û������ʲô��ֵ��������ģ����ԣ�
// auto��decltype�Ƿǳ�ǿ���

auto main() -> int
{
    cout<<func(3)<<endl;

    cout << "Helloworld!" << endl;
    return 0;
}
