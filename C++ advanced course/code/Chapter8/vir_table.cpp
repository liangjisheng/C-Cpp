
// �麯������ڲ��ṹ,�麯�������Ӧ�ó���ĳ�����

#include <iostream>

using namespace std;

// ��ʾһ���������ڴ��еĵ�ַ,ʹ�����������Ի�ȡ��ķǾ�̬��Ա�����ĵ�ַ
#define ShowFuncAddress(function) _asm{\
	mov eax, function}\
	_asm{mov p, eax}\
	cout << "address of " #function " is 0x" << p << endl;

// ��ʾһ������麯����ָ���������麯��ָ��
// ClassNameΪ����
// pObjΪ���ĳ������ĵ�ַ
// indexΪ�麯�����ڱ��е�����
void ShowVTableContent(char *ClassName, void *pObj, int index)
{
	unsigned long *pAddr = NULL;
	// ��ȡ�麯����ĵ�ַ(��ͷ4�ֽڵ�����)
	pAddr = reinterpret_cast<unsigned long*>(pObj);
	// ��ͷ4�ֽڵ�����ǿ��ת��Ϊָ��,ָ��ĳ������麯�����������еĵ�ַ
	pAddr = (unsigned long *)*pAddr;
	cout << "the content of " << ClassName << "'s vtable[" << index << "]";
	cout << " is 0x" << (void*)pAddr[index] << endl;
}

// ������İ����麯�����࣬���麯������ڵ�ַд���麯�����������в������
// 1��ȷ����ǰ�����������麯���ĸ�����һ������麯����������Դ��һ�Ǽ̳���
// ����(�ڵ�ǰ���п��ܱ���д)�����������ڵ�ǰ�������������麯��
// 2��Ϊ���е��麯������,�̳��Ը���������麯�������ڵ�ǰ�����������麯��֮ǰ
// ���������麯���������ڵ�ǰ���е�����˳������
// 3��ȷ���麯������ڵ�ַ���̳��Ը�����麯��������ڵ�ǰ���б���д�����麯��
// ����ڵ�ַ���Ǹ�д֮��ĵ�ַ�������������е��麯������ڵ�ַ�����������麯��
// ����ڵ�ַ�����ڵ�ǰ���еĺ�������ڵ�ַ
// 4���������麯������ڵ�ַ�����Ŷ��Ĵ���һ��д���麯����

class Base
{
	int i;
public:
	virtual void f1() { cout << "Base's f1()" << endl; }
	virtual void f2() { cout << "Base's f2()" << endl; }
	virtual void f3() { cout << "Base's f3()" << endl; }
};

class Derived : public Base
{
	// ��������Derived�У�f4()��f3()֮ǰ���壬������f3�Ǽ̳��ڸ�����麯��
	// ��f4�����������麯��,����f3�Ĵ�������f4֮ǰ�����⾡�ܺ���f3������f1֮ǰ
	// �������Ƕ��̳��Ը��࣬���ڸ�����f1������f3֮ǰ�ģ�������Derived�У�f1()
	// ��Ȼ����f3()֮ǰ����������Derived�У���û���丸����麯��f2()�ĸ�д�汾
	// ���Ժ���f2����ڵ�ַ��Ȼ�����丸����麯��Base::f2����ڵ�ַ
public:
	virtual void f4() { cout << "Derived's f4()" << endl; }
	void f3() { cout << "Derived's f3()" << endl; }
	void f1() { cout << "Derived's f1()" << endl; }
};

// ������Base����Derived�ĸ���,������ȴ����ʹ�ò�ͬ���麯�������е��඼�����
// �������๲��һ���麯����
int main()
{
	Base b1;
	Derived d1;
	void *p;
	unsigned long *pAddr;

	pAddr = reinterpret_cast<unsigned long*>(&b1);
	// ��Ҫ��pAddr��������Ϊָ�����,���ܱ�ʾ����麯�������ڴ��еĵ�ַ
	// ��ֱ�����pAddr,���ʾ������Base�Ķ���b1���ڴ��еĵ�ַ
	cout << "Address of b1 is 0x" << pAddr << endl;
	cout << "Address of vtable of Base is 0x" << (void*)*pAddr << endl;
	pAddr = reinterpret_cast<unsigned long*>(&d1);
	cout << "Address of d1 is 0x" << pAddr << endl;
	cout << "Address of vtable of Derived is 0x" << (void*)*pAddr << endl;
	cout << endl;

	ShowFuncAddress(Base::f1);
	ShowVTableContent("Base", &b1, 0);
	ShowFuncAddress(Base::f2);
	ShowVTableContent("Base", &b1, 1);
	ShowFuncAddress(Base::f3);
	ShowVTableContent("Base", &b1, 2);
	cout << endl;

	ShowFuncAddress(Derived::f1);
	ShowVTableContent("Derived", &d1, 0);
	ShowFuncAddress(Derived::f2);
	ShowVTableContent("Derived", &d1, 1);
	ShowFuncAddress(Derived::f3);
	ShowVTableContent("Derived", &d1, 2);
	ShowFuncAddress(Derived::f4);
	ShowVTableContent("Derived", &d1, 3);

	system("pause");
	return 0;
}

