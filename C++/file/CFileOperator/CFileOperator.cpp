
#include "stdafx.h"
#include "CFileOperator.h"

#include <fstream>
using std::ifstream;

int CFileOperator::s_nItemsNum = 0;

#include <io.h>			// _access()

BOOL CFileOperator::IsFileExist(const CString& strFilePath)
{
	DWORD dwAttrib = GetFileAttributes(strFilePath);
	return INVALID_FILE_ATTRIBUTES != dwAttrib && 0 == (dwAttrib & FILE_ATTRIBUTE_DIRECTORY);
}

bool CFileOperator::IsFileExist_1(const char *filePath)
{
	/**
	 * int access(const char *filename, int amode);
	 * amode参数为0时表示检查文件的存在性，如果文件存在，返回0，不存在，返回-1
	 * 06     检查读写权限 
	 * 04     检查读权限 
	 * 02     检查写权限 
	 * 01     检查执行权限 
	*/
	int nRet = _access(filePath, 0);
	if (0 == nRet) return true;
	else return false;
}

BOOL CFileOperator::IsDirExist(const CString& strDirPath)
{
	DWORD dwAttrib = GetFileAttributes(strDirPath);
	return INVALID_FILE_ATTRIBUTES != dwAttrib && 0 != (dwAttrib & FILE_ATTRIBUTE_DIRECTORY);
}

BOOL CFileOperator::IsPathExist(const CString& strPath)
{
	DWORD dwAttrib = GetFileAttributes(strPath);
	return INVALID_FILE_ATTRIBUTES != dwAttrib;
}

BOOL CFileOperator::IsPathExist_1(const CString & strPath)
{
	WIN32_FILE_ATTRIBUTE_DATA attrs = { 0 };
	return 0 != GetFileAttributesEx(strPath, GetFileExInfoStandard, &attrs);
}

int CFileOperator::GetFileContent(char **buffer, const char *filePath)
{
	int fileLength = 0;
	FILE *fp = fopen(filePath,"rb");
	if (NULL == fp)
		return 0;

	fseek(fp,0,SEEK_END);
	fileLength = ftell(fp);
	rewind(fp);

	*buffer = new char[fileLength+1];
	memset(*buffer,0,fileLength+1);
	fseek(fp,0,SEEK_SET);
	fread(*buffer,sizeof(char),fileLength,fp);
	fclose(fp);
	return fileLength;
}

int CFileOperator::GetFileLength(const char *filePath)
{
	if (NULL == filePath)
		return 0;

	ifstream ifs(filePath, std::ios_base::in | std::ios_base::binary);
	ifs.seekg(0, std::ios_base::end);
	long nLen = ifs.tellg();
	ifs.close();

	return nLen;
}

void CFileOperator::WriteTmpFile(const CString &strContent, CString &strTmpFilePath)
{
	TCHAR szTempPath[MAX_PATH] = {0};
	TCHAR szTmpFile[MAX_PATH] = {0};
	// 获取临时文件路径
	GetTempPath(MAX_PATH, szTempPath);
	// 获取临时文件名，第一个参数为建立此临时文件的路径，第二个参数是建立临时文件名的前缀
	// 第四个参数用于得到建立的临时文件名
	GetTempFileName(szTempPath, _T("my"), 0, szTmpFile);
	strTmpFilePath = szTmpFile;

	CFile file(szTmpFile, CFile::modeCreate | CFile::modeWrite);
	file.Write(strContent, strContent.GetLength() * sizeof(TCHAR));
	file.Close();
}

int CFileOperator::GetPointerFile(const CString& strDirPath, const CString& strSuffixName, 
	std::vector<CString>& vecFileName)
{
	if (strDirPath == _T("") || strSuffixName == _T(""))
		return 0;

	// 如果是文件则直接返回
	if (IsFileExist(strDirPath))
		return 0;

	if (!IsDirExist(strDirPath))
		return 0;

	CString strFilePath = strDirPath;
	if (strFilePath[strFilePath.GetLength() - 1] != _T('\\'))
		strFilePath += _T("\\");

	CString strFileSuffixName = strSuffixName;
	if (strFileSuffixName[0] != _T('.'))
		strFileSuffixName = _T(".") + strFileSuffixName;

	WIN32_FIND_DATA FindFileData;
	CString strFileName = strFilePath + _T("*.*");

	HANDLE hFind = ::FindFirstFile(strFileName, &FindFileData);
	if (INVALID_HANDLE_VALUE == hFind)
		return 0;

	while (TRUE)
	{
		if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			if (FindFileData.cFileName[0] != _T('.'))
				GetPointerFile(strFilePath + FindFileData.cFileName, strFileSuffixName, vecFileName);
		}
		else
		{
			CString strFindFile(FindFileData.cFileName);
			if (strFindFile.Right(strFileSuffixName.GetLength() - 1) == strSuffixName.Right(strFileSuffixName.GetLength() - 1) 
				&& strFindFile[strFindFile.GetLength() - strFileSuffixName.GetLength()] == _T('.'))
			{
				vecFileName.push_back(strFilePath + FindFileData.cFileName);
			}
		}

		if (!FindNextFile(hFind, &FindFileData))
			break;
	}

	return vecFileName.size();
}

