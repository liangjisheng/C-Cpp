#include <iostream>

using namespace std;

void DefineArray(const int n)
{
    int B[n] = {};
    cout << B[0] << endl;
}

int main()
{
    const int m = 5;
    int A[m] = {};
    cout << A[0] << endl;
    DefineArray(4);

    // ���ֳ����ǲ���Ѱַ�ģ����������������
    // int &r = 5;          // �������

    // ����ʵ������һ�������ֳ���ת��Ϊ�������Ĺ��̡�������������
    // ����һ��ֵΪ5��������������Ȼ������r��������������а�
    const int &r = 5;         // ok

    // cout << "Hello world!" << endl;
    //system("pause");
    return 0;
}
