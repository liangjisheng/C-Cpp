#include<iostream.h>
//����ṹ
struct student {
    char  name[10];
    float   grade;
};

//����student���͵����� 
void swap(student &x,student &y)      //swap�Ĳ���Ϊ���ô��ݷ�ʽ
{
    student temp;
    temp=x;
    x=y;
    y=temp;
}

//����student���͵����ã������� 
student& max(student &x,student &y)      //swap�Ĳ���Ϊ���ô��ݷ�ʽ
{
    return (x.grade>y.grade?x:y);
}

//��ʾstudent���͵����� 
void show(student &x)      //show�Ĳ���Ϊ���ô��ݷ�ʽ
{
   cout<<x.name<<"  "<<x.grade<<endl;
}
void main()  
{
    student a={"ZhangHua",351.5},b={"WangJun",385};

    //��ʾa��b������
    cout<<"a:";
    show(a);
    cout<<"b:";
    show(b);
    cout<<"------------------"<<endl;

    //����a��b������,����ʾ
    swap(a,b);    
    cout<<"a:";
show(a);
    cout<<"b:";
show(b);
    cout<<"------------------"<<endl;

    //�������ʾ�ɼ�����
    student t=max(a,b);
    cout<<"Max:";
    show(t);
}
