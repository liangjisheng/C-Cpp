#include<iostream.h>
main()
{
    int i;
    for (i=1;i<=20;i++)
   {
        if (i%3==0)   //�ܱ� 3 ���������������ؽ����´�ѭ��
            continue;
        cout<<i<<" ";
    }
    cout<<endl;
}
