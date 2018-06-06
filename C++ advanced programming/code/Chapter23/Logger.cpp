
#include <iostream>
#include "Logger.h"
#include <fstream>


using std::thread;
using std::cout;
using std::endl;
using std::cerr;
using std::unique_lock;
using std::mutex;
using std::ofstream;


//Logger::Logger()
//{
//	// Start background thread
//	mThread = thread{ &Logger::processEntries, this };
//}


//void Logger::log(const std::string& entry)
//{
//	// Lock mutex and entry to the queue
//	unique_lock<mutex> lock(mMutex);
//	mQueue.push(entry);
//	// Notify condition variable to wake up thread
//	mCondVar.notify_all();
//}


//void Logger::processEntries()
//{
//	// Open log file.
//	ofstream ofs("log.txt");
//	if (ofs.fail())
//	{
//		cerr << "Failed to open logfile." << endl;
//		return;
//	}
//
//	// Start processing loop.
//	unique_lock<mutex> lock(mMutex);
//	while (true)
//	{
//		// Wait for a notification
//		mCondVar.wait(lock);
//		// Condition variable is notified, so something might be in the queue.
//		lock.unlock();
//		while (true)
//		{
//			lock.lock();
//			if (mQueue.empty())
//				break;
//			else
//			{
//				ofs << mQueue.front() << endl;
//				mQueue.pop();
//			}
//			lock.unlock();
//		}
//	}
//}


Logger::Logger() : mExit(false)
{
	// Start background thread
	mThread = thread{ &Logger::processEntries, this };
}


Logger::~Logger()
{
	{
		unique_lock<mutex> lock(mMutex);
		// Gracefully shut down the thread by setting mExit.
		// to true and notifying the thread.
		mExit = true;
		// Notify condition variable to wake up thread
		mCondVar.notify_all();
	}
	// Wait unitl thread is shut down. This should be outside the above code
	// block because the lock on mMutex must be released before calling join()
	mThread.join();
}


void Logger::log(const std::string& entry)
{
	// Lock mutex and entry to the queue
	unique_lock<mutex> lock(mMutex);
	mQueue.push(entry);
	// Notify condition variable to wake up thread
	mCondVar.notify_all();
}


void Logger::processEntries()
{
	// Open log file.
	ofstream ofs("log.txt");
	if (ofs.fail())
	{
		cerr << "Failed to open logfile." << endl;
		return;
	}

	// Start processing loop.
	unique_lock<mutex> lock(mMutex);
	while (true)
	{
		if (!mExit)
			mCondVar.wait(lock);
		// Wait for a notification
		// mCondVar.wait(lock);
		// Condition variable is notified, so something might be in the queue.
		lock.unlock();
		while (true)
		{
			lock.lock();
			if (mQueue.empty())
				break;
			else
			{
				ofs << mQueue.front() << endl;
				mQueue.pop();
			}
			lock.unlock();
		}
		if (mExit)
			break;
	}
}

