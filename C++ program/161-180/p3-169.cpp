#include<iostream.h>
#include<stdio.h>
#include <string.h>

//main()����
void main( void )
{
    //��������������
    char  buffer[200], s[] = "computer", c = 'l';
    int   i = 35, j;
    float fp = 1.7320534f;

    //��ʽ�������buffer
    j  = sprintf( buffer,     "\tString:    %s\n", s );
    j += sprintf( buffer + j, "\tCharacter: %c\n", c );
    j += sprintf( buffer + j, "\tInteger:   %d\n", i );
    j += sprintf( buffer + j, "\tReal:      %f\n", fp );

    cout<<"Output:"<<endl;
    cout<<buffer;
    cout<<"character count ="<<j<<endl;
}
