#include<iostream.h>
const int MAX=5;     //�ٶ�ջ����ౣ��5������

//������Ϊstack���࣬�����ջ����
class  stack {
    //���ݳ�Ա
    float  num[MAX];  //���ջ���ݵ�����
    int  top;          //ָʾջ��λ�õı���
public:
    //��Ա����
    void init(void) { top=0; }    //��ʼ������
    void push(float x)          //��ջ����
    {
        if (top==MAX){
            cout<<"Stack is full !"<<endl;
            return;
        };
        num[top]=x;
        top++;
    }
    float pop(void)          //��ջ����
    {
        top--;
        if (top<0){
        cout<<"Stack is underflow !"<<endl;
        return 0;
        };
        return num[top];
    }
}

//������main()����������stack�ഴ��ջ���󣬲�ʹ������Щ����
main(void)
{
    //���������Ͷ���
    int i;
    float x;
    stack a,b;    //����(����)ջ����

    //���¶�ջ�����ʼ��
    a.init();
    b.init();

    //��������ѭ����push()��Ա������2,4,6,8,10������aջ����
    for (i=1; i<=MAX; i++)
        a.push(2*i);

    //��������ѭ����pop()��Ա�������ε���aջ�е����ݲ���ʾ
    for (i=1; i<=MAX; i++)
       cout<<a.pop()<<"  ";
    cout<<endl;

    //��������ѭ����push()��Ա�������������������������bջ
    cout<<"Please input five numbers."<<endl;
    for (i=1; i<=MAX; i++) {
         cin>>x;
         b.push(x);
    }
 
    //��������ѭ����pop()��Ա�������ε���bջ�е����ݲ���ʾ
    for (i=1; i<=MAX; i++)
       cout<<b.pop()<<"  ";
}
