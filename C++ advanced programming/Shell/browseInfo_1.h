void Cbrowseinfo_1Dlg::OnBnClickedButton1()
{
	BROWSEINFO bi;
	wchar_t Buffer[MAX_PATH] = {0};
	wchar_t szResult[MAX_PATH] = {0};
	ITEMIDLIST *ppidl;
	wchar_t strCurrentPath[MAX_PATH] = _T("C:\\");

	// CSIDL_DRIVES 是我的电脑的ID，用这个参数设置根目录就是我的电脑
	// 常用的有CSIDL_DESKTOP(桌面),CSIDL_PROGRAMS(开始菜单),CSIDL_MYMUSIC(我的音乐)
	// 将我的电脑的目录，获取到ppidl中
	SHGetSpecialFolderLocation(m_hWnd, CSIDL_DRIVES, &ppidl);
	if(NULL == ppidl)
		AfxMessageBox(_T("启动路径浏览失败"));

	// 初始化时浏览文件夹的路径
	TCHAR szPath[MAX_PATH] = _T("C:\\Users\\Administrator\\Desktop");
	// 初始化入口参数bi开始
	bi.hwndOwner = this->GetSafeHwnd();
	bi.pidlRoot = ppidl;
	bi.pszDisplayName = NULL;
	bi.lpszTitle = _T("Custom Title");
	bi.ulFlags = BIF_DONTGOBELOWDOMAIN | BIF_RETURNONLYFSDIRS | BIF_NEWDIALOGSTYLE;
	bi.lpfn = _SHBrowseForFolderCallbackProc;
	bi.lParam = LPARAM(szPath);

	// 初始化入口参数bi结束,调用显示选择对话框
	LPITEMIDLIST pIDList = SHBrowseForFolder(&bi);
	if(pIDList)		// 如果点击确定
		SHGetPathFromIDList(pIDList, szResult);

	AfxMessageBox(CString(szResult));

	LPMALLOC lpMalloc;
	if(FAILED(SHGetMalloc(&lpMalloc)))
		return ;
	lpMalloc->Free(pIDList);
	lpMalloc->Release();
}


// 定义的回调函数
int Cbrowseinfo_1Dlg::_SHBrowseForFolderCallbackProc(HWND hwnd, UINT uMsg, LPARAM lParam, LPARAM lpData)
{
	char curr[MAX_PATH] = {0};
	switch(uMsg)
	{
	case BFFM_INITIALIZED:
		// 传递默认打开路径
		::SendMessage(hwnd, BFFM_SETSELECTION, TRUE, lpData);
		break;

		// 选择路径变化，
	case BFFM_SELCHANGED:		
		SHGetPathFromIDList((LPITEMIDLIST)lParam, (LPWSTR)(LPCTSTR)curr);
		::SendMessage(hwnd, BFFM_SETSTATUSTEXT, 0, (LPARAM)&curr[0]);
		break;
	default:
		break;
	}
	return 0;
}
