#include<iostream.h>
const int MAX=5;   	//�ٶ�ջ����ౣ��5������

//������Ϊstack�ľ���ջ���ܵ���
class  stack {
    //���ݳ�Ա
    double  num[MAX];   //���ջ���ݵ�����
    int  top;             //ָʾջ��λ�õı���
public:
    //��Ա����
    stack(char *name)  //���캯��
    {
        top=0; 
        cout<<"Stack "<<name<<" initialized."<<endl;
    }
    ~stack(void)   //��������
    {
        cout << "Stack destroyed." << endl;  //��ʾ��Ϣ
    }

    void push(double x)	//��ջ����
    {
        if (top==MAX){
            cout<<"Stack is full !"<<endl;
            return;
        };
        num[top]=x;
        top++;
    }
    double pop(void) 	//��ջ����
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
    double x;
    //����(����)ջ���󲢳�ʼ��
    stack a("a"),b("b");    

    //��������ѭ����push()��Ա������2,4,6,8,10������aջ
    for (x=1; x<=MAX; x++)
        a.push(2.0*x);

    //��������ѭ����pop()��Ա�������ε���aջ�е����ݲ���ʾ
	cout<<"a: ";
    for (int i=1; i<=MAX; i++)
       cout<<a.pop()<<"  ";
    cout<<endl;

    //�Ӽ�����Ϊbջ��������,����ʾ
    for(i=1;i<=MAX;i++) {

        cout<<i<<" b:";
        cin>>x;
        b.push(x);
    }
	cout<<"b: ";
    for(i=1;i<=MAX;i++) 
       cout<<b.pop()<<" ";
    cout<<endl;
}
