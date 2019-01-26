#include<iostream.h>

//�������ò����ĺ���ģ��ԭ��
template <class T> void swap(T &x, T &y);

//����һ���ṹ����
struct student {
    int n;
    char name[20];
    float grade;
};

//��main()�����в���swap()����ģ��
void main(void)
{
    //��������int�ͱ����е�����
    int m=3,n=5;
    cout<<"m="<<m<<"  n="<<n<<endl;
    swap(m,n);
    cout<<"m="<<m<<"  n="<<n<<endl;
    cout<<"-------------------"<<endl;

    //��������double�ͱ����е�����
    double x=3.5,y=5.7;
    cout<<"x="<<x<<"  y="<<y<<endl;
    swap(x,y);
    cout<<"x="<<x<<"  y="<<y<<endl;
    cout<<"-------------------"<<endl;

    //��������char�ͱ����е�����
    char c1='A',c2='a';
    cout<<"c1="<<c1<<"  c2="<<c2<<endl;
    swap(c1,c2);
    cout<<"c1="<<c1<<"  c2="<<c2<<endl;
    cout<<"-------------------"<<endl;
    
    //���������ṹ�����е�����
    student s1={1001,"ZhangHua",90};
    student s2={1011,"LiWei",95.5};
    cout<<"s1:  ";
    cout<<s1.n<<"  "<<s1.name<<"  "<<s1.grade<<endl;
    cout<<"s2:  ";
    cout<<s2.n<<"  "<<s2.name<<"  "<<s2.grade<<endl;
    swap(s1,s2);
    cout<<"swap(s1,s2):"<<endl;
    cout<<"s1:  ";
    cout<<s1.n<<"  "<<s1.name<<"  "<<s1.grade<<endl;
    cout<<"s2:  ";
    cout<<s2.n<<"  "<<s2.name<<"  "<<s2.grade<<endl;
}

//������Ϊswap�ĺ���ģ�����ڽ������������е�����
template <class T> void swap(T &x, T &y)
{
    T temp;
    temp=x;
    x=y;
    y=temp;
}
