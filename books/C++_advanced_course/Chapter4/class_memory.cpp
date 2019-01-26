
// �������ڴ�ʵ��,���������ĳ�Ա�����Ĵ��붼��һ���ģ�û�б�Ҫ����Ա������
// ������ڶ������棬��Ա�����Ĵ�����ڴ��������������������������ĳߴ���
// �������ݳ�Ա�ĳߴ�����ģ����Ա�����Ķ����޹�

#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::hex;
using std::dec;

// ����һ���꽫ĳ���������4���ֽڵ����������
#define PrintFirstAsInt(obj) {\
	void *p = &(obj);\
	int *q = (int*)p;\
	cout << *q << endl;}

// ����һ���꽫ĳ���������4���ֽ���16�������
#define PrintFirstAs0x(obj){\
	void *p = &(obj);\
	int *q = (int*)p;\
	cout << hex << *q << endl << dec;}

// һ���������κγ�Ա���࣬���СΪ1
class Empty{};

class OneByte
{
	char c;
};

// �����Ա���������������ĳߴ�
class OneByteWithFunction
{
	char c;
public:
	void show() { cout << c << endl; }
};


// ���徲̬��Ա���������ĳߴ�
class OneByteWithStatic
{
	char c;
	static int i;
};

// ����ߴ粢��һ�����ڸ���Ա�����ߴ�֮��
class WithTwoMembers
{
	int i;		// ���ǰ4���ֽھ��Ǵ洢��i
	char c;
public:
	WithTwoMembers() { i = 106; c = 'A'; }
	void show() { cout << i << endl; }
};

// �����麯���ᵼ�¶���ߴ�����4�ֽڣ����ǰ4���ֽڴ洢����ָ������ָ��
class WithVirtualFunction
{
	int i;
	char c;
public:
	WithVirtualFunction() { i = 106; c = 'A'; }
	virtual void show() { cout << i << endl; }
};

// ������������ʼλ�ð���һ��������󣬶���ǰ4���ֽڴ洢���ǻ�������ǰ4���ֽ�
class DerivedClass : public WithTwoMembers
{
	int newmem;
public:
	DerivedClass() { newmem = 57; }
};

// �����麯��������������ھ���ʼ��ַƫ����Ϊ4��λ�ð���һ���������
// ǰ4���ֽڴ洢����������ָ������ָ�룬�����ָ������ָ���ǲ�һ����
class DerivedFromVirtual : public WithVirtualFunction
{
	int newmem;
public:
	DerivedFromVirtual() { newmem = 57; }
};


struct mytest{};


int main()
{
	cout << "sizeof(Empty) is " << sizeof(Empty) << endl;
	cout << "sizeof(OneByte) is " << sizeof(OneByte) << endl;
	cout << "sizeof(OneByteWithFunction) is " << sizeof(OneByteWithFunction) << endl;
	cout << "sizeof(OneByteWithStatic) is " << sizeof(OneByteWithStatic) << endl;
	cout << "sizeof(WithTwoMembers) is " << sizeof(WithTwoMembers) << endl;
	cout << "sizeof(WithVirtualFunction) is " << sizeof(WithVirtualFunction) << endl;
	cout << "sizeof(DerivedClass) is " << sizeof(DerivedClass) << endl;
	cout << "sizeof(DerivedFromVirtual) is " << sizeof(DerivedFromVirtual) << endl;

	cout << endl;
	WithTwoMembers obj1;
	PrintFirstAsInt(obj1);

	WithVirtualFunction obj2;
	PrintFirstAsInt(obj2);

	DerivedClass obj3;
	PrintFirstAsInt(obj3);

	DerivedFromVirtual(obj4);
	PrintFirstAsInt(obj4);

	obj1.show();
	obj2.show();

	cout << endl;
	Empty e1;
	PrintFirstAsInt(e1);
	PrintFirstAs0x(e1);

	cout << sizeof(mytest) << endl;

	system("pause");
	return 0;
}