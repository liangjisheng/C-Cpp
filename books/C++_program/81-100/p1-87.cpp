#include<iostream.h>
#include <process.h>
#include<stdio.h>
#include<conio.h>
void main(void)  {
    //��������
    char ch;
    FILE *fp1;

    //��д�뷽ʽ��d.dat�ļ� 
    if ((fp1=fopen("d.dat","w"))==NULL)    {
       cout<<"\nCould not open the file."<<endl;
       cout<<"Exiting program."<<endl;
       exit(1);   //��������ִ��
    }

    //ѭ���Ӽ����϶�ȡ�ַ�,д��"��"�ļ�
    cout<<"char:"<<endl;
    cin>>ch; 
    while (ch!='*') {
        fputc(ch,fp1);   //���ַ�д��fp1ָ���"��"�ļ���
        cin>>ch; 
    }
    fclose(fp1);  //�ر��ļ�

    // �Զ���ʽ��d.dat�ļ�
    if ((fp1=fopen("d.dat","r"))==NULL) 
    {
       cout<<"\nCould not open the file."<<endl;
       cout<<"Exiting program."<<endl;
       exit(1);   //��������ִ��
    }

    // ѭ����"��"�ļ���ȡ�ַ�,����ʾ
    while ((ch=fgetc(fp1))!=EOF)  
          cout<<ch<<"  ";		
    cout<<endl;
    fclose(fp1); //�ر��ļ�
}
