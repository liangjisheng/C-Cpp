
//CEdit	m_FileName;
//CComboBox	m_Disk;

void CFindFileDlg::EnumDisk()
{
	DWORD dirLen = GetLogicalDriveStrings(0,NULL);	// 获取字符串长度
	HANDLE hp = GetProcessHeap();			// 获取进程堆句柄
	LPSTR pdir = (LPSTR)HeapAlloc(hp,HEAP_ZERO_MEMORY,dirLen);	// 在堆中分配空间
	GetLogicalDriveStrings(dirLen,pdir);	// 获取磁盘目录字符串
	LPSTR ptmp = pdir;		// 临时指针
	while(*pdir !=0)
	{
		m_Disk.AddString(pdir);		// 向组合框中添加磁盘名称
		pdir = strchr(pdir,0) + 1;	// 查找下一个磁盘名称
	}
	HeapFree(hp,HEAP_NO_SERIALIZE,ptmp);	// 释放堆空间
}

void CFindFileDlg::OnButtonFind() 
{
	CString filename,dir,findret;
	BOOL result = FALSE;			// 记录查找结果
	m_FileName.GetWindowText(filename);
	m_Disk.GetWindowText(dir);

	if(!filename.IsEmpty() && !dir.IsEmpty())
	{
		CFileFind flFind;
		// dir += _T("*.*");
		strcat(dir.GetBuffer(0),"*.*");
		dir.ReleaseBuffer();
		flFind.MatchesMask(FILE_ATTRIBUTE_NORMAL);	// 设置要查找的文件属性
		BOOL ret = flFind.FindFile(dir);
		while(ret)		// 遍历当前目录
		{
			if(flFind.IsDots())		// . 代表当前目录 .. 代表父级目录
				continue;
			ret = flFind.FindNextFile();
			if(TRUE == ret)
			{
				findret = flFind.GetFileName();	
				if(findret == filename)
				{ result = TRUE; break; }
			}
		}
		if(result)
		{
			CString strHint = "发现文件，位于: ";
			strHint += flFind.GetFilePath();
			flFind.Close();
			MessageBox(strHint,"Title",MB_OKCANCEL | MB_ICONINFORMATION);
		}
	}
}
