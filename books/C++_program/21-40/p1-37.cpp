#include<iostream.h>
main()
{
    //�ۼӼ������������
    double x,sum=0.0;
    while(1) {
        cout<<"x=";
        cin>>x;
        if (x<=0) break;
        sum+=x;
    }
    cout<<"sum="<<sum<<endl;
}

