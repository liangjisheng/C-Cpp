
// const ���κ����Ĳ����ͷ���ֵ

#include <iostream>
#include <stdlib.h>

using std::cout;
using std::endl;

void disp1(const int &ri)
{
    cout << ri << endl;
}

// ��ֵ���õ��β�����Ϊ��������Ȼ�﷨��û��ʲô���󣬵���û�ж���
// ʵ�ü�ֵ����Ϊ�β�i�Ƿ��ں������ڸı䣬����Ӱ��ʵ�ε�ֵ
void disp2(const int i)
{
    cout << i << endl;
}

// ������������ͨ���ݶ���������ʱ����const���κ�������ֵ��û�ж��
// �ļ�ֵ����ʱ�����ķ���ֵ��һ������ֵ�������Ͳ��ܹ��ı���ֵ
const int disp3(const int &ri)
{
    cout << ri << endl;
    return ri;
}

// �����޸ķ������õı����ö����ֵ
int & disp4(int &ri)
{
    cout << ri << endl;
    return ri;
}

// �����������ֵΪ���ã���const���η���ֵ������ֹ�����ö�����޸�
const int &disp5(const int &ri)
{
    cout << ri << endl;
    return ri;
}


int main()
{
    int n = 5;
    disp1(n);
    disp2(n);
    disp3(n);
    disp4(n) = 6;
    disp5(n);           // ��������Ϊconst int& ���Բ��ܸ�ֵ

    system("pause");
    return 0;
}
