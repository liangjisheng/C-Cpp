#include<iostream.h>
#include <string.h>

//�ַ������뺯��
void str_input(char *p1,char *p2)
{
    cout<<"string1:";
    cin>>p1;
    cout<<"string2:";
    cin>>p2;
}

//��ʾstrcmp()�����ıȽϽ��
void strcmp_put(char *p1,char *p2)
{
    cout<<"strcmp():"<<endl;
    int result=strcmp(p1,p2);
    if (result>0)
        cout<<p1<<" greater than "<<p2<<endl;
    if (result<0)
        cout<<p1<<" less than "<<p2<<endl;
    if (result==0)
        cout<<p1<<" identical to "<<p2<<endl;
}

//��ʾstricmp()�����ıȽϽ��
void stricmp_put(char *p1,char *p2)
{
    cout<<"stricmp():"<<endl;
    int result=stricmp(p1,p2);
    if (result>0)
        cout<<p1<<" greater than "<<p2<<endl;
    if (result<0)
        cout<<p1<<" less than "<<p2<<endl;
    if (result==0)
        cout<<p1<<" identical to "<<p2<<endl;
}

//��ʾstrncmp()�����ıȽϽ��
void strncmp_put(char *p1,char *p2,size_t count )
{
    cout<<"strncmp():"<<endl;
    int result=strncmp(p1,p2,count);
    if (result>0)
        cout<<p1<<" greater than "<<p2<<endl;
    if (result<0)
        cout<<p1<<" less than "<<p2<<endl;
    if (result==0)
        cout<<p1<<" identical to "<<p2<<endl;
}

//main()����
void main( void )
{
    //�����ַ�����
    char str1[80],str2[80],p;
    int i;

    //���Բ��Ը��ַ����ȽϺ���
    for(i=1;i<=3;i++) {
        str_input(str1,str2);
        strcmp_put(str1,str2);
        stricmp_put(str1,str2);
        strncmp_put(str1,str2,3);
        cout<<"----------------------"<<endl;
    }
}
