#include<iostream.h>
main()
{
    //�����ַ�����ͱ���
    char str[6];
    int i;

    //�Ӽ����������ַ���
    cout<<"str=";
    cin>>str; 
    cout<<str<<endl;
	
    //��������±�������ַ�ʽ��ʾ�ַ�����
    cout<<str<<endl;
    for (i=0;i<6;i++)
        cout<<str[i];
    cout<<endl;

    //�ַ����������
    for (i=5;i>=0;i--) 
         cout<<str[i];
    cout<<endl;

    //���ַ������ɴ�д��ĸ����� 
    for (i=0;i<=5;i++)
       str[i]-=32;      	//Сд��ĸת���ɴ�д��ĸ
    cout<<str<<endl;    	//��ʾ�ַ���
}
