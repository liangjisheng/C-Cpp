#include <iostream.h>
main()     
{
    float a=3.5,b=2.1,c=0;
    cout<<"a="<<a<<"  b="<<b<<"  c="<<c<<endl;

    //������
    cout<<"a&&b="<<(a&&b)<<endl;
    cout<<"a&&c="<<(a&&c)<<endl;

    //������
    cout<<"a||b="<<(a||b)<<endl;
    cout<<"a||c="<<(a||c)<<endl;

    //������
    cout<<"!a="<<!a<<endl<<"!c="<<!c<<endl;

    //��ϵ������߼�����
    bool flag=a>=0 && a<=5;  //����a��[0,5]������
    cout<<"a=>0 && a<=5="<<flag<<endl;

    //�������㡢��ϵ������߼�����
    cout<<"a+5>2*b+2||a<b+3="<<(a+5>2*b+2||a<b+3)<<endl;
}
