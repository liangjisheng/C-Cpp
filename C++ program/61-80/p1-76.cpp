#include<iostream.h>
main()  
{
    //����ԭ������
    int fact(int x);
    int n,sn;

    //���δӼ���������3�����������ݼ������ǵĽ׳�
    for (int i=1;i<=3;i++)
    {
        cout<<i<<"   n=";
        cin>>n;
        sn=fact(n);
        cout<<n<<"!="<<sn<<endl;
    }
}

//�����ǲ��õݹ鷽�������fact()����
int fact(int x)
{
   if (x==0) return(1);
      return(x*fact(x-1));  //�˴��ֵ�����������
}
