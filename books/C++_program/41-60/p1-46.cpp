#include<iostream.h>
main()
{
    //�������顢������ָ�����
    int a[2][3],i,j;
    int* ip;

    //�Ӽ�����Ϊ����a��ֵ
    for (i=0;i<2;i++)  //Ϊ����a��ֵ
        for (j=0;j<3;j++) 
        {
           cout<<"a["<<i<<"]["<<j<<"]=";
           cin>>a[i][j];
         }

    //�����±������ʾ����a
    for (i=0;i<2;i++) { 
        for (j=0;j<3;j++) 
        {
           cout<<a[i][j]<<"  ";
        }
        cout<<endl;
    }

    //����ָ�������ʾ����a
    ip=&a[0][0];	 
    for (i=0;i<2;i++) { 
         for (j=0;j<3;j++) 
         {
            cout<<"a["<<i<<"]["<<j<<"]=";
            cout<<ip<<"  ";
            cout<<*ip<<endl;
            ip++;
         }
    }
}
