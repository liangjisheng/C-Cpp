#include<iostream.h>
//����ȫ�ֱ�������ʼ��
extern int a[]={1,2,3};
extern float p=3.14;

//��show()������ʹ���ⲿ����
show()  {
    int i;
    cout<<"In show():"<<endl;
	cout<<"p="<<p<<endl;
	cout<<"a[]: ";
    for (i=0;i<=2;i++) 
        cout<<a[i]<<"  ";
    cout<<endl;
    //cout<<"y="<<y<<endl; �������
}

//�����ⲿ��������ʼ��
int y=5678;

//��main()������ʹ���ⲿ����
main()  
{
    //�����ֲ�����
    int i,p=100;

    //��ʾ��������
	cout<<"In main():"<<endl;
    cout<<"p="<<p<<endl;

    //��ʾȫ�ֱ���
    cout<<"::p="<<::p<<endl;
	cout<<"a[]: ";
    for (i=0;i<=2;i++)
        cout<<a[i]<<"  ";
    cout<<endl;
    cout<<"y="<<y<<endl;   //������ȷ��

    show();  //���ú���
}
