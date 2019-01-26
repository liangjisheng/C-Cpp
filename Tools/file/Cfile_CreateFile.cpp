void CMy11231Dlg::OnBnClickedButtonStdiofile()
{
	CStdioFile mFile;
	CFileException mExcept;
	BOOL bOpen = mFile.Open(_T("CStdioFile.txt"), 
		CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite,
		&mExcept);

	if (bOpen)
	{
		CString str("I am a CString\r\n");
		mFile.WriteString(str);
		str = _T("I am an another CString\r\n");
		mFile.WriteString(str);
		mFile.Close();
		AfxMessageBox(_T("write ok"));
	}
	else
		AfxMessageBox(_T("open file failed"));
}


void CMy11231Dlg::OnBnClickedButton2()
{
	TCHAR szTempPath[MAX_PATH] = {0};
	TCHAR szTmpFile[MAX_PATH] = {0};
	// 获取临时文件路径
	GetTempPath(MAX_PATH, szTempPath);
	// 获取临时文件名，第一个参数为建立此临时文件的路径，第二个参数是建立临时文件名的前缀
	// 第四个参数用于得到建立的临时文件名
	GetTempFileName(szTempPath, _T("my"), 0, szTmpFile);
	LPCTSTR pszContent = _T("test");
	CFile file(szTmpFile, CFile::modeCreate | CFile::modeWrite);
	file.Write(pszContent, _tcslen(pszContent) * sizeof(TCHAR));
	file.Close();
}


void CMy11231Dlg::OnBnClickedButton3()
{
	HANDLE handle;
	DWORD dwNum = 0;
	// FILE_FLAG_DELETE_ON_CLOSE
	handle = CreateFile(_T("test.txt"), GENERIC_READ | GENERIC_WRITE, 0, NULL, 
		OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (INVALID_HANDLE_VALUE != handle)
	{
		SetFilePointer(handle, 0, 0, FILE_BEGIN);
		TCHAR szBuf[] = _T("Just create this file");
		WriteFile(handle, szBuf, sizeof(szBuf), &dwNum, NULL);
		// 将szBuf置为空后，不能在使用_tcslen(szBuf)来获取szBuf的字符长度，
		// 此时_tcslen(szBuf)得到的长度为0，应该使用sizeof(szBuf)得到szBuf的字节长度
		ZeroMemory(szBuf, sizeof(szBuf));
		SetFilePointer(handle, 0, 0, FILE_BEGIN);
		ReadFile(handle, szBuf, sizeof(szBuf), &dwNum, NULL);
		AfxMessageBox(szBuf);
		CloseHandle(handle);
	}
}


void CMy11231Dlg::OnBnClickedButton4()
{
	CFileStatus status;
	LPCTSTR pszPath = _T("D:\\test.txt");
	if (CFile::GetStatus(pszPath, status))
	{
		CString cTime, mTime, aTime;
		cTime = status.m_ctime.Format(_T("文件建立时间: %Y年%m月%d日 %H时%M分%S秒"));
		mTime = status.m_mtime.Format(_T("文件最近修改时间: %Y年%m月%d日 %H时%M分%S秒"));
		aTime = status.m_atime.Format(_T("文件最近访问时间: %Y年%m月%d日 %H时%M分%S秒"));
		CString str = pszPath;
		str = str + _T("\r\n") + cTime + _T("\r\n") + mTime + _T("\r\n") + aTime + _T("\r\n");
		AfxMessageBox(str);
	}
}


void CMy11231Dlg::OnBnClickedButton5()
{
	LPCTSTR pszPath = _T("D:\\test.txt");
	HANDLE handle;
	WIN32_FIND_DATA find_data;
	handle = FindFirstFile(pszPath, &find_data);
	FindClose(handle);
	find_data.dwFileAttributes |= FILE_ATTRIBUTE_READONLY;
	SetFileAttributes(pszPath, find_data.dwFileAttributes);
}
