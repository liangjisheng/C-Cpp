#include <iostream.h>
//��������Ĭ��ֵ�ĺ���
disp(int x=1,int y=1,int z=1)
{
    cout<<"����1: "<<x<<endl;
    cout<<"����2: "<<y<<endl;
    cout<<"����3: "<<z<<endl;
    cout<<"------------------"<<endl;
}

//main()�����в��Բ�������Ĭ��ֵ�ĺ���disp()
void main()
{
    disp();
    disp(10);
    disp(10,20);
    disp(10,20,30);
    int a=1,b=2,c=3;
    disp(a,b,c);
}
