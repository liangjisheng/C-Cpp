#include<iostream.h>
main()
{
    int i;
    //����ṹ���� 
    struct student {
           int  num;
           char  name[10];
           float maths;
           float physics;
           float chemistry;
           double  total;
    };

     //�����ṹ����st
     student st[3];

     //�Ӽ�����Ϊ�ṹ��������ֵ 
     cout<<"    num  name     maths physics chemistry "<<endl;
     for (i=0;i<3;i++)
     {
        cout<<i+1<<"   ";
        cin>>st[i].num;
        cin>>st[i].name;
        cin>>st[i].maths;
        cin>>st[i].physics;
        cin>>st[i].chemistry;
     }

    //����ÿ��ѧ�����ܳɼ�
    for (i=0;i<3;i++)
         st[i].total=st[i].maths+st[i].physics+st[i].chemistry;

    //����ṹ�����Ԫ�ص�ֵ 
    for (i=0;i<3;i++)
    {
        cout<<"st["<<i<<"]:   ";
        cout<<st[i].num<<'\t';
        cout<<st[i].name<<'\t';
        cout<<st[i].maths<<'\t';
        cout<<st[i].physics<<'\t';
        cout<<st[i].chemistry<<'\t';
        cout<<st[i].total<<endl;
     }
}
