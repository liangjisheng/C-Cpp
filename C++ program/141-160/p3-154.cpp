#include<iostream.h>
#include<stdlib.h>  
#include<malloc.h>
int main(void)
{
    //����ṹ����
    struct student {
       int num;
       char name[20];
       float grade;
    };

    //�����ṹָ�����
    struct student *sp; 
    //����������ڴ���
    int size=sizeof(struct student);

   //������Ҫ�Ĵ洢�ռ䲢ǿ������ת��
   sp=(struct student*)malloc(size);

    //Ϊ�ṹ������������
    cout<<"nmu:";
    cin>>(sp->num);
    cout<<"name:";
    cin>>(sp->name);
    cout<<"grade:";
    cin>>(sp->grade);

    //����ṹ���������
    cout<<"num:"<<(sp->num)<<endl;
    cout<<"name:"<<(sp->name)<<endl;
    cout<<"grade:"<<(sp->grade);
   
    //�ͷ��ڴ�
    free(sp);
}
