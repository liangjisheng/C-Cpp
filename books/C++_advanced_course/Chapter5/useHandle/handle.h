
#ifndef HANDLE_H_
#define HANDLE_H_

class handle
{
	class wrapped;				// ����һ����
	wrapped *working;			// ������һ��ָ��������ָ��
public:
	handle();
	void create();
	int read();
	void change(int);
	void destory();
	~handle();
};

#endif