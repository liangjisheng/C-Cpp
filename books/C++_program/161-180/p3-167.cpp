#include<iostream.h>
#include <string.h>

//main()����
void main( void )
{
    //�����ַ�����
    char string[80],*p;

    //�����ַ��������䷴ת
    cout<<"string:";
    cin>>string;
    p=strrev(string );
    cout<<"p     :"<<p<<endl;
    cout<<"string:"<<string<<endl;
}
