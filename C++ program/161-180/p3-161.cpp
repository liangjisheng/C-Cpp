#include<iostream.h>
#include <string.h>

void main( void )
{
    //�����ַ����������ַ�����
    char string[80] = "Fill the string with something";
    cout<<"string:"<<string<<endl;
    cout<<"strcpy:"<<endl;
    char *p=strcpy(string,"abc");
    cout<<"p     :"<<p<<endl;
    cout<<"string:"<<string<<endl;
    char str[80];
    cout<<"str:";
    cin>>str;
    p=strcpy(string,str);
    cout<<"p     :"<<p<<endl;
    cout<<"string:"<<string<<endl;

    //����ǰ5���ַ���string��
    cout<<"str:";
    cin>>str;
    cout<<"strncpy:"<<endl;
    p=strncpy(string,str,strlen(str));
    cout<<"p     :"<<p<<endl;
    cout<<"string:"<<string<<endl; 
}
