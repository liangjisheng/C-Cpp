
// 遍历strPath目录下的全部文件夹和文件
void TraversFile(CString strPath)
{
	if(strPath.Right(1) != '\\')	// 判断最后一个字符是不是'\\'
		strPath += _T("\\");

	CString NextPath = strPath;
	CFileFind ff;
	strPath += _T("*.*");		// 遍历这一级全部的目录
	int nRet = ff.FindFile(strPath);
	while(nRet)
	{
		nRet = ff.FindNextFile();
		if(ff.IsDirectory() && !ff.IsDots())		// 递归遍历
		{
			// cout<<ff.GetFilePath().GetBuffer(0)<<endl;
			CString tmp = ff.GetFilePath();
			cout<<tmp.GetBuffer(0)<<endl;
			tmp.ReleaseBuffer();
			NextPath += ff.GetFileName();
			NextPath += _T("\\");
			TraversFile(NextPath);
		}
		else
		{
			// cout<<ff.GetFilePath().GetBuffer(0)<<endl;
			CString tmp = ff.GetFilePath();
			cout<<tmp.GetBuffer(0)<<endl;
			tmp.ReleaseBuffer();
		}
	}
	ff.Close();
}