
// win32 API 遍历指定目录及子目录下的所有文件, 输出到指定的文件

#include <stdio.h>
#include <string.h>
#include <windows.h>

FILE* pf_path_file;		// 文件结构指针

int find_path_save_file(const char* lp_path,const char* out_file_name);
int find_path(const char* lp_path);

int main(void)
{
//	char dir[256] = {0};
//	char out_file_name[256] = {0};
//	printf("input the point directory:\n");
//	scanf("%s",&dir);
//	printf("input the outfilename:\n");
//	scanf("%s",&out_file_name);

	char dir[] = "D:\\test\\";
	char out_file_name[] = "D:\\test\\filepath.txt";

	int dirLen = strlen(dir);
	if(dir[dirLen-1] != '\\')
		strcat(dir,"\\");

	int nFileCount = find_path_save_file(dir,out_file_name);
	printf("Sum of file = %d\n",nFileCount);

	getchar();
	return 0;
}

int find_path_save_file(const char* lp_path,const char* out_file_name)
{
	pf_path_file = fopen(out_file_name,"w");
	int cnt = find_path(lp_path);
	fclose(pf_path_file);
	return cnt;
}

int find_path(const char* lp_path)
{
	static int cnt = 0;	// 函数要递归调用，cnt必须为static,记录文件个数
	HANDLE hFile;		// windows对文件的操作首先要得到一个文件句柄
	FILETIME ft;		// 文件时间
	SYSTEMTIME st;		// 系统时间
	WIN32_FIND_DATAA wfd;	// windows定义的查找文件的结构
	char sz_path[MAX_PATH] = {0};
	char buf[MAX_PATH * 2] = {0};
	strcpy(sz_path,lp_path);
	int tmpLen = strlen(sz_path);
	if(sz_path[tmpLen - 1] != '\\')
		strcat(sz_path,"\\");
	strcat(sz_path,"*.*");
	// sz_path可以是绝对路径也可以是相对路径
	// 如果找到文件，返回文件句柄，并填充wfd结构
	hFile = FindFirstFile(sz_path,&wfd);

	if(hFile != INVALID_HANDLE_VALUE)	// 文件句柄可用
	{
		// 找到文件，返回true,并填充wfd
		while(FindNextFile(hFile,&wfd))	
		{
			// 当前目录. 上级目录..跳过去
			if(wfd.cFileName[0] == '.')
				continue;
			if(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				// 如果是文件夹，递归遍历
				strcpy(sz_path,lp_path);
				strcat(sz_path,wfd.cFileName);
				find_path(sz_path);
			}
			else
			{
				ft = wfd.ftLastWriteTime;
				FileTimeToSystemTime(&ft,&st);
				sprintf(buf,"%d-%02d-%02d %02d:%02d %10u | ",
					st.wYear,st.wMonth,st.wDay,st.wHour+8,st.wMinute,wfd.nFileSizeLow);
				sprintf(buf + 30,"%s | %s",wfd.cFileName,lp_path);
				fprintf(pf_path_file,"%s\n",buf);
				++cnt;
			}
		}
	}
	return cnt;
}