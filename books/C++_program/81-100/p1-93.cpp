#include<iostream.h>
#include<stdio.h>
#include<process.h>
#include<stdlib.h>
#define MAX 5

//��ʾ���������
void show_array(double x[],int size) {
    for(int i=0;i<size;i++)
        cout<<x[i]<<" ";
    cout<<endl;
}

//main���������������ݵ��ļ���д
int main(void) 
{ 
    //��������
    FILE *fp;    // ����FILE�ṹָ����� 
    int i;
    double a[MAX]={1.0,1.2,1.4,1.6,1.8};

    //��ʾ����a������
    cout<<"a:";
    show_array(a,MAX);

    //��d.dat�ļ�
    if ((fp=fopen("d.dat","wb+"))==NULL)
    {
       cout<<"\nCould not open the file."<<endl;
       cout<<"Exiting program."<<endl;
       exit(1);   //��������ִ��
    }

    //�Ե���Ԫ�ض���������ļ�������
    for(i=0;i<MAX;i++) { 
        fwrite(&a[i], sizeof(double), 1, fp);
    }

    rewind(fp);   //�ָ���дָ���λ��

    //�Ե���Ԫ�ض���������ļ�������
    double b[MAX];
    for(i=0;i<MAX;i++) { 
       if (!feof(fp))    //ʹ��feof()�ж��ļ�β 
         fread(&b[i], sizeof(double), 1, fp);
       else
            break;
    }
    cout<<"b:";
    show_array(b,MAX);//��ʾ����b������

    fclose(fp); // �ر��ļ�

    //��d1.dat�ļ�
    if ((fp=fopen("d1.dat","wb+"))==NULL)
    {
       cout<<"\nCould not open the file."<<endl;
       cout<<"Exiting program."<<endl;
       exit(1);   //��������ִ��
    }

    //�����鵱�����ݿ�д���ļ�
    fwrite(&a, sizeof(double), MAX, fp);

    rewind(fp);   //�ָ���дָ���λ��

    //�����鵱�����ݿ���ļ��ж�ȡ
    double c[MAX];
    if (!feof(fp))    //ʹ��feof()�ж��ļ�β 
         fread(&c, sizeof(double),MAX,fp);
    cout<<"c:";
    show_array(c,MAX);  //��ʾ����c������
    
    fclose(fp); // �ر��ļ�
}
