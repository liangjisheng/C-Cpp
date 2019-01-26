
#ifndef HANDLE_H_
#define HANDLE_H_

class handle
{
	class wrapped;				// 声明一个类
	wrapped *working;			// 定义了一个指向类对象的指针
public:
	handle();
	void create();
	int read();
	void change(int);
	void destory();
	~handle();
};

#endif