
// ����ʹ������̳���ʵ���ս��࣬һ���������������̳У���ô�ڴ��������κ�
// ����(�������������)�Ķ���ʱ�����Ĺ��캯�����Ǳ��������õģ���һ���һ��
// �ļ̳й�ϵ��ͬ

#include <iostream>

using namespace std;

// �κ��ֻ࣬Ҫ��������̳���FinalParent���Ͳ��ܱ������̳У��Ӷ���һ��
// �򵥵ķ�ʽʵ�����ս���

class FinalParent
{
	// ���캯������Ϊprotected�������������������κ�ʵ����ֻ����������
protected:
	FinalParent(){}
};

// ͨ��˽������̳в���������FinalClass,����FinalParent::FinalParent�ķ���
// Ȩ����protected,���Կ�������FinalClass�Ĺ��캯���е��ã�����FinalClass
// ���Ա�ʵ�������ڸ����ж�����κγ�Ա�ķ��ʲ��ܸ����Ӱ��
// �������ڲ���˽�м̳еķ�ʽ������FinalParent::FinalParent����FinalClass
// �еķ���Ȩ�޾ͱ����private��Ҳ����˵���κ�FinalClass�������඼�޷�����
// ��FinalParent�Ĺ��캯����������������FinalParent�Ǳ���FinalClass����̳�
// �ģ�������FinalClass��������Ĺ��캯���б���ֱ�ӵ�����FinalParent�Ĺ���
// ����
class FinalClass : private virtual FinalParent
{
	int num;
public:
	FinalClass() { num = 5; }
	void show() { cout << num << endl; }
};

// ��FinalChild���б������������FinalParent�Ĺ��캯����������FinalClass
// �У���FinalParent�Ĺ��캯���Ѿ����˽�еģ����ܱ�FinalChild���κγ�Ա
// ���ʣ���˱������
class FinalChild : public FinalClass {};

int main()
{
	FinalClass obj;
	obj.show();

	FinalChild b;
	obj.show();

	system("pause");
	return 0;
}