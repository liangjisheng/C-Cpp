#include<iostream.h>
#define size 5
main()
{
    //��������
    int i,j;
    float t,a[size];

    //�Ӽ�����Ϊ���鸳ֵ
    for (i=0;i<size;i++)
    {
       cout<<"a["<<i<<"]=";
       cin>>a[i];
    }

    //�����鰴��С����˳������
    for (i=0;i<size-1;i++)
        for (j=i+1;j<size;j++)
            if (a[i]>a[j])
            {
               t=a[i];
               a[i]=a[j];
               a[j]=t;
            }

    //��ʾ������
    for (i=0;i<size;i++)
       cout<<a[i]<<" ";
    cout<<endl;

    //����Ҫ���ҵ�����
    int value;
    int found;   //�ҵ�Ϊ1������Ϊ0
    int	low,high,mid;   
    for (i=1;i<=3;i++) {
        cout<<"value=";
        cin>>value;
	
        //���ַ���������a
        found=0;
        low=0;
        high=size-1;
        while(low<=high)
        {	
            mid=(high+low)/2;
            if (a[mid]==value)
            {
            found=1;
            break;
            }
            if (a[mid]<value)
                low=mid+1;
            else
                high=mid-1;
        }
        if (found)
            cout<<"The valu found at:a["<<mid<<"]="<<a[mid]<<endl;
        else
            cout<<"The "<<value<<" is not found!"<<endl;
    }
}
