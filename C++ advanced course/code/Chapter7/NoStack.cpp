
// ������ֹ��ջ�ϴ������󣬿��Խ����캯�����˽�еģ�����Ҳ��Ӱ��new����,
// ���п��Խ��������������Ϊ˽�е�

#include <iostream>

using namespace std;

class NonStack
{
private:
	int num;
	~NonStack();
public:
	NonStack() { num = 1; }
	void show() { cout << num << endl; }
	void Delete() { delete this; }
};

int main()
{
	// ����������˽�еģ���ֹ��ջ�ϴ�������
	// NonStack obj;		// error

	NonStack *p = new NonStack;
	p->show();
	p->Delete();		// ����ʱ���������Delete����

	system("pause");
	return 0;
}