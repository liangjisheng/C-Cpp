#include <stack>
#include <iostream>

using namespace std ;

typedef stack<int> STACK_INT;

void main()
{
    STACK_INT stack1;
    int i;

    //�ж�ջ�Ƿ��
    cout << "stack1.empty() returned " <<
         (stack1.empty()? "true": "false") << endl;  

    //0,2,4,6...��ջ
    for (i=0;i<10;i=i+2)
        stack1.push(i);

    //top()����
    if (!stack1.empty())                         
        cout << "stack1.top() returned " <<stack1.top() << endl;
 
    //����ջ�ĳ���
    cout<<"stack1.size(): "<<stack1.size()<<endl;
   
    //�ı�ջ����ֵ 20.
    if (!stack1.empty()) {                        
        cout << "stack1.top()=20;" << endl;
        stack1.top()=20;                         
    }

    //����ջ�����е����ݲ���ʾ
	cout<<"stack1: ";
    while (!stack1.empty()) {                   
        cout<<stack1.top()<<" ";
        stack1.pop();
    }
	cout<<endl;
}
