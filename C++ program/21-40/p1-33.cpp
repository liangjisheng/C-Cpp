#include<iostream.h>
main()
{
    //����s=1+2+3...+100
    int s=0,n=1;
    while(n<=100) {
        s=s+n;
        n++;
    }
    cout<<"s="<<s<<endl;

    //�ۼӼ������������
    double x,sum=0.0;
    cout<<"x=";
    cin>>x;
    while(x!=0) {
        sum+=x;
        cout<<"x=";
        cin>>x;
    }
    cout<<"sum="<<sum<<endl;
}
