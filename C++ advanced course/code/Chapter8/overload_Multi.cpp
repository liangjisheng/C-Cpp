
// *��һ��һԪ��������������ָ�룬��ʾȡָ����ָ��Ԫ�����ݣ�����ĳ������
// ��*��������������ʱ���ǽ�����Ķ�����һ��ָ�뿴��,����*��������ȡָ
// ����ָ������

#include <iostream>

using namespace std;

template<typename T>
class Data_Container
{
	T *p;
public:
	Data_Container(T *inp) { p = inp; }
	~Data_Container() { delete p; }

	// *�������ȿ�������Ԫ��������ʽ�������أ�Ҳ�����ó�Ա��������ʽ����
	template<typename T>
	friend T operator*(const Data_Container<T>&);
};

template<typename T>
T operator*(const Data_Container<T>& src)
{
	return *(src.p);
}

int main()
{
	Data_Container<int> IntData(new int(5));
	Data_Container<double> DoubleData(new double(7.8));
	cout << *IntData << endl;
	cout << *DoubleData << endl;

	system("pause");
	return 0;
}