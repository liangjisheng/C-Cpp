#include<iostream.h>
main()
{
	//��������
    int i,j;
    float t,a[5];

    //�Ӽ�����Ϊ���鸳ֵ
    for (i=0;i<=4;i++)
    {
       cout<<"a["<<i<<"]=";
       cin>>a[i];
    }

    //�����鰴�Ӵ�С˳������
    for (i=0;i<=3;i++)
        for (j=i+1;j<=4;j++)
            if (a[i]<=a[j])
            {
               t=a[i];
               a[i]=a[j];
               a[j]=t;
            }

    //��ʾ������
    for (i=0;i<=4;i++)
       cout<<a[i]<<" ";
}
