#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 15
using namespace std;

//��ʾ����
void put_array(int x[],int size) {
    for(int i=0;i<size;i++)
        cout<<x[i]<<" ";
	cout<<endl;
}

//����ָ����Χ�����������
int getrand(int min,int max) {
	int m;
	m=(max-min);
    m=min+double(rand())/RAND_MAX*m ;
	return m;
}
//��main()�����в���max_element()�� min_element()�㷨
void main ()
{
    //��������������
    int i;
    int x[ARRAY_SIZE];

    //��1��100���������ʼ�����飬����ʾ
    srand( (unsigned)time( NULL ) );
    for (i=0;i<ARRAY_SIZE;i++) {
        x[i]=getrand(1,100);
    }
    cout<<"x[]:";
    put_array(x,ARRAY_SIZE);

    //������xʹ��max_element()�㷨������ʾ
    int *pMax=max_element(x,x+ARRAY_SIZE);
    cout<<"pMax    ="<<pMax<<endl;
    cout<<"Location="<<(pMax-x)<<endl;
    cout<<"*pMax   ="<<(*pMax)<<endl;

    //������xʹ��min_element()�㷨������ʾ
    int *pMin=min_element(x,x+ARRAY_SIZE);
    cout<<"pMin    ="<<pMin<<endl;
    cout<<"Location="<<(pMin-x)<<endl;
    cout<<"*pMin   ="<<(*pMin)<<endl;
}
