#include <iostream.h>
main()
{
    int a,b,c;
    int smallest;
    cout<<"a  b  c"<<endl;
    cin>>a>>b>>c;
    if (a<=b)    //����������
    {
        if (a<=c)    //�ڲ��������
           smallest=a;
        else
           smallest=c;
    }
    else
    {
       if (b<=c)    //�ڲ��������
           smallest=b;
       else
           smallest=c;
    }
    cout<<"Smallest="<<smallest<<endl;
}

