#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#define ARRAY_SIZE 15
using namespace std;

//������������vector������
typedef vector<int > IntVector ;

//��ʾ����
void put_array(int x[],int size) {
    for(int i=0;i<size;i++)
        cout<<x[i]<<" ";
    cout<<endl;
}

//��ʾvector�����е�Ԫ��
void put_vector(IntVector v,char *name)
{
    IntVector::iterator theIterator;
    cout<<name<<": ";
    for (theIterator=v.begin();theIterator!=v.end();++theIterator){
        cout<<(*theIterator)<<" ";
    }
    cout<<endl;
}

//����ָ����Χ�����������
int getrand(int min,int max) {
    int m;
    m=(max-min);
    m=min+double(rand())/RAND_MAX*m ;
    return m;
}

//��main()�����в���sort()��partial_sort()�㷨
void main ()
{
    int i;
//--------------------------------------------
//	sort()��partial_sort()�㷨����ͨ���鴦��
//---------------------------------------------
    //sort()�㷨�������飬����ʾ
    int x[ARRAY_SIZE];
    for (i=0;i<ARRAY_SIZE;i++) {
        x[i]=getrand(1,20);
    }
    cout<<"x[]:";
    put_array(x,ARRAY_SIZE);
    sort(x,x+ARRAY_SIZE);
    cout<<"sort(x,x+ARRAY_SIZE):"<<endl;
    put_array(x,ARRAY_SIZE);

    //partial_sort()�㷨����������д���
    int y[ARRAY_SIZE];
    for (i=0;i<ARRAY_SIZE;i++) {
		y[i]=getrand(1,30) ;
	}
    cout<<"y[]:";
    put_array(y,ARRAY_SIZE);
    partial_sort(y+2,y+7,y+ARRAY_SIZE);
    cout<<"partial_sort(y+2,y+7,y+ARRAY_SIZE):"<<endl;
    put_array(y,ARRAY_SIZE);
//--------------------------------------------
//	sort()��partial_sort()�㷨��vector�����Ĵ���
//---------------------------------------------
	IntVector Numbers1,Numbers2;
    for(i=0;i<15;i++) {
        Numbers1.push_back(getrand(1,30));
        Numbers2.push_back(getrand(1,30));
	}
	put_vector(Numbers1,"Numbers1");
	put_vector(Numbers2,"Numbers2");

    //sort()�㷨������ʾ
    sort(Numbers1.begin(),Numbers1.end());
	cout<<"After call sort():"<<endl;
	put_vector(Numbers1,"Numbers1");

    //partial_sort()�㷨������ʾ
    partial_sort(Numbers2.begin()+2,Numbers2.begin()+7,Numbers2.end());
 	cout<<"After call partial_sort():"<<endl;
 	put_vector(Numbers2,"Numbers2");  
}
