
//CStatic	m_SavePath;
//CStatic	m_OpenPath;
//CEdit	m_FileText;
	
void CFileDialogDlg::OnOpen()
{
	CFileDialog dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		"All Files(*.txt)|*.txt||",AfxGetMainWnd());
	CString strPath,strText="";
	if(dlg.DoModal() == IDOK)
	{
		strPath = dlg.GetPathName();
		m_OpenPath.SetWindowText(strPath);
		CFile file(strPath,CFile::modeRead);	// 打开文件
		char read[102400];
		file.Read(read,102400);
		for(int i=0;i<file.GetLength();i++)
			strText += read[i];
		file.Close();
		m_FileText.SetWindowText(strText);	// 显示文件内容
	}
}

void CFileDialogDlg::OnSave() 
{
	CFileDialog dlg(FALSE,NULL,NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		"All Files(*.txt)|*.txt||",AfxGetMainWnd());
	CString strPath,strText="";
	char write[1024];
	if(dlg.DoModal() == IDOK)
	{
		strPath = dlg.GetPathName();
		m_SavePath.SetWindowText(strPath);
		if(strPath.Right(4) != ".txt")
			strPath += ".txt";
		CFile file(_T(strPath),CFile::modeCreate | CFile::modeWrite);
		m_FileText.GetWindowText(strText);
		strcpy(write,strText);
		file.Write(write,strText.GetLength());
		file.Close();
	}
}