#include"stdafx.h"
#include"iostream"
#include"stdio.h"
#include"memory"
#include"time.h"
#include"tchar.h"
using namespace std;

// ʹ�ú��������ʾ�Զ����ɾ����
class FileCloser {
public:
	void operator() (FILE* pFile) {
		if(pFile!=NULL) {
			// д����־�ļ�������־
			fprintf(pFile,"��־�ļ�����\n");
			// �����־�ļ����ر�
			cout<<"�ر���־�ļ�"<<endl;
			// �ر���־�ļ�������ļ�ָ��������
			fclose(pFile);
		}
	}
};

// ʹ����־�ļ���һ�ļ�ָ��Ķ���ͻ���ͨ��shared_ptr����ͬһ����־�ļ���
// �ֱ���ͬһ����־�ļ���ӡϵͳʱ���ϵͳ����

void PrintTime(shared_ptr<FILE> spLog) 
{
	char tmpbuf[128];
	// strtime_s(tmpbuf,128);
	time_t timep;
	time(&timep);
	fprintf(spLog.get(),"��ǰϵͳʱ��:\t\t%s\n",ctime(&timep));
}

void PrintDate(shared_ptr<FILE> spLog)
{
	char tmpbuf[128];
	//_strdate_s(tmpbuf,128);
	time_t timep;
	time(&timep);
	fprintf(&*spLog,"��ǰϵͳ����:\t\t%s\n",ctime(&timep));
}

int _tmain(int argc,_TCHAR* argv[])
{
	FILE* fLog=NULL;
	fLog=fopen("log.txt","w");
	if(fLog!=NULL) {		// �ɹ�����־�ļ�
		cout<<"����־�ļ���д����־"<<endl;
		shared_ptr<FILE> spLog(fLog,FileCloser());
		fprintf(spLog.get(),"��־�ļ���ʼ\n");
		// ͨ��shraed_ptrʵ���ļ�ָ���ڶ���ͻ�֮��Ĺ���
		PrintTime(spLog);
		PrintDate(spLog);
	}

	system("pause");
	return 0;
}
