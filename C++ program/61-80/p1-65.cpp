#include<iostream.h>
//add()�����Ķ��壬���з���ֵ
double add(double x,double y)
{
    double z;
    z=x+y;
    cout<<x<<"+"<<y<<"="<<z<<endl;
    return(z);
}

main()
{
    double a=0.5,b=1.0;
	
    //�Բ�ͬ������ʽ���ú���add()
    cout<<"add(1.5,2.5)="<<add(1.5,2.5)<<endl;
    cout<<"add(a,b)="<<add(a,b)<<endl;
    cout<<"add(2*a,a+b)="<<add(2*a,a+b)<<endl;
    cout<<"----------------------"<<endl;

    //�Ա��ʽ��ʽ���ú���add()
    double c=2*add(a,b);
    cout<<"c="<<c<<endl;
    cout<<"----------------------"<<endl;

    //�����ʽ��ʽ���ú���add()
    add(2*a,b);
    cout<<"----------------------"<<endl;
 
    //���������Ͳ������ú���add()
    int n=1,m=2;
    cout<<"add("<<n<<","<<m<<")="<<add(n,m)<<endl;
}
