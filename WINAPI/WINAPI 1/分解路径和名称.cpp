// 获取一个文件的路径名，文件名，和扩展名
#include"stdafx.h"
#include"iostream"
#include"string.h"
using namespace std;

// 路径管理类
class CPath {
public:
	// 从包含完整路径的文件名中去除路径，获得文件名和扩展名
	static void GetFileName(char szSrcFile[],int nSrcLen,char *szDesFile);
	// 获取文件的扩展名
	static void GetExtName(char szSrcFile[],int nSrcLen,char *szDesFile);
	// 获取文件名
	static void GetFileShortName(char szSrcFile[],int nSrcLen,char *szDesFile);
	// 获取文件路径
	static void GetPath(char szSrcFile[],int nSrcLen,char *szDesFile);
};

void CPath::GetFileName(char szSrcFile[],int nSrcLen,char *szDesFile)
{
	char ch;
	int i,prev=0,curr=0,j;
	for(i=0;i<nSrcLen;i++) {
		curr=i;
		ch=szSrcFile[i];
		if(ch=='\\') prev=curr;
		if(ch=='.') break;
	}
	for(i=prev+1,j=0;i<nSrcLen;i++,j++)
		szDesFile[j]=szSrcFile[i];
	szDesFile[j]='\0';
}

void CPath::GetExtName(char szSrcFile[],int nSrcLen,char *szDesFile)
{
	char ch;
	int i,prev=0,curr=0,j;
	for(i=0;i<nSrcLen;i++) {
		curr=i;
		ch=szSrcFile[i];
		if(ch=='\\') prev=curr;
		if(ch=='.') break;
	}
	for(i=curr+1,j=0;i<nSrcLen;i++,j++)
		szDesFile[j]=szSrcFile[i];
	szDesFile[j]='\0';
}

void CPath::GetFileShortName(char szSrcFile[],int nSrcLen,char *szDesFile)
{
	char ch;
	int i,prev=0,curr=0,j;
	for(i=0;i<nSrcLen;i++) {
		curr=i;
		ch=szSrcFile[i];
		if(ch=='\\') prev=curr;
		if(ch=='.') break;
	}
	for(i=prev+1,j=0;i<curr;i++,j++)
		szDesFile[j]=szSrcFile[i];
	szDesFile[j]='\0';
}

void CPath::GetPath(char szSrcFile[],int nSrcLen,char *szDesFile)
{
	char ch;
	int i,prev=0,curr=0,j;
	for(i=0;i<nSrcLen;i++) {
		curr=i;
		ch=szSrcFile[i];
		if(ch=='\\') prev=curr;
		if(ch=='.') break;
	}
	for(i=0,j=0;i<prev;i++,j++)
		szDesFile[j]=szSrcFile[i];
	szDesFile[j]='\0';
}

int main(int argc,char *argv[])
{
	char FileName[128]={0};
	CPath::GetFileName(argv[1],strlen(argv[1]),FileName);
	cout<<"文件名:"<<FileName<<endl;

	char FileExtName[128]={0};
	CPath::GetExtName(argv[1],strlen(argv[1]),FileExtName);
	cout<<"扩展名:"<<FileExtName<<endl;

	char FileShortName[128]={0};
	CPath::GetFileShortName(argv[1],strlen(argv[1]),FileShortName);
	cout<<"短文件名:"<<FileShortName<<endl;

	char FilePath[128]={0};
	CPath::GetPath(argv[1],strlen(argv[1]),FilePath);
	cout<<"文件路径:"<<FilePath<<endl;

	system("pause");
	return 0;
}