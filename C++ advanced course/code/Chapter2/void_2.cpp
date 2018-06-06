
// void* memcpy(void *dest, void *src, size_t len);
// void* memset(void *buffer, int c, size_t num);
// �κ����͵�ָ�붼���Դ���memcpy��memset�У���Ҳ��ʵ�������ڴ��������������
// ��Ϊ���Ĳ������������һƬ�ڴ棬��������Ƭ�ڴ�ʱʲô����

#include <iostream>

using std::cout;
using std::endl;

class A
{
	int arr[2];
	int i;
	double d;
public:
	A(){ memset(this, 0, sizeof(A)); }
	// ������Ϊʹ��memcpy��ʵ�����Ĭ�Ͽ������캯����һ�ֿ��з�����ͬʱ����
	// �����������A�д���ֻ����Ա����������memset()��memcpy()��ִ�л�ı�
	// ֻ����Ա������ֵ
	A(const A& a) { memcpy(this, &a, sizeof(A)); }
	void set(int, int, int, double);
	void show();
};

void A::set(int a0, int a1, int iv, double dv)
{
	arr[0] = a0;
	arr[1] = a1;
	i = iv;
	d = dv;
}

void A::show()
{
	cout << arr[0] << " " << arr[1] << " " << i << " " << d << endl;
}


int main()
{
	A obj;
	obj.show();
	obj.set(1, 2, 3, 4.8);
	A another = obj;
	another.show();

	system("pause");
	return 0;
}