#include<iostream.h>
main()
{
    //�Զ������� 
    typedef  int  ARRAY_INT[50];
    int i;
    ARRAY_INT a;    //���Զ������������������a 

    //����Ϊ����a��ֵ������ӡ  
    for (i=0;i<50;i++) {
       if (i%10==0)       //ÿ10������һ���� 
         cout<<endl;
       a[i]=i;
       cout<<a[i]<<"\t";
     }
    cout<<endl;
}
