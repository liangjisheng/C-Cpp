#include<iostream.h>
main()
{
     int i,max,index,a[5];

    //�Ӽ�����Ϊ���鸳ֵ
     for (i=0;i<=4;i++)
     {
       cout<<"a["<<i<<"]=";
       cin>>a[i];
     }

    // ����ѭ���������飬�ҳ����ֵ��Ԫ�ؼ����±�
    max=a[0];
    for (i=0;i<=4;i++)
    {
            if (max<a[i])
            {
                max=a[i];
                index=i;
            }
        }
    cout<<"\nMax="<<max<<"  index="<<index;
}
