#pragma once


// ��ʾ�����ʹ���̡߳������塢���������������дһ�����̵߳�Logger�࣬�����
// ����ͬ���߳���һ�������������־��Ϣ��Logger�౾�������һ����̨�߳��д���
// ������У�����־��Ϣ���е�д��һ���ļ���C++��׼û���̰߳�ȫ�Ķ��У�����ͨ��
// һ�������屣�����еķ��ʣ��������߳�ͬʱ��д���С�

#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <atomic>

//class Logger
//{
//public:
//	// Starts a background thread writing log entries to a file
//	Logger();
//	// Prevent copy construction and assignment.
//	Logger(const Logger& src) = delete;
//	Logger& operator=(const Logger& src) = delete;
//	// Add log entry to the queue
//	void log(const std::string& entry);
//
//private:
//	// The function running in the background thread.
//	void processEntries();
//	// Mutex and condition variable to protect access to the queue
//	std::mutex mMutex;
//	std::condition_variable mCondVar;
//	std::queue<std::string> mQueue;
//	// The backgournd thread
//	std::thread mThread;
//};


// ����ڶ�˼�����Ϲ���������������򣬻ᷢ�ֺ�̨Logger�̻߳���main()����
// ����ʱͻȻ��ֹ������ζ�ţ���Ȼ�ڶ����е���Ϣ����д������ļ�������̨Logger
// �߳�ͻȻ��ֹʱ������һЩ����ʱ��ᱨ�������һ������ת������Ҫ���һ��
// �����������رպ�̨�̣߳�����Ӧ�ó�������ֹ֮ǰ���ȴ���̨�߳���ȫ�ر�
// �����ͨ�����������һ������������һ��ԭ��bool�ͳ�Ա�������


class Logger
{
public:
	// Starts a background thread writing log entries to a file
	Logger();
	virtual ~Logger();
	// Prevent copy construction and assignment.
	Logger(const Logger& src) = delete;
	Logger& operator=(const Logger& src) = delete;
	// Add log entry to the queue
	void log(const std::string& entry);

private:
	// The function running in the background thread.
	void processEntries();
	// Mutex and condition variable to protect access to the queue
	std::mutex mMutex;
	std::condition_variable mCondVar;
	std::queue<std::string> mQueue;
	// The backgournd thread
	std::thread mThread;
	// Boolean telling the background thread to terminate.
	std::atomic<bool> mExit;
};
