#include<iostream.h>
#include <string.h>

void main( void )
{
    //�����ַ�������ַ���ָ�����
    char string[80],*p;

    //�����ַ���
    strcpy( string, "I'll see you");
    cout<<"string:"<<string<<endl;

    //׷���ַ���
    p=strcat( string, " in the morning.");
    cout<<"String: "<<string<<endl;
    cout<<"p     : "<<p<<endl;
}
