#include <iostream.h>
main()
{
    int x,y;
    cout<<"x=";
    cin>>x;
    if (x<=0) {            //��������ִ��
       y=2*x; 
       cout<<"y="<<y;     //������
    }
    else  {              //����������ִ��
       y=x*x; 
       cout<<"y="<<y;    //������
    }
}
