#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//����һ��Fibonacci��������generate_n()�㷨����
int Fibonacci1(void)
{
    static int r;
    static int f1 = 0;
    static int f2 = 1;
    r = f1 + f2 ;
    f1 = f2 ;
    f2 = r ;
    return f1 ;
}
//����һ��Fibonacci��������generate()�㷨����
int Fibonacci2(void)
{
    static int r;
    static int f1 = 0;
    static int f2 = 1;
    r = f1 + f2 ;
    f1 = f2 ;
    f2 = r ;
    return f1 ;
}
//������������vector������
    typedef vector<int > IntVector ;

//��ʾvector�����е�Ԫ��
void put_vector(IntVector v,char *name)
{
    IntVector::iterator theIterator;
    cout<<name<<":"<<endl;
    for (theIterator=v.begin();theIterator!=v.end();++theIterator){
        cout<<(*theIterator)<<" ";
    }
    cout<<endl;
}

//����generate()��generate_n()�㷨
void main()
{
    const int VECTOR_SIZE = 15 ;

    //�����������
    typedef IntVector::iterator IntVectorIt ;

    //����vector��������
    IntVector Numbers1(VECTOR_SIZE),Numbers2(VECTOR_SIZE);
    int i ;

    //��ʼ��vector��������
    for(i = 0; i < VECTOR_SIZE; i++)
        Numbers1[i] = i ;
	
    //��ʾvector���������Ԫ��
    cout << "Before calling generate_n:" << endl ;
    put_vector(Numbers1,"Numbers1");

    //����generate_n�㷨��Fibonacci �����vector����
    generate_n(Numbers1.begin(), VECTOR_SIZE, Fibonacci1) ;

    //��ʾvector���������Ԫ��
    cout << "After calling generate_n:" << endl ;
    put_vector(Numbers1,"Numbers1");

    //����generate�㷨��Fibonacci �����vector����
    generate(Numbers2.begin(),Numbers2.end(), Fibonacci2) ;

    //��ʾvector���������Ԫ��
    cout << "After calling generate:" << endl ;
    put_vector(Numbers2,"Numbers2");
}
