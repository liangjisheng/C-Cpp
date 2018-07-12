
#ifndef _CLOG_H_
#define _CLOG_H_

#include <string>
#include <fstream>

using std::endl;
using std::string;
using std::fstream;
using std::ios;


class CLog
{
public:
	CLog();
	CLog(int num);
	CLog(float f);
	CLog(double d);
	CLog(char *lpszContent);
	CLog(const string& strName);
	virtual ~CLog();
	// static void SetLogAttribute(const string& logFile);
	static void WriteLine();					// 写入一个空行
	static void ResetLog();						// 清空日志文件
	// 设置日志文件名,返回上一次的日志名
	static string setLogFileName(const string &strNewName);
	// 设置日志文件路径，返回上一次的日志路径
	static string setLogPathName(const string &strNewPath);
	static void WriteTime();
private:
	static string m_strLogFilePath;			// 日志文件路径
	static string m_strLogFileName;			// 日志文件名
	string m_strLogContent;					// 每次写入日志文件的内容
	string m_strCurTime;					// 每次写入日志内容的时间
	static string GetLogWriteTime();		// 获取日志写入时间
};

#endif