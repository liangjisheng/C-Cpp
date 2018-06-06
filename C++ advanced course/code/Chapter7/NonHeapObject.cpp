
// ��ʱ������Ա���ܲ�ϣ�������ڶ��ϲ���������ĳ�����ڷ�װ����������Դ���������
// ���������ĵ��þ��Ե÷ǳ���Ҫ������ö���ֻ����ջ�в����������������쳣�����
// ���Զ��ͷŷ�װ����Դ����������������ڶ��ϲ�������ô����������������ܱ���
// �����õĿ����Ի�����
// �����Ѷ����Ψһ������ʹ��new��������Ϊ2������һ������operator new,�ڶ�����
// ���ù��캯������operator new�ǿ������صģ����Կ���ʹoperator new��Ϊprivate

#include <stdlib.h>

class Resource {};		// ������װ����Դ��

class NonHeapObject
{
private:
	Resource *ptr;		// ָ�򱻷�װ����Դ
	void* operator new(size_t size)
	{ return malloc(size); }		// ���ϸ�ʵ�֣�����ʾ��
	void operator delete(void *pp)
	{ free(pp); }					// ���ϸ�ʵ�֣�����ʾ��
public:
	NonHeapObject()
	{
		// �˴����Ի����Ҫ��װ����Դ����ptrָ�����Դ
		ptr = new Resource();
	}
	~NonHeapObject() { delete ptr; }	// �ͷ���Դ
};

// NonHeapObject���ھ���һ����ֹ�����Ѷ��������

int main()
{
	// error,��Ϊ��operator new���˽�е�
	// NonHeapObject *np = new NonHeapObject();
	// delete np;

	// ���ֽ�ֹ�����Ѷ���ķ���ֻ�����ѳ���Ա��Ҫ�ڶ��ϲ���ĳ��Ķ����������Ա
	// ��ǿ���ڶ��ϴ�������һ������ͨ�����;��ʵ�֣��������ڶ�������һ��ռ䣬
	// Ȼ�����ö�λ����new(placement new)�����������󣬻����ֹ�����һ������ȵ�

	system("pause");
	return 0;
}