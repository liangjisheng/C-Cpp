#include<iostream.h>
//����
class First {
    int val1;
protected:
    void SetVal1(int v) {
        val1=v;
    }
public:
    show_First(void) {
        cout<<"val1="<<val1<<endl;
    }
};
//������
class Second:public First {   
    int val2;
protected:
    void SetVal2(int v) {
        SetVal1(v);  //ʹ��First ����ı�����Ա
        val2=v;
    }
public:
    show_Second(void) {
        show_First();
        cout<<"val2="<<val2<<endl;
    }
};
//������
class Third:public Second {   
    int val3;
public:
    void SetVal3(int n) {
         SetVal1(n);  //ʹ��First ����ı�����Ա
         SetVal2(n);  //ʹ��Second����ı�����Ա
         val3=n;
    }
    show_Third(void) {
        show_Second();
        cout<<"val3="<<val3<<endl;
    }
};
//main()�����Ķ���
main(void)
{
    First f1;
    //f1.SetVal1(1);   ���ɷ���

    Second s1;
    //s1.SetVal1(1);   ���ɷ���
    //s1.SetVal2(2);   ���ɷ���

    Third  t1;
    //t1.SetVal1(1);   ���ɷ���
    //t1.SetVal2(2);   ���ɷ���
    t1.SetVal3(10);

	//��ʾt1���������
	cout<<"t1.show_Third();"<<endl;
    t1.show_Third();
    cout<<"t1.show_Second();"<<endl;
    t1.show_Second();
    cout<<"t1.show_First();"<<endl;
    t1.show_First();
}
