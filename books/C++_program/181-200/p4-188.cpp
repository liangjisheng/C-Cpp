#include <iostream>                 
#include <valarray>                 
#include <math.h>                   

using namespace std;

#define ARRAY_SIZE  3               //array size

//����valarray����
void main()
{
    //��������3��Ԫ�ص�����val_array 
    valarray<double> val_array(ARRAY_SIZE);

    //���������ֵΪ1, 4, 9
    for (int i = 0; i < ARRAY_SIZE; i++)
        val_array[i] = (i+1) * (i+1);

    //��ʾval_array����Ĵ�С
    cout << "Size of val_array = " << val_array.size() << endl;

    // ��ʾval_array�����ֵ
    cout << "The values in val_array before calling sqrt() and pow():" << endl;
    for (i = 0; i < ARRAY_SIZE; i++)
        cout << val_array[i] << "    ";
    cout << endl;

    //����һ��rev_valarray���飬�䱣�������val_array��ȡ��
    valarray<double> rev_valarray(ARRAY_SIZE);
    for (i = 0; i < ARRAY_SIZE; i++)
        rev_valarray[i] = val_array[ARRAY_SIZE - i - 1];

    //��ʾrev_valarray����Ĵ�С��Ԫ��
    cout << "Size of rev_valarray = " << rev_valarray.size() << endl;
    cout << "The values in rev_valarray:" << endl;
    for (i = 0; i < ARRAY_SIZE; i++)
        cout << rev_valarray[i] << "    ";
    cout <<endl;

    // ����rvalue_array���飬���ŵ���sqrt()��pow()�����ķ���ֵ
    valarray<double> rvalue_array;

    //����sqrt()��������ʾ���
    rvalue_array = sqrt(val_array);
    cout << "The result of rvalue_array after calling sqrt():" << endl;
    for (i = 0; i < ARRAY_SIZE; i++)
        cout << rvalue_array[i] << "     ";
    cout <<endl;

    //��val_array����Ԫ�ؼ����ݺ�������ʾ
    rvalue_array = pow(val_array, rev_valarray);
    cout << "The result after calling pow(val_array, rev_valarray):"
         << endl;
    for (i = 0; i < ARRAY_SIZE; i++)
        cout << rvalue_array[i] << "     ";
    cout <<endl;

    //��val_array����Ԫ�ؼ����ݺ�����ָ����Ϊ2.0������ʾ
    rvalue_array = pow(val_array, 2.0);
    cout << "The result after calling pow(val_array, 2.0):" << endl;
    for (i = 0; i < ARRAY_SIZE; i++)
        cout << rvalue_array[i] << "     ";
    cout <<endl;

    //��2.0�����ݺ������㣬ָ����Ϊ����val_array�ĸ�Ԫ��ֵ
    rvalue_array = pow(2.0, val_array);
    cout << "The result after calling pow(2.0, val_array):" << endl;
    for (i = 0; i < ARRAY_SIZE; i++)
        cout << rvalue_array[i] << "     ";
    cout <<endl;

	//��val_array��rvalue_array���
	cout<<"val_array.sum()="<<val_array.sum()<<endl;
	cout<<"rvalue_array.sum()="<<rvalue_array.sum()<<endl;

	//�����ֵ����ʾ
	cout<<"val_array.max()="<<val_array.max()<<endl;
	cout<<"rvalue_array.max()="<<rvalue_array.max()<<endl;
}
