#include<iostream.h>
//������ź���sgn(),�䷵��ֵΪint����
int sgn(double x)
{
    if (x>0) return(1);    //���س���1
    if (x<0) return(-1);   //���س���2
    return(0);          //���س���3
}
//main()��������
main()
{
    double x;
    int i;
    for (i=0;i<=2;i++) {
        cout<<"x=";
        cin>>x;
        cout<<"sgn("<<x<<")="<<sgn(x)<<endl;
    }
}
