// 使用API函数进行文件操作
/*HANDLE CreateFile(
	LPCTSTR lpFileName,
	DWORD dwDesiredAccess,	// 访问控制
	DWORD dwShareMode,		// 共享控制
	LPSECURITY_ATTIRBUTE lpSecurityAttribute,
	DWORD dwCreationDisposition,	// 创建方式
	DWORD dwFlagsAndAttribute,		// 文件的新属性
	HANDLE hTemplateFile			// 文件模板句柄，一般为NULL
	); */
/*BOOL ReadFile(
	HANDLE hFile,
	LPVOID lpBuffer,
	DWORD nNumberofBytesToRead,		// 要读取的字节数
	LPDWORD lpNumberOfBytesRead,	// 实际读取的字节数
	LPOVERLAPPED lpOverlapped		// 指向结构体lpOverlapped,一般为NULL
	);
BOOL WriteFile(
	HANDLE hFile,
	LPVOID lpBuffer,
	DWORD nNumberofBytesToRead,		// 要读取的字节数
	LPDWORD lpNumberOfBytesRead,	// 实际读取的字节数
	LPOVERLAPPED lpOverlapped		// 指向结构体lpOverlapped,一般为NULL
	);*/

HANDLE hFile;
hFile=::CreateFile("E:\\VC++\\MyProjects\\1047\\ReadMe.txt",
	GENERIC_READ,FILE_SHARE_DELETE | FILE_SHARE_READ | FILE_SHARE_WRITE,
	NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
if(hFile==INVALID_HANDLE_VALUE)
	AfxMessageBox("文件创建失败");
else {
	DWORD nFileSize=::GetFileSize(hFile,NULL);
	char *lpBuffer=new char[nFileSize+1];
	DWORD nNumberOfBytesRead;
	BOOL bRet=::ReadFile(hFile,lpBuffer,nFileSize,&nNumberOfBytesRead,NULL);
	lpBuffer[nFileSize]='\0';
	cout<<lpBuffer<<endl;
	// printf("%s\n",lpBuffer);
	// MessageBox(NULL,lpBuffer,"title",MB_OK);

	delete [] lpBuffer;
	::CloseHandle(hFile);
}

hFile=::CreateFile("E:\\VC++\\MyProjects\\1047\\lishuyu.txt",
	GENERIC_WRITE,0,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
if(hFile==INVALID_HANDLE_VALUE)
	AfxMessageBox("文件创建失败");
else {
	char Text[]="lishuyu and liangjisheng";
	DWORD nTextSize=sizeof(Text);
	DWORD nNumberOfBytesWrite;
	::WriteFile(hFile,Text,nTextSize,&nNumberOfBytesWrite,NULL);
	AfxMessageBox("文件写入成功");
	::CloseHandle(hFile);
}

hFile=::CreateFile("E:\\VC++\\MyProjects\\1047\\lishuyu.txt",
	GENERIC_READ,0,NULL,OPEN_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
if(hFile==INVALID_HANDLE_VALUE)
	AfxMessageBox("文件打开失败");
else {
	DWORD nFileSize=::GetFileSize(hFile,NULL);
	char *lpBuffer=new char[nFileSize];
	DWORD nNumberOfBytesRead;
	::ReadFile(hFile,lpBuffer,nFileSize,&nNumberOfBytesRead,NULL);
	AfxMessageBox("文件读取成功");
	printf("\n\n\n%s\n",lpBuffer);
	delete [] lpBuffer;
	::CloseHandle(hFile);
}