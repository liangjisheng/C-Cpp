#include<iostream.h>
main()
{
    //������ά���鼰���� 
    int a[2][3],i,j;
    
    //�Ӽ�����Ϊ����a��ֵ
     for (i=0;i<2;i++) 
         for (j=0;j<3;j++) 
         {
            cout<<"a["<<i<<"]["<<j<<"]=";
            cin>>a[i][j];
          }

    //��ʾ����a
     for (i=0;i<2;i++) { 
         for (j=0;j<3;j++) 
         {
            cout<<a[i][j]<<"  ";
         }
        cout<<endl;
    }

    //�ҳ�����������Ԫ�ؼ����±�
    int h,l,Max=a[0][0];
     for (i=0;i<2;i++) {  
         for (j=0;j<3;j++) 
         {
            if (Max<a[i][j]) {
                Max=a[i][j];
                h=i;
                l=j;
            }
         }
    }
     cout<<"Max:"<<"a["<<h<<"]["<<l<<"]="<<a[h][l]<<endl;
}
