
#include <iostream>

using std::cout;
using std::endl;

// �������г���Ϊ0���������ʹ��ڣ���ʹ�����в������κ����ݳ�Ա��
// ����Ķ������ڴ�����ȻҪռ1���ֽ�
class Small {};

// ��ĳ�Ա��������Ӱ�������ռ�ռ�Ĵ�С�������Ĵ�С�����������ݳ�Ա������
// ��LessFunc�������MoreFunc��Ķ�����ռ�ڴ��С��һ����
class LessFunc
{
	int num;
	void func1() {}
};

class MoreFunc
{
	int num;
	void func1() {}
	int func2() { return 1; }
};

class NeedAlign
{
	char c;
	double d;
	int i ;
};

// �����������һ��ָ���麯�����ָ�룬��ʵ���麯���Ķ�̬����
// ���ʹ�����ݳ�Ա֮��Ķ��룬��ô���ٰ���һ�����ݳ�Ա�ġ�ӵ��
// �麯���������Ĵ�С��СΪ8
class Virtual
{
	int num;
	virtual void func() {}
};


int main()
{
	cout << sizeof(Small) << endl;			// 1
	cout << sizeof(LessFunc) << endl;		// 4
	cout << sizeof(MoreFunc) << endl;		// 4
	cout << sizeof(NeedAlign) << endl;		// 24
	cout << sizeof(Virtual) << endl;		// 8

	system("pause");
	return 0;
}
