
// ������������û�в��������ʼ�տ����Զ����ø��������������
// ���������ĵ���˳��պ��빹�캯���෴
// (1)���ñ������������
// (2)���ٱ�������ݳ�Ա���봴����˳���෴
// (3)����и��࣬���ø������������
// ���Եݹ�ʹ����Щ������������ײ�ĳ�Ա���Ǳ���һ�����١�
// ���е���������������Ϊvirtual

// ���������ɵ�Ĭ��������������virtual,���Ӧ�ö����Լ���������������
// �����ڸ�����Ӧ����ô�� 

#include <iostream>

using namespace std;

class Something{
public:
    Something() { cout << "2"; }
    ~Something() { cout << "2"; }		// should be virtual ,but will work
};

class Parent{
public:
    Parent() { cout << "1"; }
    ~Parent() { cout << "1"; } 			// BUG! make this virtual 
};

class Child : public Parent {
public:
    Child() { cout << "3"; }
    ~Child() { cout << "3"; }			// should be virtual ,but will work
private:
    Something mDataMember;
};

int main()
{
    Parent* ptr = new Child();
    delete ptr;

	system("pause");
    return 0;
}

