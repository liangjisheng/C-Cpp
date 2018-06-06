
// ��ֵ(lvalue)����locator value��Ҳ����˵��������ʽͨ�����ֺ�
// ����ֵ(pointer��reference)��ָ��һ������.lvalue����һ���ɱ�����
// ���磺������������־���һ�����ɱ��Ķ���lvalue.���еķ�non-lvalues
// ���󣬶���rvalue,��������ʾ����(T())����ʱ����ͺ�������ֵ����rvalue

#include<iostream>
#include<memory>

using std::cout;
using std::endl;
using std::auto_ptr;
using std::ostream;

template<class T>
ostream& operator<<(ostream& out, const auto_ptr<T>& p)
{
	// does p own an object?
	if (NULL == p.get())
		out << "NULL";
	else
		out << *p;
	return out;
}

int main()
{
	// const auto_ptr������Ȩ���ܱ�����
	const auto_ptr<int> p(new int(42));
	const auto_ptr<int> q(new int(0));
	const auto_ptr<int> r;

	cout << "after initialization: " << endl;
	cout << "p: " << p << endl;
	cout << "q: " << q << endl;
	cout << "r: " << r << endl;

	*q = *p;
	// ��δָ���κζ����auto_ptr���н�����(dereference)����
	// C++��׼�涨����ᵼ��δ������Ϊ����������ʱ����
	// *r = *p;
	*p = -77;
	cout << "after assigning values: " << endl;
	cout << "p: " << p << endl;
	cout << "q: " << q << endl;
	cout << "r: " << r << endl;

	// q = p;		// error at compile time
	// r = p;		// error at compile time

	system("pause");
	return 0;
}