int CFileOperator::DeletePointerFile(const CString& strDirPath, const CString& strSuffixName)
{
	if (strDirPath == _T("") || strSuffixName == _T(""))
		return 0;

	std::vector<CString> vecFileName;
	int num = GetPointerFile(strDirPath, strSuffixName, vecFileName);

	for (int i = 0; i < vecFileName.size(); ++i)
		DeleteFile(vecFileName[i]);

	return num;
}

int CFileOperator::GetAllItems(const CString& strDirPath, std::vector<CString>& vecName)
{
	if (strDirPath == _T(""))
		return 0;

	if (IsFileExist(strDirPath))
	{
		vecName.push_back(strDirPath);
		return 1;
	}

	if (!IsDirExist(strDirPath))
		return 0;

	CString strPath = strDirPath;
	if (strPath[strPath.GetLength() - 1] != _T('\\'))
		strPath += _T("\\");

	CFileFind tmpFind;
	BOOL bFound = tmpFind.FindFile(strPath + _T("*.*"));

	while (bFound)
	{
		// 第一次执行FindNextFile是选择到第一个文件，以后执行为选择到下一个文件  
		bFound = tmpFind.FindNextFile();

		if (tmpFind.IsDots())
			continue;

		if (tmpFind.IsDirectory())
		{
			CString strDir = tmpFind.GetFilePath();
			if (strDir[strDir.GetLength() - 1] != _T('\\'))
				strDir += _T("\\");
			vecName.push_back(strDir);
			GetAllItems(strDir, vecName);
		}
		else
		{
			CString strFile = tmpFind.GetFilePath();
			vecName.push_back(strFile);
		}
	}

	tmpFind.Close();
	return vecName.size();
}

int CFileOperator::GetAllItems_1(const CString& strDirPath, std::vector<CString>& vecName)
{
	if (strDirPath == _T(""))
		return 0;

	// 如果是文件则直接返回
	if (IsFileExist(strDirPath))
		return 0;

	if (!IsDirExist(strDirPath))
		return 0;

	CString strFilePath = strDirPath;
	if (strFilePath[strFilePath.GetLength() - 1] != _T('\\'))
		strFilePath += _T("\\");

	WIN32_FIND_DATA FindFileData;
	CString strFileName = strFilePath + _T("*.*");

	HANDLE hFind = ::FindFirstFile(strFileName, &FindFileData);
	if (INVALID_HANDLE_VALUE == hFind)
		return 0;

	while (TRUE)
	{
		if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			if (FindFileData.cFileName[0] == _T('.'))
			{
				if (!FindNextFile(hFind, &FindFileData))
					break;
				continue;
			}

			CString strDir = strFilePath + FindFileData.cFileName;
			if (strDir[strDir.GetLength() - 1] != _T('\\'))
				strDir += _T("\\");

			vecName.push_back(strDir);
			GetAllItems_1(strDir, vecName);
		}
		else
			vecName.push_back(strFilePath + FindFileData.cFileName);

		if (!FindNextFile(hFind, &FindFileData))
			break;
	}

	return vecName.size();
}

int CFileOperator::GetAllDirs(const CString& strDirPath, std::vector<CString>& vecName)
{
	if (strDirPath == _T(""))
		return 0;

	if (IsFileExist(strDirPath))
	{
		vecName.push_back(strDirPath);
		return 1;
	}

	if (!IsDirExist(strDirPath))
		return 0;

	CString strPath = strDirPath;
	if (strPath[strPath.GetLength() - 1] != _T('\\'))
		strPath += _T("\\");

	CFileFind tmpFind;
	BOOL bFound = tmpFind.FindFile(strPath + _T("*.*"));

	while (bFound)
	{
		// 第一次执行FindNextFile是选择到第一个文件，以后执行为选择到下一个文件  
		bFound = tmpFind.FindNextFile();

		if (tmpFind.IsDots())
			continue;

		if (tmpFind.IsDirectory())
		{
			CString strDir = tmpFind.GetFilePath();
			if (strDir[strDir.GetLength() - 1] != _T('\\'))
				strDir += _T("\\");
			vecName.push_back(strDir);
			GetAllDirs(strDir, vecName);
		}
		//else
		//{
		//	CString strFile = tmpFind.GetFilePath();
		//	vecName.push_back(strFile);
		//}
	}

	tmpFind.Close();
	return vecName.size();
}

