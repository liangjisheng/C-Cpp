#include <iostream>
// ��ʼ���б���˲��������ɱ亯���ı�д
// ��ʼ���б��е�Ԫ�ض�Ӧ����ͬһ��Ԥ��������
#include <initializer_list>
using namespace std;

int makeSum(initializer_list<int> lst){
    int total = 0;
    for(const auto& value : lst){
        total += value;
    }
    return total;
}

int main()
{
    int a = makeSum({1,2,3});
    int b = makeSum({10,20,30,40,50,60});
    // ���һ��Ԫ����double,���ܻᵼ�±��������߸�������
    int c = makeSum({1,2,1.2});
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    return 0;
}
