#include<iostream.h>
float x=365.5;  //����ȫ�ֱ���
main() {
    int x=1,y=2;
    double w=x+y;
    {
        double x=1.414,y=1.732,z=3.14;
        cout<<"inner:x="<<x<<endl;
        cout<<"inner:y="<<y<<endl;
        cout<<"inner:z="<<z<<endl;
        cout<<"outer:w="<<w<<endl;
        cout<<"::x="<<::x<<endl;    //����������ȫ�ֱ���
    }
    cout<<"outer:x="<<x<<endl;
    cout<<"outer:y="<<y<<endl;
    cout<<"outer:w="<<w<<endl;

    //cout<<"inner:z="<<z<<endl;��Ч
    cout<<"::x="<<::x<<endl;    //����������ȫ�ֱ���
}
