#include<iostream.h>
#include <string.h>

//main()����
void main( void )
{
    //�����ַ�����
    char string[]="This is a test.";
    int n;

    //����ַ����ĳ���
    cout<<"string:"<<string<<endl;
    n=strlen(string);
    cout<<"The length of "<<"\""<<string<<"\": "<<n<<endl;

    //�����ַ��������䳤��
    cout<<"string:";
    cin>>string;
    n=strlen(string);
    cout<<"The length of "<<"\""<<string<<"\": "<<n<<endl;
}
