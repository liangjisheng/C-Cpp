#include<iostream.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
main()  {
    //��������
    FILE *fp1;
    char str[80];

    //�Ӽ�������������һ���ַ���
    cout<<"Inupt a string:";
    cin.getline(str,80);

    //��д�뷽ʽ��d.dat�ļ�
    if ((fp1=fopen("d.dat","w"))==NULL)
    {
       cout<<"\nCould not open the file."<<endl;
       cout<<"Exiting program."<<endl;
       exit(1);   //��������ִ��
    }

    // д"��"�ļ� 
    fputs(str,fp1);         
    fputs("\n",fp1); 

    fclose(fp1);               	//�ر��ļ�

    // �Զ���ʽ��d.dat�ļ�
    if ((fp1=fopen("d.dat","r"))==NULL) 
    {
       cout<<"\nCould not open the file."<<endl;
       cout<<"Exiting program."<<endl;
       exit(1);   //��������ִ��
    }

    // ѭ����"��"�ļ���ȡ�ַ�,����ʾ
    char ch;
    while ((ch=fgetc(fp1))!=EOF)  
          cout<<ch;		
    cout<<endl;
    fclose(fp1); //�ر��ļ�

}
