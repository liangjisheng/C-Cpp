
// ������������û�в��������ʼ�տ����Զ����ø��������������
// ���������ĵ���˳��պ��빹�캯���෴
// (1)���ñ������������
// (2)���ٱ�������ݳ�Ա���봴����˳���෴
// (3)����и��࣬���ø������������
// ���Եݹ�ʹ����Щ������������ײ�ĳ�Ա���Ǳ���һ�����١�
// ���е���������������Ϊvirtual

#include <iostream>

using namespace std;

class Something{
public:
    Something() { cout << "2"; }
    virtual ~Something() { cout << "2"; }
};

class Parent{
public:
    Parent() { cout << "1"; }
    virtual ~Parent() { cout << "1"; }
};

class Child : public Parent {
public:
    Child() { cout << "3"; }
    virtual ~Child() { cout << "3"; }
private:
    Something mDataMember;
};

int main()
{
    Child myChild;
	
	system("pause");
    return 0;
}

