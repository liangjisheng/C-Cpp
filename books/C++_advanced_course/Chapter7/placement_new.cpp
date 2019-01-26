
// һ����˵��ʹ��new����ռ�ʱ���Ǵ�ϵͳ�Ķ�(heap)�з���ռ䣬�������õĿռ��
// λ���Ǹ��ݵ�ʱ���ڴ��ʵ��ʹ����������ģ�������ĳЩ���������£�������Ҫ
// �ڳ���Աָ�����ض��ڴ洦���������������ν�Ķ�λ����new(placement new)����

#include <iostream>
#include <new>			// for placement new

using namespace std;

// ʹ�ö�λ����new���ȿ����ڶ�ջ(stack)�����ɶ���Ҳ�����ڶ�(heap)�����ɶ���
// ��������ջ������һ������

class A
{
	int num;
public:
	A() { cout << "A" << endl; }
	~A() { cout << "~A" << endl; }
	void show() { cout << num << endl; }
};

int main()
{
	char memory[100] = {0};
	memory[0] = 'a';
	memory[1] = 0;
	memory[2] = 0;
	memory[3] = 0;
	cout << (void*)memory << endl;

	// ��λ���ɶ���ʱ�����Զ�������Ĺ��캯���������ڶ���Ŀռ䲻���Զ��ͷ�
	// ���Ա�����ʾ�ĵ��������������
	// �򲻵���ʱ��ʹ��placement new�﷨��ֻ�е����������������ڴ��е��ض�
	// λ��ʱ��ʹ�������������Ӳ����һ���ڴ�ӳ���I/O��ʱ���豸����������
	// ����һ��Clock�������Ǹ��ڴ�λ��
	A *p = new(memory) A;
	cout << p << endl;
	p->show();
	p->~A();

	system("pause");
	return 0;
}