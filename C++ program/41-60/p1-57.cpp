#include<iostream.h>
main()
{
    //����date�ṹ
    struct date
    {
       int year;
       int month;
       int day;
    };

    //����baby�ṹ
    struct baby {
        int    num;
        float   weight;
        date   birthday;   // dateΪ�ṹ���� 
    }; 
	
    //����baby�ṹ��������ʼ��
    baby b1={10001,10,{2002,12,25}};

    //������baby�ṹ����b1�����á�
    cout<<"b1.num="<<b1.num<<endl;
    cout<<"b1.weight="<<b1.weight<<endl;
    cout<<"b1.birthday.year="<<b1.birthday.year<<endl;
    cout<<"b1.birthday.month="<<b1.birthday.month<<endl;
    cout<<"b1.birthday.day="<<b1.birthday.day<<endl;
    cout<<"--------------------------"<<endl;

    //����baby�ṹ����temp,�����и�ֵ����
    baby temp;
    temp=b1;
    cout<<"temp.num="<<temp.num<<endl;
    cout<<"temp.weight="<<temp.weight<<endl;
    cout<<"temp.birthday.year="<<temp.birthday.year<<endl;
    cout<<"temp.birthday.month="<<temp.birthday.month<<endl;
    cout<<"temp.birthday.day="<<temp.birthday.day<<endl;
}
