#include<iostream.h>
//����First
class First {
    int val1;
public:
    SetVal1(int v) {
        val1=v;
    }
    void show_First(void) {
        cout<<"val1="<<val1<<endl;
    }
};
//������Second
class Second:private First {   //Ĭ��Ϊprivateģʽ
    int val2;
public:
    void SetVal2(int v1,int v2) {
        SetVal1(v1);     //�ɼ����Ϸ�
        val2=v2;
    }
    void show_Second(void) {
    // cout<<"val1="<<val1<<endl; ���ܷ���First˽�г�Ա
        show_First();
        cout<<"val2="<<val2<<endl;
    }
};
main() {
    Second s1;
    //s1.SetVal1(1);    //���ɼ����Ƿ�
    s1.SetVal2(2,3);    //�Ϸ�
    //s1.show_First();  //���ɼ����Ƿ�
    s1.show_Second();
}
