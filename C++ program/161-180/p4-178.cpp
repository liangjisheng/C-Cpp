#include <iostream.h>
//����ջ�ĳߴ�
const int SIZE = 100;

//���崦��ջ����ģ��ӿ�
template <class T> class stack {
    T stck[SIZE];
    int tos;
public:
    stack(void) {
        tos = 0;
        cout << "Stack Initialized." << endl;
    }
    ~stack(void) {
       cout << "Stack Destroyed." << endl;
    }
    void push(T);
    T pop(void);
};

//����ջ�ĳ�Ա����
template <class T> void stack<T>::push(T i)
{
    if(tos==SIZE)
    {
        cout << "Stack is full." << endl;
        return;
    }
    stck[tos++] = i;
}
template <class T> T stack<T>::pop(void)
{
    if(tos==0)
    {
        cout << "Stack underflow." << endl;
        return 0;
    }
    return stck[--tos];
}

//main()�����в���stack��ģ��
void main(void)
{
    //����int�������ݵ�ջ
    cout<<"stack<int> a :"<<endl;
    stack<int> a;
    a.push(1);
    a.push(2);
    cout << a.pop() << " ";
    cout << a.pop() << endl;

    //����double�������ݵ�ջ
    cout<<"stack<double> b :"<<endl;
    stack<double> b;
    b.push(99.3);
    b.push(-12.23);
    cout << b.pop() << " ";
    cout << b.pop() <<endl;

    //����char�������ݵ�ջ
    cout<<"stack<char> c :"<<endl;
    stack<char> c;
    for(int i=0; i<10; i++)
      c.push((char) 'A' + i);
    for(i=0; i<10; i++)
      cout <<c.pop();
    cout << endl;
}
