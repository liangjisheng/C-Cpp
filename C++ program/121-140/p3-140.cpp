#include<iostream.h>
#include<stdlib.h>
#define MAX 30
//main()�Ķ���
int main(void)
{
    char str[MAX],*p;

    //�Ӽ���������int��
    cout<<"Please input a int:"<<endl;
    int n;
    cin>>n;

    //��������n��ʮ����ת��Ϊ�ַ��������
    p=itoa(n,str,10);
    cout<<"str="<<str<<endl;
    cout<<"p="<<p<<endl;

    //��������n��ʮ������ת��Ϊ�ַ��������
    p=itoa(n,str,16);
    cout<<"str="<<str<<endl;
    cout<<"p="<<p<<endl;

    //�Ӽ���������double���͵�����
    cout<<"Please input a double:"<<endl;
    double x;
    cout<<"x=";
    cin>>x;

    //��������xת��Ϊ�ַ��������
    p=gcvt(x,10,str);
    cout<<"str="<<str<<endl;
    cout<<"p="<<p<<endl;
	
    return 0;
}