int CFileOperator::GetAllFile(const CString& strDirPath, std::vector<CString>& vecName)
{
	if (strDirPath == _T(""))
		return 0;

	if (IsFileExist(strDirPath))
	{
		vecName.push_back(strDirPath);
		return 1;
	}

	if (!IsDirExist(strDirPath))
		return 0;

	CString strPath = strDirPath;
	if (strPath[strPath.GetLength() - 1] != _T('\\'))
		strPath += _T("\\");

	CFileFind tmpFind;
	BOOL bFound = tmpFind.FindFile(strPath + _T("*.*"));

	while (bFound)
	{
		// 第一次执行FindNextFile是选择到第一个文件，以后执行为选择到下一个文件  
		bFound = tmpFind.FindNextFile();

		if (tmpFind.IsDots())
			continue;

		if (tmpFind.IsDirectory())
		{
			CString strDir = tmpFind.GetFilePath();
			if (strDir[strDir.GetLength() - 1] != _T('\\'))
				strDir += _T("\\");
			//vecName.push_back(strDir);
			GetAllFile(strDir, vecName);
		}
		else
		{
			CString strFile = tmpFind.GetFilePath();
			vecName.push_back(strFile);
		}
	}

	tmpFind.Close();
	return vecName.size();
}

int CFileOperator::DeleteAllItems(const CString& strDirPath, std::vector<CString>& vecName)
{
	if (strDirPath == _T(""))
		return 0;

	if (IsFileExist(strDirPath))
	{
		if (DeleteFile(strDirPath))
		{
			vecName.push_back(strDirPath);
			return 1;
		}
		else
			return 0;
	}

	if (!IsDirExist(strDirPath))
		return 0;

	CString strPath = strDirPath;
	if (strPath[strPath.GetLength() - 1] != _T('\\'))
		strPath += _T("\\");

	CFileFind tmpFind;
	BOOL bFound = tmpFind.FindFile(strPath + _T("*.*"));

	while (bFound)
	{
		// 第一次执行FindNextFile是选择到第一个文件，以后执行为选择到下一个文件  
		bFound = tmpFind.FindNextFile();

		if (tmpFind.IsDots())
			continue;

		if (tmpFind.IsDirectory())
		{
			CString strDir = tmpFind.GetFilePath();
			if (strDir[strDir.GetLength() - 1] != _T('\\'))
				strDir += _T("\\");
			vecName.push_back(strDir);
			DeleteAllItems(strDir, vecName);
			RemoveDirectory(strDir);
		}
		else
		{
			CString strFile = tmpFind.GetFilePath();
			DeleteFile(strFile);
			vecName.push_back(strFile);
		}
	}

	tmpFind.Close();
	return vecName.size();
}

int CFileOperator::GetAllPointerDir(const CString& strDirPath, const CString& strPointerDir, 
	std::vector<CString>& vecName)
{
	if (strDirPath == _T("") || strPointerDir == _T(""))
		return 0;

	if (IsFileExist(strDirPath))
	{
		vecName.push_back(strDirPath);
		return 1;
	}

	if (!IsDirExist(strDirPath))
		return 0;

	CString strPath = strDirPath;
	if (strPath[strPath.GetLength() - 1] != _T('\\'))
		strPath += _T("\\");

	CFileFind tmpFind;
	BOOL bFound = tmpFind.FindFile(strPath + _T("*.*"));

	while (bFound)
	{
		// 第一次执行FindNextFile是选择到第一个文件，以后执行为选择到下一个文件  
		bFound = tmpFind.FindNextFile();

		if (tmpFind.IsDots())
			continue;

		if (tmpFind.IsDirectory())
		{
			CString strDir = tmpFind.GetFilePath();
			if (strDir[strDir.GetLength() - 1] == _T('\\'))
				strDir = strDir.Left(strDir.GetLength() - 1);
			CString strTmp = strDir.Right(strDir.GetLength() - strDir.ReverseFind(_T('\\')) - 1);
			if (strTmp == strPointerDir)
			{
				strTmp = tmpFind.GetFilePath();
				if (strTmp[strTmp.GetLength() - 1] != _T('\\'))
					strTmp += _T("\\");
				vecName.push_back(strTmp);
			}
			if (strDir[strDir.GetLength() - 1] != _T('\\'))
				strDir += _T("\\");
			GetAllPointerDir(strDir, strPointerDir, vecName);
		}
		//else
		//{
		//	CString strFile = tmpFind.GetFilePath();
		//	vecName.push_back(strFile);
		//}
	}

	tmpFind.Close();
	return vecName.size();
}

