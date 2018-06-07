#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#define size 10
using namespace std;

//����ָ����Χ�����������
int getrand(int min,int max) {
    int m;
    m=(max-min);
    m=min+double(rand())/RAND_MAX*m ;
    return m;
}

//������ģ������ʵ��
typedef vector < int > IntArray;
typedef list <int> LISTINT;
typedef set<int> SET_INT;

//��main()�����в���accumulate�㷨
void main ()
{
//--------------------------------------------
//	count�㷨������ͨ����ļ���
//---------------------------------------------
    int x[size];

    cout<<"x[]:";
    for (int i=0;i<size;i++) {
		x[i]=getrand(1,3);
        cout<<x[i]<<" ";
	}
    cout<<endl;
    cout<<"count(x,x+size,2)=";
    cout<<count(x,x+size,2)<<endl;
    cout<<"count(x+2,x+8,2)=";
    cout<<count(x+2,x+8,2)<<endl;
//--------------------------------------------
//	count�㷨����vector�����ļ���
//---------------------------------------------
    //����intvector�����͵�����ii
    IntArray intvector;
    IntArray::iterator ii;

    //��intvector�����в���Ԫ��
    for (i=1; i<size; i++) {
        intvector.push_back(getrand(2,6));
    };
    //��ʾintvector�����е�Ԫ��ֵ��ͳ�ƽ��
    cout << "intvector: ";
    for (ii=intvector.begin();ii !=intvector.end();++ii) 
        cout<<(*ii)<<" ";
    cout<<endl;
    cout<<"count(intvector.begin(),intvector.end(),4)=";
    cout<<count(intvector.begin(),intvector.end(),4)<<endl;
//--------------------------------------------
//	count�㷨����list�����ļ���
//---------------------------------------------
    //����list��������͵�����
    LISTINT::iterator iL;	
    LISTINT list1; 

    //��list1���������в���Ԫ�ز���ʾ
    for (i=1; i<size; i++) {
            list1.push_front(getrand(3,5));
    };

    //��ʾlist1������Ԫ��ֵ��ͳ�ƽ��
    cout << "list1: ";
    for (iL=list1.begin();iL !=list1.end();++iL) 
        cout<<(*iL)<<" ";
    cout<<endl;
    cout<<"count(list1.begin(),list1.end(),3)=";
    cout<<count(list1.begin(),list1.end(),3)<<endl;
//--------------------------------------------
//	count�㷨����set�����ļ���
//---------------------------------------------
    //����set��������͵�����
    SET_INT set1;
    SET_INT::iterator si;

    //��set1�����в���Ԫ��
    for (i=1; i<size; i++) {
      set1.insert(getrand(1,10));
    };

    //��ʾset1������Ԫ��ֵ��ͳ�ƽ��
    cout <<"set1: ";
    for (si=set1.begin();si !=set1.end();++si) 
        cout<<(*si)<<" ";
    cout<<endl;
    cout<<"count(set1.begin(),set1.end(),5)=";
    cout<<count(set1.begin(),set1.end(),5)<<endl;
}
