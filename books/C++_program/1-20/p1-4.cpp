##include <iostream.h>    //����iostream.hͷ�ļ�
void main()
{
    //����ַ��������������ַ���
    char c1='A';
    cout<<'W';
    cout<<c1<<endl;
    cout<<"This is a test."<<endl;
    cout<<"------------------"<<endl;

    //������ͳ����������ͱ��ʽ
    int n=100;
    cout<<10;
    cout<<n;
    cout<<2*n<<endl;   //������ͱ��ʽ
    cout<<"------------------"<<endl;

    //��������ͳ����������ͱ��ʽ
    double pi=3.1415926,r=10.0,s=pi*r*r;
    cout<<pi<<endl;
    cout<<r;
    cout<<s;
    cout<<2*r*pi<<endl;      //��������ͱ��ʽ
    cout<<"------------------"<<endl;
    
    //һ��cout���������������
    cout<<'W'<<" "<<c1<<endl;
    cout<<"This is a test."<<endl;
    cout<<"pi="<<pi<<" r="<<r<<" s="<<s<<endl;
}
