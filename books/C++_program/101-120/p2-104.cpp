#include<iostream.h>
main()
{
    //����һ����Ϊstudent����
    class student {
          int num;
          char *name;
          float grade;
    public:
         //���幹�캯��
        student(int n,char *p,float g): num(n),name(p),grade(g){}
        display(void) {
              cout<<num<<" ,"<<name<<","<<grade<<endl;
          }
    }; 

    student a(1001,"Liming",95),b(1002,"ZhangHua",96.5);   //�������󣬲���ʼ��
    //student c;  ����û�ṩ����

    a.display();            //��ʾ����a�е�����
    b.display();            //��ʾ����b�е�����
}
