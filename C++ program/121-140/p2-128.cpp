#include<iostream.h>
//������Ͳ����First������Ϊ������Ļ���
class First {
    int val1;
public:
    First() {
        cout<<"The First initialized"<<endl;
    }
    ~First() {
        cout<<"The First destroyed"<<endl;
    }
};
//����������Second������Ϊ������Ļ���
class Second :public First {   //Ĭ��Ϊprivateģʽ
    int val2;
public:
    Second() {
        cout<<"The Second initialized"<<endl;
    }
    ~Second() {
        cout<<"The Second destroyed"<<endl;
    }
};
//�������ϲ�������Three
class Three :public Second {
    int val3;
public:
    Three() {
        cout<<"The Three initialized"<<endl;
    }
    ~Three() {
        cout<<"The Three destroyed"<<endl;
    }
};
//main()�����в��Թ��캯��������������ִ�����
main() { 
    Three t1;
    cout<<"---- Use the t1----"<<endl;
}
