#include<iostream.h>
main()
{
    int i;
    //������Ϊstudent�ĵݹ�ṹ 
    struct  student {
           char name[10];
           int  math;
           int  computer;
           float sum;
           student *forw;    //forw��Ա��ǰָ�� 
           student *next;    //next��Ա�Ǻ�ָ��
    };

    //��student����3���ṹָ�����
    struct student *head,*tail,*temp; 

    //�����1�����ݣ������ø��ṹָ��ĳ�ֵ
    temp=new struct student;    //�����ڴ� 
    head=temp;      // ͷָ�� 
    tail=head;      // βָ�� 
    head->forw=NULL;

    //ѭ��Ϊ�����¼��������
    cout<<"\tname    Math   Computer"<<endl;
    for (i=1;;i++) {
        cout<<i<<"\t";
        cin>>temp->name;
        if (temp->name[0]!='*')
        {
            cin>>temp->math>>temp->computer;
            temp->sum=temp->math+temp->computer;
            temp->next=NULL;
            tail=temp;      //��������βָ�� 
         }
         else
         {
          // ����������������� 
            delete temp;
            tail->next=NULL;
            break;
         }
        //Ϊ��һ��ѧ�������ڴ�
        temp->next=new struct student; 
        temp->next->forw=temp;   //����ǰָ��
        temp=temp->next;         //ʹ����ָ��tempָ�����ڴ��
    }

    // ���������ݴ�ͷ��β��ӡ����
    cout<<"head------>tail:"<<endl;
    temp=head;
    while (temp!=NULL) {
           cout<<temp->name<<","<<temp->math<<",";
           cout<<temp->computer<<","<<temp->sum<<endl;
           temp=temp->next;
     }

    // ���������ݴ�β��ͷ��ӡ����
    cout<<"tail------>head:"<<endl;
    temp=tail;
    while (temp!=NULL) {
           cout<<temp->name<<","<<temp->math<<",";
           cout<<temp->computer<<","<<temp->sum<<endl;
           temp=temp->forw;
     }
}
