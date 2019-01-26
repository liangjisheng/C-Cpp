
// �򵥵�˵��ģ���ʵ���������ɺ���ģ��(��ģ��)����ģ�庯��(ģ����)�Ĺ��̡�
// �Ժ���ģ����ԣ�ʵ�����󣬾ͻ����һ�������ĺ���(�ú�����������֮�����
// ��ִ�еĶ����ƴ���)������ģ�徭��ʵ������ֻ������������͵Ķ��壬ģ��
// ��ĳ�Ա����Ҫ�����õ�ʱ��Żᱻʵ����

// ��ʽʵ������Ժ���ģ�壬������ֱ�ӵ��ú���ģ���ʱ�򡣻��о��Ǽ�ӵ��ú���
// �����Σ���ӵ���ָ����������ڵ�ַ���ݸ�һ��ָ�룬ͨ������ָ����ɺ�������


#include <iostream>

using std::cout;
using std::endl;

template<typename T>
void func(T t) { cout << t << endl; }

template<typename T>
class A
{
	T num;
public:
	A() { num = T(6.8); }
	void invoke(void(*p)(T)) { p(num); }
};


template<typename T>
T myMax(const T &t1, const T &t2)
{ return t1 > t2 ? t1 : t2; }


int main()
{
	A<int> a1;
	a1.invoke(func);	// funcʵ����Ϊfunc<int>

	A<double> a2;
	a2.invoke(func);	// funcʵ����Ϊfunc<double>

	int i = 5;
	// i��'a'��������ͬ���������ͣ��޷��������������н�����������
	// cout << myMax(i, 'a') << endl;		// error
	cout << myMax<int>(i, 'a') << endl;		// ok

	system("pause");
	return 0;
}


// ��ʾʵ������Ҳ��Ϊ�ⲿʵ�������京�����ڲ������������õ�ʱ�򽫺���ģ��ʵ����
// ���߲�ʹ��ģ�����ʱ����ģ��ʵ����:template void func<int>(const int&);
// ��������ģ����ԣ������Ƿ�����һ��ģ������󣬶�����ֱ��ͨ����ʾʵ��������
// ����ģ��ʵ����:template class theclass<int>;��ģ���е����г�Ա����ģ���ͬʱ
// ��ʵ����(ֻҪ��ͬһ��Դ�ļ����ṩ�䶨��)

