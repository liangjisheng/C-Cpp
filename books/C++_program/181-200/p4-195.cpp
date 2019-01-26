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
    cout<<endl;
}

//��ʾvector�����е�Ԫ��
void put_vector(IntArray v)
{
    IntArray::iterator theIterator;

    for (theIterator=v.begin();theIterator!=v.end();++theIterator){
        cout<<(*theIterator)<<" ";
    }
    cout<<endl;
}

//��main()�����в���find()�㷨
void main ()
{
	int i,value,*p;
//--------------------------------------------
//	find()�㷨������ͨ����Ĵ���
//---------------------------------------------
    int x[ARRAY_SIZE]={1,3,5,7,9,2,4,6,8,10};
    cout << "x[]: ";
    put_array(x,ARRAY_SIZE);

    //find()�㷨����,����ʾ���ҽ��
	for(i=0;i<=2;i++) {
       cout<<"value=";
	   cin>>value;
       p=find(x,x+ARRAY_SIZE,value);

       if (p != x + ARRAY_SIZE)  {  //�鵽
          cout << "First element that matches " << value;
          cout<< " is at location " << p - x<< endl;
	   }
       else  {           //δ�鵽                      
         cout << "The sequence does not contain any elements";
         cout<< " with value " << value << endl ;
	   }

	}
//--------------------------------------------
//	find()�㷨����vector�����Ĵ���
//---------------------------------------------
    //����intvector��������
    IntArray intvector;

    //��intvector�����в���Ԫ��
    for (i=1; i<=10; i++) {
        intvector.push_back(i);
    };

    //��ʾintvector�����е�Ԫ��ֵ
    cout << "intvector: ";
    put_vector(intvector);

    //find()�㷨����,����ʾ���ҽ��
    IntArray::iterator pos;

    for (i=0;i<=2;i++) {
		cout<<"value=";
		cin>>value;
        pos=find(intvector.begin(),intvector.end(),value);
        if (pos != intvector.end())  {  //�鵽
           cout << "First element that matches " << value;
           cout<< " is at location " <<pos - intvector.begin()<< endl;
		}
        else  {           //δ�鵽                      
           cout << "The sequence does not contain any elements";
           cout<< " with value " << value << endl ;
		}
	}
}
