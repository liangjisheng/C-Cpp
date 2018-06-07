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

//��main()�����в���reverse()��reverse_copy()�㷨
void main ()
{
//--------------------------------------------
//	reverse()��reverse_copy()�㷨����ͨ���鴦��
//---------------------------------------------
    int x[]={1,3,5,7,9};
    cout<<"x[]:";
    put_array(x,5);

	//reverse()��תx���鲢��ʾ
    reverse(x,x+5);
    cout<<"x[]:";
    put_array(x,5);

    int y[]={2,4,6,8,10};
    cout<<"y[]:";
    put_array(y,5);

	//reverse_copy()��תy����Ĳ���Ԫ�ز�������x�����2��Ԫ��λ��
    reverse_copy(y+1,y+3,x+1);
    cout<<"x[]:";
    put_array(x,5);
    cout<<"y[]:";
    put_array(y,5);
//--------------------------------------------
//	reverse()��reverse_copy()�㷨��vector�����Ĵ���
//---------------------------------------------
    //����intvector�����͵�����ii
    IntArray intvector;

    //��intvector�����в���Ԫ��
    for (int i=1; i<=10; i++) {
        intvector.push_back(i);
    };

    //��ʾintvector�����е�Ԫ��ֵ
    cout << "intvector: "<<endl;
    put_vector(intvector);

	//reverse()����vector�����Ĵ���
    reverse(intvector.begin(),intvector.end());
    cout << "intvector: "<<endl;
    put_vector(intvector);

    // reverse_copy����vector�����Ĵ���
    IntArray temp(5);
    reverse_copy(intvector.begin()+2,intvector.begin()+7,temp.begin());
    cout << "temp: "<<endl;
    put_vector(temp);
}
