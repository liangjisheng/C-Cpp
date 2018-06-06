#include <iostream>
#include <string>
using namespace std;

const string message = "test";

const string& foo(){
    return message;     // const string To const string&
}

int main()
{
    // auto ȥ�������ú�const�޶���,����f1��string����
    // ������һ������
    auto f1 = foo();

    // ���ϣ��f1��һ��const���ã��Ϳ�����ȷ��������Ϊһ��
    // һ������,�����Ϊconst
    const auto& f2 = foo();     // f2 is const string& ����
    // ��һ�з�����ʹ��decltype����û��ȥ���κ��޶���
    decltype(foo()) f3  = foo();   // f3 ��f2������һ��

    // ������Ĵ������ظ��ĵط���foo()��Ҫָ�����Σ�
    // ��foo()��һ���Ƚϸ��ӵı��ʽ�ǣ���ȽϷ���
    // C++14�н������:
    decltype(auto) f4 = foo();
    // f4Ҳ��const string& ����

    return 0;
}
