void CBrowseFolderDlg::OnGetbrowse() 
{
	CString ReturnPath;
	TCHAR szPath[_MAX_PATH];	// 保存路径变量
	BROWSEINFO bi;
	bi.hwndOwner = NULL;	// HWND句柄
	bi.pidlRoot = NULL;		// 默认值为NULL
	bi.lpszTitle =_T("文件浏览对话库");	// 对话库标题
	bi.pszDisplayName = szPath;		// 选择文件夹路径
	bi.ulFlags = BIF_RETURNONLYFSDIRS;	// 标记
	bi.lpfn = NULL;			// 默认值为NULL
	bi.lParam = NULL;		// 回调消息
	// 显示浏览文件对话库
	LPITEMIDLIST pItemIDList = SHBrowseForFolder(&bi);
	if(pItemIDList)
	{
		if(SHGetPathFromIDList(pItemIDList,szPath))	// 判断是否获得文件夹路径
			ReturnPath = szPath;					// 获取文件夹路径
	}
	else
		ReturnPath = "";	// 路径为空
	m_Path.SetWindowText(ReturnPath);
}
