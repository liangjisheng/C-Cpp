#include <iostream>
#include <iostream>
#include <numeric>
#include <vector>
#include <list>
#include <set>

using namespace std;

//������ģ��������ʵ��
typedef vector < int > IntArray;
typedef list <int> LISTINT;
typedef set<int> SET_INT;
int add(int a, int b) {
   return a+b;
}
//��main()�����в���accumulate�㷨
void main ()
{
//--------------------------------------------
//	accumulate�㷨������ͨ����ļ���
//---------------------------------------------
    int x[]={1,3,5,7,9};

    cout<<"x[]:";
    for (int i=0;i<5;i++) 
        cout<<x[i]<<" ";
    cout<<endl;
    cout<<"accumulate(x,x+5,0)=";
    cout<<accumulate(x,x+5,0)<<endl;
	int val=100;
	cout<<"val="<<val<<endl;
    cout<<"accumulate(x,x+5,val)=";
    cout<<accumulate(x,x+5,val)<<endl;
//--------------------------------------------
//	accumulate�㷨����vector�����ļ���
//---------------------------------------------
    //����intvector�����͵�����ii
    IntArray intvector;
    IntArray::iterator ii;

    //��intvector�����в���Ԫ��
    for (i=1; i<=5; i++) {
        intvector.push_back(i);
    };

    //��ʾintvector�����е�Ԫ��ֵ���ۼӽ��
    cout << "intvector: "<<endl;
    for (ii=intvector.begin();ii !=intvector.end();++ii) 
        cout<<(*ii)<<" ";
    cout<<endl;
    cout<<"accumulate(intvector.begin(),intvector.end(),0)=";
    cout<<accumulate(intvector.begin(),intvector.end(),0)<<endl;
//--------------------------------------------
//	accumulate�㷨����list�����ļ���
//---------------------------------------------
    //����list��������͵�����
    LISTINT::iterator iL;	
    LISTINT list1; 

    //��list1���������в���Ԫ�ز���ʾ
    list1.push_front(1);
    list1.push_front(3);
    list1.push_front(5);
    list1.push_back(2);
    list1.push_back(6);

    //��ʾlist1������Ԫ��ֵ���ۼӽ��
    cout << "list1: "<<endl;
    for (iL=list1.begin();iL !=list1.end();++iL) 
        cout<<(*iL)<<" ";
    cout<<endl;
    cout<<"accumulate(list1.begin(),list1.end(),0)=";
    cout<<accumulate(list1.begin(),list1.end(),0)<<endl;
//--------------------------------------------
//	accumulate�㷨����set�����ļ���
//---------------------------------------------
    //����set��������͵�����
    SET_INT set1;
    SET_INT::iterator si;

    //��set1�����в���Ԫ��
    set1.insert(5);
    set1.insert(20);
    set1.insert(10);
    set1.insert(15);
    set1.insert(25);

    //��ʾset1������Ԫ��ֵ���ۼӽ��
    cout <<"set1: "<<endl;
    for (si=set1.begin();si !=set1.end();++si) 
        cout<<(*si)<<" ";
    cout<<endl;
    cout<<"accumulate(set1.begin(),set1.end(),0)=";
    cout<<accumulate(set1.begin(),set1.end(),0)<<endl;
    cout<<"accumulate(set1.begin(),set1.end(),100)=";
    cout<<accumulate(set1.begin(),set1.end(),100)<<endl;
}
