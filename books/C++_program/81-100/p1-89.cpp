#include<iostream.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
#include<stdlib.h>
#define MAX    10
main()  {
    //��������
    int i,n;
    FILE *fp1;     			// �����ļ�ָ�����

    //��д�뷽ʽ��d.dat�ļ�
    if ((fp1=fopen("d.dat","w"))==NULL)
    {
       cout<<"\nCould not open the file."<<endl;
       cout<<"Exiting program."<<endl;
       exit(1);   //��������ִ��
    }

    // д�ļ����� 
    for (i=1;i<=MAX;i++)  {     
        n=rand();        //����1�����������
        putw(n,fp1);
        cout<<n<<" ";
    }
    cout<<endl<<"--------------------"<<endl;
 
    fclose(fp1);               	//�ر��ļ�

    // �Զ���ʽ��d.dat�ļ�
    if ((fp1=fopen("d.dat","r"))==NULL) 
    {
       cout<<"\nCould not open the file."<<endl;
       cout<<"Exiting program."<<endl;
       exit(1);   //��������ִ��
    }
  
    // ѭ����"��"�ļ���ȡ�ַ�,����ʾ
    while ((n=getw(fp1))!=EOF)  
          cout<<n<<" ";		

    fclose(fp1); //�ر��ļ�
}
