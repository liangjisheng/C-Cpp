#include<iostream.h>
main()
{
    //����ṹ����
    struct    books
    {
    char   title[20];
    char   author[15];
    int    pages;
    float  price;
    } ;
    
    //�����ṹ����
    struct books Zbk={"VC++ ","Zhang",295,35.5}; 
    books Wbk;  

    //�Խṹ���������
    cout<<"Zbk:"<<endl;
    cout<<Zbk.title <<endl;
    cout<<Zbk.author<<endl;
    cout<<Zbk.pages<<endl;
    cout<<Zbk.price<<endl;
    cout<<"--------------------"<<endl;

    //�Խṹ��Ա������
    Zbk.pages+=10;
    Zbk.price+=0.5;
    cout<<"Zbk.pages="<<Zbk.pages<<endl;
    cout<<"Zbk.price="<<Zbk.price<<endl;
    cout<<"--------------------"<<endl;

    //�Խṹ�������������
    cout<<"Wbk.title =";
    cin>>Wbk.title;
    cout<<"Wbk.author=";
    cin>>Wbk.author;
    cout<<"Wbk.pages=";
    cin>>Wbk.pages;
    cout<<"Wbk.price=";
    cin>>Wbk.price;
    cout<<"Wbk:"<<endl;
    cout<<Wbk.title <<endl;
    cout<<Wbk.author<<endl;
    cout<<Wbk.pages<<endl;
    cout<<Wbk.price<<endl;
    cout<<"--------------------"<<endl;

    //�ṹ����֮����໥��ֵ
    books temp;
    temp=Wbk;
    cout<<"temp:"<<endl;
    cout<<temp.title<<endl;
    cout<<temp.author<<endl;
    cout<<temp.pages<<endl;
    cout<<temp.price<<endl;
}

