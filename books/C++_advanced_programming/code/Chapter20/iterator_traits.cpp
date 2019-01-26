#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

template<typename IteratorType>
void iteratorTraitsTest(IteratorType it)
{
    // һЩ�㷨��ʵ����Ҫ�������Ķ�����Ϣ�����磬Ϊ�˱�����ʱֵ
    // �㷨������Ҫ֪�����������õ�Ԫ�ص����ͣ����п���Ҫ֪��
    // ��������˫����ʵĻ���������ʵġ�
    // C++�ṩ��һ��iterator_traits����ģ�壬ͨ��Ҫʹ�õĵ�����
    // ����ʵ����iterator_traits��ģ�壬Ȼ����Է�������5��
    // typedef: value_type�� difference_type�� iterator_category
    // pointer �� reference
    // typename ˵�������������һ������
    typename std::iterator_traits<IteratorType>::value_type temp;
    temp = *it;
    cout << temp << endl;
}

int main()
{
    vector<int> v{ 5 };
    iteratorTraitsTest(v.cbegin());

    return 0;
}
