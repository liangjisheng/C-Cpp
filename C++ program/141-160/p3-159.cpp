#include<iostream.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

void main( void )
{
    struct stat buf;
    int result;

    //���c:\Windows\Calc.exe�ļ���״̬��Ϣ
    result =stat( "c:\\windows\\Calc.exe", &buf );

    //��ʾCalc.exe�ļ���״̬��Ϣ
   if( result != 0 )
       perror( "Problem getting information" );
    else
    {
        cout<<"Size of the file in bytes:"<<buf.st_size<<endl;
        cout<<"Drive number of the disk containing the file :";
        cout<<char(buf.st_dev + 'A')<<endl;
        cout<<"Time of creation of the file:"<<ctime(&buf.st_ctime);
        cout<<"Time of last access of the file:"<<ctime(&buf.st_atime);
        cout<<"Time of last modification of the file:"<<ctime(&buf.st_mtime);
   }
}
