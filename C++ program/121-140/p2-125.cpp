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
class Second:public First {   //Ĭ��Ϊprivateģʽ
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
    //����Second�ඨ��ĳ�Ա����
    s1.SetVal2(2,3);    
    cout<<"s1.show_Second():"<<endl;
    s1.show_Second();

    //����First�ඨ��ĳ�Ա����
    s1.SetVal1(10);  
    cout<<"s1.show_First():"<<endl;	
    s1.show_First(); 
}
