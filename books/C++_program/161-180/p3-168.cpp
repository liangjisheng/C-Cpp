#include<iostream.h>
#include <string.h>

char string[80];
char seps[]   = " ,\t\n";
char *token;

void main( void )
{
    //�Ӽ����������������
    for (int i=1;i<3;i++) {
        cout<<"Please input a sentence:"<<endl;
        //��������
        cin.getline(string,80);             
        cout<<"Tokens:"<<endl;
        //�״η����ַ���
        token = strtok( string, seps );		
        while( token != NULL )              //���������ж�
        {
            cout<<token<<endl;
            //�´η����ַ���
            token = strtok( NULL, seps );   
        }
    }
}
