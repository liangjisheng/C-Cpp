#include<iostream.h>
#include <process.h>
#include <stdlib.h> 
#include <stdio.h> 
int main(void) 
{ 
    FILE *fpd,*fpw;    // ����FILE�ṹָ����� 
    unsigned char dw;
    int i=0;

    //�Զ����ƶ���ʽ��Calc.exe�ļ�
    if((fpd=fopen("C:\WINDOWS\Calc.exe", "rb"))==NULL) 
    { 
       cout<<"\nCould not open the file."<<endl;
       cout<<"Exiting program."<<endl;
       exit(1);   //��������ִ��
    } 

    // �Զ�����д��ʽ��test.exe�ļ� 
    if((fpw=fopen("test.exe", "wb+"))==NULL)
    {
       cout<<"\nCould not open the file."<<endl;
       cout<<"Exiting program."<<endl;
       exit(1);   //��������ִ��
    }

    // �������ļ���д������ÿ��ָ����д1���ֽ�
    while(!feof(fpd)) {   //ʹ��feof()�ж��ļ�β 
        fread(&dw, 1, 1, fpd);
        fwrite(&dw, 1, 1, fpw);
    }
    // �ر��ļ�
    fclose(fpd);
    fclose(fpw);

    //ִ��Calc.exe��Calc.exe�ļ�
    cout<<"1 Run C:\WINDOWS\Calc.exe"<<endl;
    system("C:\WINDOWS\Calc.exe");
    cout<<"-------------------"<<endl;
    cout<<"2 Run test.exe!"<<endl;
    system("test.exe");
}
