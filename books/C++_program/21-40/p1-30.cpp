#include <iostream.h>
main()
{
    //x,y Ϊ��������cΪ�����
    int x,y,z;
    char c1;
    cin>>x>>c1>>y;   //c1

    //��·ѡ�����ѡ��ͬ���ʽ�������
    switch(c1) {
          case '+':cout<<x<<"+"<<y<<"="<<x+y<<endl;
                   break;
          case '-':cout<<x<<"-"<<y<<"="<<x-y<<endl;
                   break;
          case '*':cout<<x<<"*"<<y<<"="<<x*y<<endl;
                   break;
          case '/':cout<<x<<"/"<<y<<"="<<x/y<<endl;
                   break;
          case '%':cout<<x<<"%"<<y<<"="<<x%y<<endl;
                   break;
          default :cout<<"Wrong !"<<endl; //���������������ʱִ�б��Ӿ�
    }
}



