// p1-851.cpp Ϊmain()�����ļ�
#include<iostream.h>
main()
{
    int i,s=0;
    extern int fact(int x);
    for (i=2;i<=6;i=i+2)
        s+=fact(i);
    cout<<"s="<<s<<endl;
}
// p1-852.cppΪ����׳˺����ļ�
//����fact()����Ϊ�ⲿ(extern)����
extern int fact(int x)  
{
    int i,t=1;
    if(x==0) return(1);
    for(i=1;i<=x;i++)
        t*=i;
    return(t);
}
