#include<iostream.h>
main() {
    //��ʾ1,2,3...10
    for(int i=1;i<=10;i++)
        cout<<i<<" ";
    cout<<endl;

    //��ʾ10,9,8...1
    for(int j=10;j>=1;j--)
       cout<<j<<" ";
    cout<<endl;

    //��ʾ1,3,5...9
    for(int k=1;k<=10;k=k+2)
       cout<<k<<" ";
    cout<<endl;

    //��ʾABC...Z   
    for(char c='A';c<='Z';c++)
       cout<<c;
    cout<<endl;

    //��ʾ0,0.1,0.2...1.0
    for(float x=0;x<=1.0;x=x+0.1)
       cout<<x<<" ";
    cout<<endl;

    //��ʾ0,0.1,0.2...1.0
    for(float x1=0;x1<=1.0+0.1/2;x1=x1+0.1)
       cout<<x1<<" ";
    cout<<endl;

    //����s=1+2+3...+100
    int s=0;
    for(int n=1;n<=100;n++)
        s=s+n;
    cout<<"s="<<s<<endl;
}
