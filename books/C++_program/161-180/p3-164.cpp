#include<iostream.h>
#include <string.h>

//main()����
void main( void )
{
    //�����ַ�����
    char string[80],*p;
    int i;

    //ת���ַ����е�Сд��ĸΪ��д
    cout<<"Convert a string to uppercase:"<<endl;
    cout<<"string:";
    cin>>string;
    p=strupr(string);
    cout<<"p:"<<p<<endl;
    cout<<"string:"<<string<<endl;
    cout<<"----------------------"<<endl;

    //ת���ַ����еĴ�д��ĸΪСд
    cout<<"Convert a string to lowercase:"<<endl;
    cout<<"string:";
    cin>>string;
    p=strlwr(string);
    cout<<"p:"<<p<<endl;
    cout<<"string:"<<string<<endl;
}
