
// new��������ռ䣬���ط���ռ���׵�ַ���������ڴ���new����ʱ���Ƿ�����ʵ�ֵ�:
// ��һ���Ƿ���ռ䣬�ڶ����ǵ�����صĹ��캯����ע��new������(new operator)��
// ������new(operator new)��������ͬ�ĸ���
// new��������������£�1�����ڴ棬2���ù��캯����C++���������κη�ʽ�ı�������Ϊ
// ����Ա���ܸı�������Ϊ��������ڴ棬new������Ϊ�����ڴ������õĺ�����������
// operator new(������new): void* operator new(size_t size);����Ա�����Ӷ���Ĳ���
// ���غ���operator new,����һ���������ͱ�����size_t
// һ�㲻ֱ�ӵ���operator new,����������д�ǺϷ��ģ����������������һ��
// void* rawMemory = operator new(sizeof(string));

// ��������ʽ��operator new()��һ����ȫ�ֵ�operator new��������һ����Ϊ��ĳ�Ա����
// ���ڣ����һ����û�ж���operator new()��ô��̬����ʱ���õ���ȫ�ֵ�operator new

#include <iostream>
#include <string>

using namespace std;

void* operator new(size_t size)
{
	cout << "global operator new" << endl;
	return malloc(size);
}

class A
{
public:
	void* operator new(size_t size)
	{
		cout << "local operator new" << endl;
		return malloc(size);
	}
};


int main()
{
	string *ps;
	ps = new string("test");		// global new
	delete ps;						// delete��ʱ��Ҳ�����global new

	A *p;
	p = new A;
	delete p;

	system("pause");
	return 0;
}

