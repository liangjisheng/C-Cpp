#include <iostream.h>  //����iostream.hͷ�ļ�
main()
{
    //��������������ʼ��
    int a=010,b=10,c=0X10; 

    //��ʮ������ʽ��ʾ����
    cout<<"DEC:";
    cout<<" a="<<a;
    cout<<" b="<<b;
    cout<<" c="<<c<<endl; 
	
    //�԰˽�����ʽ��ʾ����
    cout<<"OCT:";
    cout<<oct;             //ָ���˽������
    cout<<" a="<<a;
    cout<<" b="<<b;
    cout<<" c="<<c<<endl;  
	
    //��ʮ��������ʽ��ʾ����
    cout<<"HEX:";
    cout<<hex;            //ָ��ʮ���������
    cout<<" a="<<a;
    cout<<" b="<<b;
    cout<<" c="<<c<<endl;  

    //�ˡ�ʮ��ʮ��������������㲢���
    cout<<"a+b+c=";
    cout<<dec;            //�ָ�ʮ�������
    cout<<a+b+c<<endl;

    //���԰ˡ�ʮ��ʮ����������
    cout<<"DEC:a="; cin>>a;
    cout<<"OCT:b="; cin>>b;
    cout<<"HEX:a="; cin>>c;
    cout<<"DEC:"<<dec<<endl;            //ָ��ʮ�������
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;
    cout<<"c="<<c<<endl;
}
