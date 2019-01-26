#include <iostream>
#include <algorithm>
#include <vector>

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

//��main()�����в���fill��fill_n�㷨
void main ()
{
//--------------------------------------------
//	fill��fill_n�㷨����ͨ����ļ���
//---------------------------------------------
    int x[]={1,3,5,7,9};
    cout << "x[]: ";
    put_array(x,5);
    //��������
    fill(x+1,x+3,2);
    cout << "fill(x+1,x+3,2): "<<endl;
    put_array(x,5);
	fill_n(x,3,8);
    cout << "fill_n(x,3,8): "<<endl;
    put_array(x,5);
//--------------------------------------------
//	fill��fill_n�㷨����vector�����ļ���
//---------------------------------------------
    //����intvector�����͵�����ii
    IntArray intvector;

    //��intvector�����в���Ԫ��
    for (int i=1; i<=10; i++) {
        intvector.push_back(i);
    };
    //��ʾintvector�����е�Ԫ��ֵ��ͳ�ƽ��
    cout << "intvector: "<<endl;
    put_vector(intvector);
    //��������
    fill(intvector.begin(),intvector.begin()+3,2);
    cout << "fill(intvector.begin(),intvector.begin()+3,2): "<<endl;
    put_vector(intvector);
    fill_n(&intvector[5],3,8);
    cout << "fill_n(&intvector[5],3,8): "<<endl;
    put_vector(intvector);
}
