
// ���������������b�ĵ�ַ����һ���ģ�����a�Ĺ��캯���ڶ���b�Ĺ��캯��֮ǰִ��
// ����ʱ����b�ĵ�ַ�Ѿ�ȷ���ˡ��ڵ���b�Ĺ��캯��ʱ�����ڹ��캯���������֮��
// b�ĵ�ַ��û�з����仯��������½��ۣ�
// 1��Ϊ�������ռ�͵��ö���Ĺ��캯����������ͬ�Ĺ��������캯����������Ϊ����
// ����ռ�ģ����Ƕ����ݳ�Ա���г�ʼ����ʹ�������״λ���������ֵ����������
// ���캯��ʱ���������ռ�Ĺ����Ѿ���ɣ�����ڹ��캯���п������ɷ��ʶ����
// ���ݳ�Ա�͵��ó�Ա����
// 2��һ������£�Ϊ�������ռ�͵��ù��캯�����ǽ����Ž��еģ����Ǳ���������
// ��֯����Ľ������Ҳ�����⣬���ں������ڶ���ľ�̬������ռ����ڳ���ִ��
// ֮�����Ѿ�����(��ȫ�ֱ���ͬ��һ���洢��)�����ö���Ĺ��캯��ȴ�ǵ�������
// ��һ�ε���ö������ִ�е�

#include <iostream>

using std::cout;
using std::endl;

class B;

class A
{
public:
	A(B &obj) 
	{
		cout << "Before constructor,b's address is:" << &obj << endl; 
	}
};

class B
{
	int num;
public:
	B(){ cout << "In constructor,b's address is:" << this << endl; show(); }
	void show() { cout << "B's member function, num = " << num << endl; }
};


extern B b;
A a(b);
B b;

int main()
{
	cout << "After constructor,b's address is:" << &b << endl;

	system("pause");
	return 0;
}

