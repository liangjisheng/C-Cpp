#include<iostream.h>
#include <process.h>
#include<stdio.h>
#include<conio.h>
void main(void) {
    //��������
    int i;
    char ch;
    FILE *fp1;

    //��д�뷽ʽ��d.dat�ļ� 
    if ((fp1=fopen("d.dat","w"))==NULL)    {
       cout<<"\nCould not open the file."<<endl;
       cout<<"Exiting program."<<endl;
       exit(1);   //��������ִ��
    }

    //ѭ���Ӽ����϶�ȡ�ַ�,д���ļ�
    cout<<"char:";
    cin>>ch; 
    while (ch!='*') {
        fputc(ch,fp1);   //���ַ�д��fp1ָ���"��"�ļ���
        cin>>ch; 
    }
    cout<<"--------------------"<<endl;
    fclose(fp1);  //�ر��ļ�

    //�Զ���ʽ��d.dat�ļ�
    if ((fp1=fopen("d.dat","r"))==NULL) 
    {
       cout<<"\nCould not open the file."<<endl;
       cout<<"Exiting program."<<endl;
       exit(1);   //��������ִ��
    }

    //ѭ�����ļ���ȡ�ַ�,����ʾ
    while ((ch=fgetc(fp1))!=EOF)  
          cout<<ch;		
    cout<<endl<<"--------------------"<<endl;

    //���°�����ʽ��ȡ�ļ��е��ַ�������ʾ
    for (i=-1;;i--) {
        fseek(fp1,i,2);   			//�����ļ�ָ�룬ƫ����Ϊi,����ļ�β
        if ((ch=fgetc(fp1))!=EOF)
            cout<<ch;
         else
            break;
    }
    cout<<endl<<"--------------------"<<endl;

    //���¶�ȡ"��"�ļ���ż��λ���ϵ��ַ�������ӡ
    long position;
    for (i=0;;i=i+2) {
        fseek(fp1,i,0);        	//�����ļ�ָ�룬ƫ����Ϊi,����ļ�ͷ
        position=ftell(fp1);
        if ((ch=fgetc(fp1))==EOF)	 //�����ļ�β�����˳��������ӡ��ȡ���ַ�
            break;     
        else {
           cout<<position<<" :"<<ch<<endl;
        }
    }
    cout<<endl;

    fclose(fp1); //�ر��ļ�
}
