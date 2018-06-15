
// auto_ptr�Ǳ�׼���ṩ��һ��������ָ��(smart pointer),��ֹ���쳣
// �׳�ʱ������Դй¶��auto_ptr��ֻ֤Ҫ�Լ����ݻ٣���һ�������ͷ�
// ����ָ��Դ��auto_ptrҪ��һ������ֻ����һ��ӵ���ߣ��Ͻ�һ�����

// std::auto_ptr<ClassA> ptr(new ClassA);

// auto_ptrӵ��Ȩ��ת�ƣ���auto_ptr��copy������assignment��������
// ����ӵ��Ȩ����ȥ

// ���auto_ptr�Ѵ�ֵ�ķ�ʽ������һ���������ݸ�ĳ����,��ʱ�����õ�
// �����Ĳ�����������auto_ptr��ӵ��Ȩ������������ڽ������ݳ�ȥ��
// ����ָ�Ķ���ͻ��ں����˳�ʱ��ɾ��
// ��һ��auto_ptr������ʱ����ӵ��Ȩ�㱻ת�������ö���
// ���������ת��ӵ��Ȩ���Ͳ�Ҫ�ڲ����б���ʹ��auto_ptr��Ҳ��Ҫ����
// ��Ϊ����ֵ
// ���ͨ�������÷�ʽ���ݣ�������ʹ��ӵ��Ȩ�ĸ���������׽����Ӧ��
// ���⴫���÷�ʽ

// ����constant reference,ͨ��һЩ���ɣ�������constant reference�޷�
// ����ӵ��Ȩ
// const std::auto_ptr<int> p(new int);	// no ownership transfer possible
// const������ζ�Ų��ܸ���auto_ptr��ӵ�еĶ��󣬶��ǲ��ܸ���auto_ptr��ӵ��Ȩ
// ʹ��const auto_ptr��Ϊ����,���¶�����κθ�ֵ�����������±����ڴ���
// const auto_ptr�Ƚ������ڳ���ָ��T* const p;����ָ������ָ��(const T* p)
// �����﷨����ȥ�����

// auto_ptrȷʵ�����һ���ض����⣬�Ǿ������쳣��������е���Դ��ʧ����
// 1.auto_ptr֮�䲻�ܹ���ӵ��Ȩ��һ��auto_ptr����ָ����һ��auto_ptr��
// ӵ�еĶ���
// 2.�����������array����Ƶ�auto_ptr,auto_ptr������ָ��array,��Ϊauto_ptr
// ��͸��delete����delete[]���ͷ�����ӵ�еĶ���C++��׼����Ⲣδ�ṩ���
// array����Ƶ�auto_ptr
// 3.auto_ptr����һ���ĺ�ͨ�õ�������ָ��
// 4.auto_ptr������STL��������Ԫ�ص�Ҫ����Ϊ�ڿ����͸�ֵ֮��ԭ����auto_ptr
// ���²�����auto_ptr�������

#include<iostream>
#include<memory>

using std::cout;
using std::endl;
using std::ostream;
using std::auto_ptr;

/* define output operator for auto_ptr
 * print object value or NULL
 * �ڶ�������Ϊconst auto_ptr<T>&,���Բ�û�з���ӵ��Ȩ��ת��
*/
template<class T>
ostream& operator <<(ostream& out, const auto_ptr<T>& p)
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
	// int*�޷���ʽת����auto_ptr,����ͨ����ʾת��
	// ��Ϊ�乹�캯��������Ϊexplicit
	// auto_ptr<int> p1 = new int(32);		// error

	auto_ptr<int> p(new int(42));
	auto_ptr<int> q;

	cout << "after initialization: " << endl;
	cout << "p: " << p << endl;
	cout << "q: " << q << endl;
	cout << endl;

	q = p;
	cout << "after assigning auto pointers: " << endl;
	cout << "p: " << p << endl;
	cout << "q: " << q << endl;
	cout << endl;

	*q += 13;
	p = q;
	cout << "after change and reassignment: " << endl;
	cout << "p: " << p << endl;
	cout << "q: " << q << endl;
	cout << endl;

	system("pause");
	return 0;
}
