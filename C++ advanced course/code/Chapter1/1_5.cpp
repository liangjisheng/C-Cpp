
// �ܶ�����ȣ�Ϊ�˱��ͬһ�����壬���Խ�const���ڲ�ͬ��λ�ã�
// ����ĳЩ����£�constֻ�ܷ����ض���λ�ã���������ͻ���ȫ��һ��
// const ��϶���ָ�������

#include <iostream>
#include <stdlib.h>

using std::cout;
using std::endl;

int main()
{
    // �������������������ָ���ǲ�һ����
    // p1����ָ�볣��������ָ��ı���������int const*(ָ�����ͳ�����ָ��)
    // p2Ҳ����ָ�볣��������ָ��ı�����ָ�볣��(int* const����ָ�����͵�ָ�볣��)
    // ����p1��p2�ĸ�ֵʱ�н�����
    int const **p1;
    int* const *p2;
    int i = 5;
    int j = 6;
    const int * ptr1 = &i;  // int to const int
    int * const ptr2 = &j;  // int* to const int*

    p1 = &ptr1;
    p2 = &ptr2;
    // p1 = &ptr2;              // error
    // p2 = &ptr1;              // error

    cout << **p1 << endl;
    cout << **p2 << endl;

    system("pause");
    return 0;
}
