#include<iostream.h>
//max()Ϊ��������
inline int max(int x,int y)   //ע��inline�ؼ���
{
    return x>y?x:y;
}

//����main()���� 
main()  
{
    int a=3,b=5,c;
    c=max(a,b);    
    cout<<"max("<<a<<","<<b<<")="<<c<<endl;
    cout<<"max("<<15<<","<<11<<")="<<max(15,11)<<endl;
}
