#include<iostream.h>
//������Ͳ���࣬����Ϊ������Ļ���
class First {
    int val1;
public:
    First(void) {
        cout<<"The First initialized"<<endl;
    }
};
//���������࣬����Ϊ������Ļ���
class Second :public First {   
    int val2;
public:
    Second(void) {
        cout<<"The Second initialized"<<endl;
    }
};
//�������ϲ�������
class Three :public Second {
    int val3;
public:
    Three() {
        cout<<"The Three initialized"<<endl;
    }
};
//���������Ķ��󣬲��Թ��캯����ִ�����
//���������Ķ��󣬲��Թ��캯����ִ�����
main() { 
	cout<<"First f1;"<<endl;
    First f1;
    cout<<"Second s1;"<<endl;
    Second s1;
    cout<<"Three t1;"<<endl;
    Three t1;
}
