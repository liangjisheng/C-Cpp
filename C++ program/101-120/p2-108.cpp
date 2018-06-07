#include<iostream.h>
#define MAX 5
//����stack��ӿ�
class stack{
    int num[MAX];
    int top;
public:
     stack(char *name);   //���캯��ԭ��
    ~stack(void);         //��������ԭ��
    void push(int n);
    int pop(void);
};
//main()��������stack��
main(void)
{
    int i,n;
    //��������
    stack a("a"),b("b");    

    //��������ѭ����push()��Ա������2,4,6,8,10������aջ
    for (i=1; i<=MAX; i++)
        a.push(2*i);

    //��������ѭ����pop()��Ա�������ε���aջ�е����ݣ�����ʾ
	cout<<"a: ";
    for (i=1; i<=MAX; i++)
       cout<<a.pop()<<"  ";
    cout<<endl;

    //�Ӽ�����Ϊbջ��������,����ʾ
    for(i=1;i<=MAX;i++) {
        cout<<i<<" b:";
        cin>>n;
        b.push(n);
    }
	cout<<"b: ";
    for(i=1;i<=MAX;i++) 
       cout<<b.pop()<<" ";
    cout<<endl;

    return 0;
}
//-------------------------
//   stack��Ա�����Ķ���
//-------------------------
//���幹�캯��
stack::stack(char *name)
{
    top=0;
    cout << "Stack "<<name<<" initialized." << endl;
}
//������������
stack::~stack(void)
{
    cout << "stack destroyed." << endl;  //��ʾ��Ϣ
}
//��ջ��Ա����
void stack::push(int n)
{
    if (top==MAX){
        cout<<"Stack is full !"<<endl;
        return;
    };
    num[top]=n;
    top++;
}
//��ջ��Ա����
int stack::pop(void)
{
    top--;
    if (top<0){
        cout<<"Stack is underflow !"<<endl;
        return 0;
    };
    return num[top];
}
