#include<iostream.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
main()  {
    //��������
    int i=0;
    char p[100];   			// �������뻺���� 
    FILE *fp1;     			// �����ļ�ָ�����

    //��д�뷽ʽ��d.dat�ļ�
    if ((fp1=fopen("d.dat","w"))==NULL)
    {
       cout<<"\nCould not open the file."<<endl;
       cout<<"Exiting program."<<endl;
       exit(1);   //��������ִ��
    }

    // д�ļ����� 
    for (i=1;;i++)  {            //������ѭ��
        cout<<i<<" string:";
        cin>>p;         	      //�Ӽ�������������
        if (stricmp(p,"end")) {	  //���������ַ���Ϊend�������ѭ��
            fputs(p,fp1);         //д���ļ�����
            fputs("\n",fp1); 
        }
        else
            break;                //�˳�ѭ��
    }
 
    fclose(fp1);               	//�ر��ļ�

    // �Զ���ʽ��d.dat�ļ�
    if ((fp1=fopen("d.dat","r"))==NULL) 
    {
       cout<<"\nCould not open the file."<<endl;
       cout<<"Exiting program."<<endl;
       exit(1);   //��������ִ��
    }

    // ѭ�����ļ���ȡ�ַ�,����ʾ
    while (fgets(p,100,fp1)!=NULL)  
          cout<<p;		
     fclose(fp1); //�ر��ļ�
}
