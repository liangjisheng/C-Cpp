// 在指定目录下查找文件
#include"io.h"
#include"string.h"
#include"iostream"
using namespace std;

const int MAXLEN=1024;
unsigned long FILECOUNT=0;
// 递归函数，实现指定目录的遍历
void ListDir(const char* pchData,const char* pFileName,bool* pBool)
{
	_finddata_t fdata;	// 定义文件查找结构对象
	long done;
	char tempdir[MAXLEN]={0};	// 临时字符数组，存储目录
	strcat(tempdir,pchData);
	strcat(tempdir,"\\*.*");
	done=_findfirst(tempdir,&fdata);	// 开始查找文件
	if(done!=-1) {
		int ret=0;
		while(ret!=-1) {
			if(fdata.attrib!=_A_SUBDIR) {
				if(strcmp(fdata.name,"...")!=0 &&
					strcmp(fdata.name,"..")!=0 && 
					strcmp(fdata.name,".")!=0)	// 过滤
				{
					char dir[MAXLEN]={0};
					strcat(dir,pchData);
					strcat(dir,"\\");
					strcat(dir,fdata.name);
					cout<<dir<<endl;
					FILECOUNT++;
					if(strcmp(fdata.name,pFileName)==0)
						break;
				}
			}
			ret=_findnext(done,&fdata);
			if(fdata.attrib==_A_SUBDIR && ret!=-1)	// 判断文件属性，如果是目录，则递归调用
			{
				if(strcmp(fdata.name,"...")!=0 &&
					strcmp(fdata.name,"..")!=0 &&
					strcmp(fdata.name,".")!=0)
				{
					char pdir[MAXLEN]={0};
					strcat(pdir,pchData);
					strcat(pdir,"\\");
					strcat(pdir,fdata.name);
					ListDir(pdir,pFileName,pBool);
					if(*pBool)
						break;
				}
			}
		}
	}
}

int main(int argc,char * argv[])
{
	while(true) {
		FILECOUNT=0;
		char szFileDir[128]={0};
		char szFileName[128]={0};
		bool isFind=false;
		cin>>szFileDir;
		cin>>szFileName;
		if(strcmp(szFileDir,"e")==0)	// 退出系统
			break;
		ListDir(szFileDir,szFileName,&isFind);
		cout<<"共计"<<FILECOUNT<<"个文件"<<endl;
	}
	return 0;
}
