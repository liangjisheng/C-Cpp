#include<iostream.h>
#include <string.h>

//main()����
void main( void )
{
    //�����ַ�����
    char ch,string[80],*p;
    int n;

    //�����ַ�����Ҫ���ҵ��ַ�
    cout<<"Test strchr():"<<endl;
    cout<<"string:";
    cin>>string;
    cout<<"ch    :";
    cin>>ch;

    //��string�в���ch�е��ַ�����ʾ
    p=strchr(string,ch);
    cout<<"p    :"<<p<<endl;

    //�����ַ�����Ҫ���ҵ��ַ���������
    char substr[80];
    cout<<"Test strstr():"<<endl;
    cout<<"substr:";
    cin>>substr;

    //��string�в���substr�е��ַ�������ʾ
    p=strstr(string,substr);
    cout<<"p    :"<<p<<endl;
}
