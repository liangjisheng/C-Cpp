#include<iostream.h>
main()
{
    //������Ϊlist�ĵݹ�ṹ  
    struct list {
          char         name[10];
          int          sex;
          int          age;
          list         *next;   //��ԱnextΪָ��������ṹ��ָ��
    };

    //ʹ�õݹ�ṹ����
    list L1={"WeiPing",1,35.5,NULL};
    cout<<"L1:"<<endl;
    cout<<"name\t"<<L1.name<<endl;
    cout<<"sex\t"<<L1.sex<<endl;
    cout<<"age\t"<<L1.age<<endl;
    cout<<"next\t"<<L1.next<<endl;
}
