#include <iostream.h>
main() 
{ 
    //��������
    char c;
    double x,y;

    //��������
	cout<<"++E and E++ :"<<endl;
    c='B';
    cout<<"c="<<++c<<endl;   //���c=C
    c='B';
    cout<<"c="<<c++<<endl;   //���c=B
    x=1.5;
    y=5+ ++x;               //�Ӻź�Ŀո�����
    cout<<"y="<<y<<endl;    //���y=7.5
    x=1.5;
    y=5+x++;
    cout<<"y="<<y<<endl;    //���y=6.5
    cout<<"--------------------"<<endl;

	//�����Լ�
	cout<<"--E and E-- :"<<endl;
    c='B';
    cout<<"c="<<--c<<endl;   //���c=A
    c='B';
    cout<<"c="<<c--<<endl;   //���c=B
    x=1.5;
    y=5+--x;
    cout<<"y="<<y<<endl;    //���y=5.5
    x=1.5;
    y=5+x--;
    cout<<"y="<<y<<endl;    //���y=6.5
}
