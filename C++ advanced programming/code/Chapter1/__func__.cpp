#include <iostream>

using namespace std;

// ÿ����������һ��Ԥ����ľֲ�����__func__
// static const char __func__[] = "function-name"
// ���Խ��������������־

int addNumber(int a,int b)
{
    cout<<"Entering function: "<<__func__<<endl;
    return a + b;
    // cout<<"Exit function: "<<__func__<<endl;
}

int main()
{
    cout<<"Entering function: "<<__func__<<endl;
    int sum = addNumber(3,4);
    cout<<"sum(3,4)="<<sum<<endl;
    cout<<"Exit function"<<__func__<<endl;

    return 0;
}
