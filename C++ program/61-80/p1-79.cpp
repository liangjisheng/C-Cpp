#include<iostream.h>
//����ṹ
struct student {
    char  name[10];
    float   grade;
};

//����student���ݵ�grade��Ա,������ʽΪ���� 
void change(student &x,float grade) 
{
    x.grade=grade;
}

//����student���ݵ�grade��Ա,������ʽΪָ�� 
void change1(student *p,float grade)      
{
    p->grade=grade;
}

//����student���͵�����,��ͨ������ʽ 
void change2(student x,float grade)      
{
    x.grade=grade;
}

//��ʾstudent���͵�����,������ʽΪ����
void show(student &x)      
{
    cout<<x.name<<"  "<<x.grade<<endl;
}

//��main()�����У����ԶԽṹ�Ĵ�����
void main()  
{
    student a={"ZhangHua",351.5};

    //��ʾa������
    show(a);

    //��change�޸ķ���,����ʾ
	cout<<"change(student &x,float grade):"<<endl;
    change(a,360);
    show(a);

    //��change1�޸ķ���,����ʾ
	cout<<"change1(student *p,float grade):"<<endl;
    change1(&a,375);
    show(a);

    //��change2�޸ķ���,����ʾ
	cout<<"change2(student x,float grade):"<<endl;
    change2(a,380.5);
    show(a);
}
