
#include "stdafx.h"
#include "CLog.h"
#include <time.h>

string CLog::m_strLogFileName = "myLog.log";
string CLog::m_strLogFilePath = "";

CLog::CLog()
{
	m_strLogContent = "";
	m_strCurTime = GetLogWriteTime();
}

CLog::CLog(int num)
{
	char szNum[20] = {0};
	sprintf_s(szNum, 19, "%d", num);
	m_strLogContent = szNum;
	m_strCurTime = GetLogWriteTime();
}

CLog::CLog(float f)
{
	char szNum[20] = {0};
	sprintf_s(szNum, 19, "%f", f);
	m_strLogContent = szNum;
	m_strCurTime = GetLogWriteTime();
}

CLog::CLog(double d)
{
	char szNum[20] = {0};
	sprintf_s(szNum, 19, "%f", d);
	m_strLogContent = szNum;
	m_strCurTime = GetLogWriteTime();
}

CLog::CLog(char *lpszContent)
{
	m_strLogContent = lpszContent;
	m_strCurTime = GetLogWriteTime();
}

CLog::CLog(const string& strName)
{
	m_strLogContent = strName;
	m_strCurTime = GetLogWriteTime();
}

void CLog::ResetLog()
{
	fstream file;
	// 默认方式打开清空文件
	file.open(m_strLogFileName.c_str(), ios::out);
	file.close();
}

void CLog::WriteLine()
{
	fstream file;
	file.open(m_strLogFileName.c_str(), ios::app | ios::out);
	file << endl;
	file.close();
}

CLog::~CLog()
{
	fstream file;
	file.open(m_strLogFileName.c_str(), ios::app | ios::out);
	file << m_strLogContent << endl;
	file.close();
}

string CLog::setLogFileName(const string &strNewName)
{
	string strOldName = m_strLogFileName;
	m_strLogFileName = strNewName;
	return strOldName;
}

string CLog::setLogPathName(const string &strNewPath)
{
	string strOldPath = m_strLogFilePath;
	m_strLogFilePath = strNewPath;
	return strOldPath;
}

string CLog::GetLogWriteTime()
{
	time_t rawtime;
	struct tm timeinfo; 
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);
	char szTime[128] = {0};
	asctime_s(szTime, 127, &timeinfo);
	return string(szTime);
}

void CLog::WriteTime()
{
	fstream file;
	file.open(m_strLogFileName.c_str(), ios::app | ios::out);
	file << GetLogWriteTime() << endl;
	file.close();
}

