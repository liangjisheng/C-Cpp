
// ������ͨ���ݳ�Ա���ԣ�ʹ�ó�ʼ���б���ڹ��캯�����ڸ���ֵЧ����һ����
// ����һЩ����£�ֻ��ʹ�ó�ʼ���б�Գ�Ա���г�ʼ�������磬���ݳ�Ա��
// ���á��������������(����û���ṩ���������Ĺ��캯��)��

#include <iostream>

using std::cout;
using std::endl;


class A
{
	int num;
public:
	A(int i) { num = i; }
	void show() { cout << num << endl; }
};


class B
{
	int &r;
	const double PI;
	A a;
public:
	B(int i);
	void show() 
	{
		cout << r << endl;
		cout << PI << endl;
		a.show();
	}
};

int e = 5;

// �����ò���i��ʼ������r�������������һ�������
B::B(int i) : r(e), PI(3.1415926), a(i) {}

//B::B(int i)
//{
//	r = e;				// ����Ϊ���ø�ֵ�������ǳ�ʼ��
//	PI = 3.1415926;		// ������ֵ������ı�
//	a = A(i);			// �ڵ�����B�Ĺ��캯��֮ǰ���ȵ�����A�Ĺ��캯��A(),
//						// ����A���޲����Ĺ��캯����û�ж���
//}

int main()
{
	// ������һ�������Ķ��󣬲�����show()��Ա����
	B(1).show();

	system("pause");
	return 0;
}