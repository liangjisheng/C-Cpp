
// 遍历strPath目录下的所有文件夹和文件
void GetFolderTxtFile(CString strPath,CStringArray& arrStrFile)
{
	if(strPath.Right(1) != '\\')
		strPath += _T("\\");
	CString NextPath = strPath;
	NextPath += _T("*.*");

	CFileFind find;
	int nRet = find.FindFile(NextPath);
	while(nRet)
	{
		nRet = find.FindNextFile();
		if(!find.IsDots())
		{
			CString path = find.GetFilePath();
			if(find.IsDirectory())	// 文件夹，递归遍历
				GetFolderTxtFile(path,arrStrFile);
			else
			{
				// 如果是文件，判断是不是*.txt
				CString fileExtName = path.Right(4);
				fileExtName.MakeLower();	// 转换成小写
				if(_T(".txt") == fileExtName)
					arrStrFile.Add(path);
			}
		}
	}
	find.Close();
}