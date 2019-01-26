#include <iostream>

using namespace std;

// ��C++�У�������д��̬���������������ܼ�ʱ��̬��������ġ�
// ��ͼ��дһ����̬�����õ��Ľ������Ԥ�ڣ�����������д���
// �ľ�̬����������еľ�̬����ͬ����ʵ�����������������ķ���

class SuperStatic{
public:
    static void beStatic(){
        cout << "SuperStatic being static." << endl;
    }
};

class SubStatic : public SuperStatic {
public:
    static void beStatic() {
        cout << "SubStatic keepin it static." << endl;
    }
};

int main()
{
    SubStatic mySubStatic;
    SuperStatic& ref1 = mySubStatic;
    mySubStatic.beStatic();
    ref1.beStatic();

    SuperStatic::beStatic();
    SubStatic::beStatic();

    return 0;
}
