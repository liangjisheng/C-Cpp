#include<iostream.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
#include<stdlib.h>
#define MAX    3
main()  {
    //����ṹ����
    struct student {
        int num;
        char name[10];
        float grade;
    };

    //��������ͱ���
    student st[3];
    int i;
    FILE *fp1;     			    // �����ļ�ָ�����

    //��д�뷽ʽ��d.dat�ļ�
    if ((fp1=fopen("d.dat","w"))==NULL)
    {
       cout<<"\nCould not open the file."<<endl;
       cout<<"Exiting program."<<endl;
       exit(1);   //��������ִ��
    }

    //�Ӽ����϶�����,д���ļ�
    cout<<"    num    name    grade"<<endl;
    for (i=0;i<MAX;i++)  {     
        cout<<i+1<<" ";
        cin>>st[i].num;
        cin>>st[i].name;
        cin>>st[i].grade;
        fprintf(fp1,"%d %s %f\n",st[i].num,st[i].name,st[i].grade);
    }
 
    fclose(fp1);               	//�ر��ļ�

    // �Զ���ʽ��d.dat�ļ�
    if ((fp1=fopen("d.dat","r"))==NULL) 
    {
       cout<<"\nCould not open the file."<<endl;
       cout<<"Exiting program."<<endl;
       exit(1);   //��������ִ��
    }
  
    // ѭ����"��"�ļ���ȡ�ַ�,����ʾ
    student t;
    while ((fscanf(fp1, "%d %s %f",&t.num,t.name,&t.grade))!=EOF)  {
          cout<<t.num<<" ";		
          cout<<t.name<<" ";		
          cout<<t.grade<<endl;		
    }

    fclose(fp1); //�ر��ļ�
}
