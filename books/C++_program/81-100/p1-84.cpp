#include <iostream.h>
//ʹ�þ�̬�����ļ��������� 
count1() 
{
    //������̬����i�����ó�ֵΪ0��i��count()�оֲ��ɼ�
    static int i=0; 
    return(++i);
}
//ʹ�þֲ������ļ���������  
count2() 
{
    int i=0; 
    return(++i);
}
//��main()�����е���count()����
main()  
{
    int i;

    //����count1()10��
    cout<<"count1():"<<endl;
    for (i=1;i<=12;i++)
         cout<<count1()<<"  ";
    cout<<endl;

    //����count2()10��
    cout<<"count2():"<<endl;
    for (i=1;i<=12;i++)
         cout<<count2()<<"  ";
    cout<<endl;
}
