#include<iostream.h>

//���幫���ṹ����
struct student {
       int  num;
       char  name[10];
       float maths;
       float physics;
       float chemistry;
       double  total;
};
 
//����ṹ���뺯��
input_Rec(struct student *p)   //����Ϊstudent���͵Ľṹָ�����
{
    cin>>p->num;
    cin>>p->name;
    cin>>p->maths;
    cin>>p->physics;
    cin>>p->chemistry;
}

//����ṹ���ݽ�������
swap_Rec(struct student *p1,struct student *p2)
{
    struct student x;

    //����������¼������
    x=*p1;
    *p1=*p2;
    *p2=x;
}

//����ṹ��ֵ
put_Rec(struct student *p)
{
    cout<<p->num<<'\t';
    cout<<p->name<<'\t';
    cout<<p->maths<<'\t';
    cout<<p->physics<<'\t';
    cout<<p->chemistry<<'\t';
    cout<<p->total<<endl;
}

//����main()����
main() 
{
    int i,j;
    // �����ṹָ������ͽṹ���� 
    struct student *p1,a[3];  

    //����3��ѧ�������ݲ������ܳɼ�
    cout<<"num\tname\tmaths\tphysics\tchemistry"<<endl;
    for (p1=a;p1<=a+2;p1++)  {
         input_Rec(p1);
         p1->total=p1->maths+p1->physics+p1->chemistry;
    }

    //��3��ѧ������������
    for (i=0;i<=2;i++)  
         for (j=i+1;j<=2;j++)
             if (a[i].total<a[j].total)
                 swap_Rec(&a[i],&a[j]);   //���������ṹ�����е�����
     cout<<"-------------------"<<endl;	  //���һ�ֽ���

     //��������Ľṹ����
    cout<<"num\tname\tmaths\tphysics\tchemistry\ttotal"<<endl;
    for (p1=a;p1<=a+2;p1++)
          put_Rec(p1);
}
