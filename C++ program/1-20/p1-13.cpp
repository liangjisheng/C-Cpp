#include<iostream.h>
main()
{
    //����ö�����ͣ���ָ����ö��Ԫ�ص�ֵ
    enum color {  
         RED=3,
         YELLOW=6,
         BLUE=9
    };

    //����ö�ٱ���a��b,��Ϊö�ٱ���a����ֵ 
    enum color a=RED;
    color b;        //�Ϸ�����C���Բ�ͬ

    // ���ö�ٳ��� 
    cout<<"RED="<<RED<<endl;
    cout<<"YELLOW="<<YELLOW<<endl;
    cout<<"BLUE="<<BLUE<<endl;
    
    //ö�ٱ����ĸ�ֵ�����
    b=a;
    a=BLUE;
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;
    //a=100;   ����!
    //a=6      Ҳ����!

    //ö�ٱ����Ĺ�ϵ����
    b=BLUE;                    		// ö�ٱ����ĸ�ֵ����
    cout<<"a<b="<<(a<b)<<endl;
}
