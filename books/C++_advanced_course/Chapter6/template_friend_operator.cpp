
// ������Ԫ���������������������أ����ú���ģ����в���������ʱ��һ��Ҫע��
// ��Ԫ�����Ժ���ģ��ʵ��������������

#include <iostream>

using std::cout;
using std::endl;
using std::ostream;


template<typename T>
class UseOutputOverload
{
	T var;
public:
	UseOutputOverload(T t) { var = t; }
	template<typename T>		// ���������ȥ������ζ��operator<<��ĳ��ģ����
	// ����Ԫ�����������Ǹ���ͨ�������������ᷢ����Ԫ���������������������غ���
	// ģ��ʵ���������Σ����ֱ������
	friend ostream& operator<<(ostream&, const UseOutputOverload<T>&);

	//
};

template<typename T>
ostream& operator<<(ostream& out, const UseOutputOverload<T>& obj)
{
	out << obj.var;
	return out;
}


template<typename T>
class UseOutputOverload1
{
	T var;
public:
	UseOutputOverload1(T t) { var = t; }
	// �ں�����operator<<֮�����<T>����ʾ�����Ͳ���T��ʾʵ��������ģ��
	// operator<<,�Ӷ�ʵ�ֲ���������
	friend ostream& operator<< <T>(ostream&, const UseOutputOverload1<T>&);
};

template<typename T>
ostream& operator<<(ostream &out, const UseOutputOverload1<T> &obj)
{
	out << obj.var;
	return out;
}


int main()
{
	UseOutputOverload<int> o(3);
	// �˴��������в������ݣ����ҽ�����ģ��ʵ����
	cout << o << endl;

	UseOutputOverload<double> s(7.8);
	// �˴��������в������ݣ����ҽ�����ģ��ʵ����
	cout << s << endl;

	UseOutputOverload1<int> t1(3);
	cout << t1 << endl;

	system("pause");
	return 0;
}

