#include<iostream.h>
#include<stdio.h>
#define size 3
//����book�ṹ����
struct book
{
    char   title[20];
    char   author[15];
    int    pages;
    float  price;
};
//book�ṹ�����뺯��
input_book(book& bk,char *name)
{
    cout<<name<<":"<<endl;
    cout<<"title:";
    cin>>bk.title;
    cout<<"author:";
    cin>>bk.author;
    cout<<"pages:";
    cin>>bk.pages;
    cout<<"price:";
    cin>>bk.price;
}
//book�ṹ���������
output_book(book& bk,char *name)
{
    cout<<name<<":  ";
    cout<<bk.title<<" ";
    cout<<bk.author<<" ";
    cout<<bk.pages<<" ";
    cout<<bk.price<<endl;
}
void main(void)
{
    //���������ͽṹ����
    int i;
    char str[20];
    book bk[size];

    //����ṹ����
    for(i=0;i<size;i++) {
        sprintf(str,"bk[%d]",i+1);
        input_book(bk[i],str);
    }

    //��ʾ�ṹ����
    for(i=0;i<size;i++) {
        sprintf(str,"bk[%d]",i+1);
        output_book(bk[i],str);
    }
}
