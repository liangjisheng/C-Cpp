#include<iostream.h>
main()
{
    //����ʹ�ӡ��ӡ�˷��žű�
    for (int i=1;i<=9;i++) {
        cout<<i;
        for (int j=1;j<=9;j++)
            cout<<'\t'<<i<<"*"<<j<<"="<<i*j;
        cout<<endl;
    }
}

