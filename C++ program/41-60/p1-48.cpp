#include<iostream.h>
main()
{
    //�����ַ��������ָ�����
    char str[10];
    char *strip=str;

    //�������
    cout<<"str=";
    cin>>str;      //���ַ����������ַ���
    cout<<"str="<<str<<endl;
    cout<<"strip="<<strip<<endl;
    cout<<"strip=";
    cin>>strip;     //���ַ�ָ����������ַ���
    cout<<"str="<<str<<endl;
    cout<<"strip="<<strip<<endl;

    //����ָ������ı���ָ���ַ���������
    *(strip+2)='l';
    cout<<"str="<<str<<endl;
    cout<<"strip="<<strip<<endl;

    //��̬Ϊ�ַ���ָ����������ڴ�
    strip=new char(100);
    cout<<"strip=";
    cin>>strip; //���ַ�ָ����������ַ���
    cout<<"str="<<str<<endl;
    cout<<"strip="<<strip<<endl;
}
