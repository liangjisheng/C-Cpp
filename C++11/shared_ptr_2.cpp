#include"stdafx.h"
#include"iostream"
#include"stdio.h"
#include"memory"
#include"time.h"
#include"tchar.h"
using namespace std;

// 使用函数对象表示自定义的删除器
class FileCloser {
public:
	void operator() (FILE* pFile) {
		if(pFile!=NULL) {
			// 写入日志文件结束标志
			fprintf(pFile,"日志文件结束\n");
			// 输出日志文件被关闭
			cout<<"关闭日志文件"<<endl;
			// 关闭日志文件，完成文件指针清理工作
			fclose(pFile);
		}
	}
};

// 使用日志文件这一文件指针的多个客户，通过shared_ptr共享同一个日志文件，
// 分别向同一个日志文件打印系统时间和系统日期

void PrintTime(shared_ptr<FILE> spLog) 
{
	char tmpbuf[128];
	// strtime_s(tmpbuf,128);
	time_t timep;
	time(&timep);
	fprintf(spLog.get(),"当前系统时间:\t\t%s\n",ctime(&timep));
}

void PrintDate(shared_ptr<FILE> spLog)
{
	char tmpbuf[128];
	//_strdate_s(tmpbuf,128);
	time_t timep;
	time(&timep);
	fprintf(&*spLog,"当前系统日期:\t\t%s\n",ctime(&timep));
}

int _tmain(int argc,_TCHAR* argv[])
{
	FILE* fLog=NULL;
	fLog=fopen("log.txt","w");
	if(fLog!=NULL) {		// 成功打开日志文件
		cout<<"打开日志文件并写入日志"<<endl;
		shared_ptr<FILE> spLog(fLog,FileCloser());
		fprintf(spLog.get(),"日志文件开始\n");
		// 通过shraed_ptr实现文件指针在多个客户之间的共享
		PrintTime(spLog);
		PrintDate(spLog);
	}

	system("pause");
	return 0;
}
