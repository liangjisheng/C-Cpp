#include<iostream.h>
#include<stdio.h>
#include<process.h>
#include<stdlib.h>
#define MAX 5
//����ṹ����
struct student {
       int  num;
       char name[20];
       float grade;
};

//��ʾstudent�ṹ����
void show_str(student a,char *name) {
    cout<<name<<":"<<endl;
    cout<<a.num<<" "<<a.name<<" "<<a.grade;
    cout<<endl;
}

//main�������Խṹ���ݵ��ļ���д
int main(void) 
{ 
    //��������
    FILE *fp;    
    //����FILE�ṹָ����� 
    student st={1001,"ZhangBin",85.5};

    //��ʾst�ṹ����
    show_str(st,"st");

    //��d.dat�ļ�
    if ((fp=fopen("d.dat","wb+"))==NULL)
    {
       cout<<"\nCould not open the file."<<endl;
       cout<<"Exiting program."<<endl;
       exit(1);   //��������ִ��
    }

    //��fprintf()����д�ṹ���ݵ��ļ�
    fprintf(fp,"%d %s %f",st.num,st.name,st.grade);

    rewind(fp);   //�ָ���дָ���λ��

    //��fscanf()�������ļ��е����ݸ�ֵ���ṹ����ʾ
    student temp;
    fscanf(fp, "%d %s %f",&temp.num,temp.name,&temp.grade);
    show_str(temp,"temp");
    cout<<"-----------------------"<<endl;

    fclose(fp); // �ر��ļ�

    //���ṹ���ݵ������ݿ���ж�д
    if ((fp=fopen("d1.dat","wb+"))==NULL)  //��d1.dat�ļ�
    {
       cout<<"\nCould not open the file."<<endl;
       cout<<"Exiting program."<<endl;
       exit(1);   //��������ִ��
    }

    //�����ṹ���鲢��ʼ��
    int i;
    student starr[3]={{101,"WangPing",92},{102,"Li",85},{103,"LiuMin",97}};

    //��ʾ�ṹ����
    for(i=0;i<3;i++) 
        show_str(starr[i],"starr");

    //���ṹ���鵱�����ݿ�д���ļ�
    fwrite(starr, sizeof(student), 3, fp);

    rewind(fp);   //�ָ���дָ���λ��

    //�����ݿ���ļ��ж�ȡ���ݸ�ֵ���ṹ����
    student temp_arr[3];
    if (!feof(fp))    //ʹ��feof()�ж��ļ�β 
         fread(temp_arr, sizeof(student),3,fp);
    for(i=0;i<3;i++) 
        show_str(temp_arr[i],"temp_arr");
    
    fclose(fp); // �ر��ļ�
}
