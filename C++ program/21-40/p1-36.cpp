#include<iostream.h>
main()
{
    int x,sum=0;
    //������L1
L1: cout<<"x=";
    cin>>x;
    if (x==-1)
       goto L2;          //������ת����䣬ת��L2��䴦
    else
       sum+=x;
    goto L1;             //������ת����䣬ת��L1��䴦
    //������L2
L2: cout<<"sum="<<sum<<endl;
}


