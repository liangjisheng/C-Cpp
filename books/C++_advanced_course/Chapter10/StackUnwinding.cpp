
// ��ջչ��(Stack Unwinding)��ָ�������һ�������ڲ��׳��쳣�������쳣��δ�ڸú���
// �ڲ�����׽���ͽ����¸ú������������׳��쳣�������������Ѿ�������ջ�ϵľֲ�����
// ��Ҫ���ͷţ�������ͷŵı�������ָ�룬����ָ���ǰ�Ѿ���new�����˿ռ䣬���п��ܡ�
// �����ڴ�й¶����Ϊ��ջչ����ʱ�򲢲����Զ��Ը�ָ�����ִ��delete(delete[])����
// ʹ������ָ��auto_ptr����ֹ�ڴ�й¶

#include <iostream>
#include <memory>		// auto_ptr

using std::cout;
using std::endl;
using std::auto_ptr;

class A
{
	int num;
public:
	A(int i) : num(i) 
	{ cout << "this is A's constructor,num = " << num << endl; }
	~A() { cout << "this is A's destructor, num = " << num  << endl; }
	void show() { cout << num << endl; }
};

void AutoPtr_test1()
{
	A *pa = new A(1);
	throw 1;
	// ����throw��������仰�޷�ִ�У������ڴ�й¶
	delete pa;
}

void AutoPtr_test2()
{
	// ��ջչ��������auto_ptr<T>����ᱻ�ͷţ��Ӷ�����auto_ptr<T>���������
	// ���������ã����ᷢ���ڴ�й¶
	auto_ptr<A> pa(new A(2));
	pa->show();
	throw 2;
}


int main()
{
	try{
		AutoPtr_test1();
	}
	catch(int){
		cout << "there is no destructor invoked" << endl;
	}

	cout << endl;
	try{
		AutoPtr_test2();
	}
	catch(int){
		cout << "A's destructor does be invoked" << endl;
	}

	system("pause");
	return 0;
}