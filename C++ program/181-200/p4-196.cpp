#include <iostream>
#include <algorithm>
#include <vector>
#define ARRAY_SIZE 10
using namespace std;

//������ģ������ʵ��
typedef vector < int > IntArray;

//��ʾ����
void put_array(int x[],int size) {
    for(int i=0;i<size;i++)
        cout<<x[i]<<" ";
}

//��ʾvector�����е�Ԫ��
void put_vector(IntArray v)
{
    IntArray::iterator theIterator;

    for (theIterator=v.begin();theIterator!=v.end();++theIterator){
        cout<<(*theIterator)<<" ";
    }
}

//��main()�����в���find()_end()�㷨
void main ()
{
//--------------------------------------------
//	find_end()�㷨����ͨ����Ĵ���
//---------------------------------------------
    int x[ARRAY_SIZE]={1,3,5,7,9,2,4,6,8,10};
    cout << "x[]: ";
    put_array(x,ARRAY_SIZE);
    cout<<endl;
    int y[]={5,7,9};
    cout << "y[]: ";
    put_array(y,3);
    cout<<endl;

    // find_end()�㷨����,����ʾ���ҽ��
    int *p=find_end(x,x+ARRAY_SIZE,&y[0],&y[2]);
    if (p != x + ARRAY_SIZE)  {  //�鵽
        cout << "The first element that matches :" ;
        put_array(y,3);
        cout<< " is at location in x" << p - x<< endl;
    }
    else  {           //δ�鵽                      
         cout << "The sequence does not contain any elements";
         cout<< " with value " ;
         put_array(&x[3],3);
    }

//--------------------------------------------
//	find_end()�㷨��vector�����Ĵ���
//---------------------------------------------
   //����intvector��������
    IntArray intvector;

    //��intvector�����в���Ԫ��
    for (int i=1; i<=10; i++) {
        intvector.push_back(i);
    };

    //��ʾintvector�����е�Ԫ��ֵ
    cout << "intvector: ";
    put_vector(intvector);
    cout<<endl;

    IntArray temp;
    temp.push_back(5);
    temp.push_back(6);
    temp.push_back(7);
    cout << "temp: ";
    put_vector(temp);
    cout<<endl;

    // find_end()�㷨����,����ʾ���ҽ��
    IntArray::iterator pos;
    pos=find_end(intvector.begin(),intvector.end(),temp.begin(),temp.end());

    if (pos != intvector.end())  {  //�鵽
        cout << "The first element that matches ";
        put_vector(temp);
        cout<< " is at location in intvector " <<pos - intvector.begin()<< endl;
    }
    else  {           //δ�鵽                      
         cout << "The sequence does not contain any elements";
         cout<< " with value ";
        put_vector(temp);
        cout<< endl ;
    }
}
