
// �������߳���ָ��Ҫִ�е���ĳ�Ա����

#include <iostream>
#include <thread>

using std::cout;
using std::endl;
using std::thread;

class Request
{
public:
	Request(int id) : mId(id) {}
	void process()
	{
		cout << "Processing request " << mId << endl;
	}

private:
	int mId;
};


int main()
{
	Request req(100);
	thread t{ &Request::process, &req };
	t.join();

	// ͨ�����ּ��������ڲ�ͬ�߳���ִ��ĳ�������еķ���������������߳�
	// ����ͬһ��������Ҫȷ�����ַ������̰߳�ȫ�ģ���Ҫ����ͬ��

	system("pause");
	return 0;
}

