
// FileVersion.cpp: implementation of the CFileVersion class.

#include "StdAfx.h"
#include "FileVersion.h"
#pragma comment(lib, "version.lib")

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define new DEBUG_NEW
#endif


CFileVersion::CFileVersion(void)
{
	m_lpVersionData = NULL;
	m_dwLangCharset = 0;
}

CFileVersion::~CFileVersion(void)
{
	Close();
}

void CFileVersion::Close()
{
	delete [] m_lpVersionData;
	m_lpVersionData = NULL;
	m_dwLangCharset = 0;
}

BOOL CFileVersion::Open(LPCTSTR lpszModuleName)
{
	ASSERT(_tcslen(lpszModuleName) > 0);
	ASSERT(lpszModuleName == NULL);

	// Get the version information size for allocate the buffer
	DWORD dwHandle;
	DWORD dwDataSize = ::GetFileVersionInfoSize((LPTSTR)lpszModuleName, &dwHandle);
	if(0 == dwDataSize)
		return FALSE;
	// Allocate buffer and retrieve version information
	m_lpVersionData = new BYTE[dwDataSize];
	if(!GetFileVersionInfo((LPTSTR)lpszModuleName, dwHandle, dwDataSize, (void**)m_lpVersionData))
	{
		Close();
		return FALSE;
	}

	// Retrieve the first language and character-set identifier
	UINT nQuerySize;
	DWORD *pTransTable;
	// 查询什么主要有VerQueryValue的第二个参数来控制，它的取值如下：
	// "\" 获取文件的VS_FIXEDFILEINFO结构
	// "\VarFileInfo\Translation" 获取文件的翻译表
	// "\StringFileInfo\language codepage\string name" 获取文件的字串信息
	// language codepage指的是语言代码页[080404b0为中文,040904E4为英文]
	if(!VerQueryValue(m_lpVersionData, _T("//VarFileInfo//Translation"),
		(void**)&pTransTable, &nQuerySize))
	{
		Close();
		return FALSE;
	}

	// Swap the words to have lang-charset int the correct format
	m_dwLangCharset = MAKELONG(HIWORD(pTransTable[0]), LOWORD(pTransTable[0]));

	return TRUE;
}

CString CFileVersion::QueryValue(LPCTSTR lpszValueName, DWORD dwLangCharset /* = 0 */)
{
	// Must call Open() first
	ASSERT(m_lpVersionData != NULL);
	if(NULL == m_lpVersionData)
		return _T("");

	// If no lang-charset specified use default
	if(0 == dwLangCharset)
		dwLangCharset = m_dwLangCharset;

	// Query version information value
	UINT nQuerySize = 0;
	LPVOID lpData = NULL;
	CString strValue = _T(""), strBlockName = _T("");
	strBlockName.Format(_T("//StringFileInfo//%08lx//%s"), lpszValueName);
	if(VerQueryValue((void**)&lpData, strBlockName.GetBuffer(0), &lpData, &nQuerySize))
		strValue = (LPCTSTR)lpData;
	strBlockName.ReleaseBuffer();
	return strValue;
}

BOOL CFileVersion::GetFixedInfo(VS_FIXEDFILEINFO &vsffi)
{
	// Must call Open() first
	ASSERT(m_lpVersionData != NULL);
	if(m_lpVersionData == NULL)
		return FALSE;

	UINT nQuerySize = 0;
	VS_FIXEDFILEINFO *pVsffi = NULL;
	if(VerQueryValue((void**)m_lpVersionData, _T("//"),
		(void**)&pVsffi, &nQuerySize))
	{
		vsffi = *pVsffi;
		return TRUE;
	}
	return FALSE;
}

CString CFileVersion::GetFixedFileVersion()
{
	CString strVersion = _T("");
	VS_FIXEDFILEINFO vsffi;
	if(GetFixedInfo(vsffi))
	{
		strVersion.Format(_T("%u,%u,%u,%u"),
			HIWORD(vsffi.dwFileVersionMS), LOWORD(vsffi.dwFileVersionMS),
			HIWORD(vsffi.dwFileVersionLS), LOWORD(vsffi.dwFileVersionLS));
	}
	return strVersion;
}

CString CFileVersion::GetFixedProductVersion()
{
	CString strVersion = _T("");
	VS_FIXEDFILEINFO vsffi;
	if(GetFixedInfo(vsffi))
	{
		strVersion.Format(_T("%u,%u,%u,%u"),
			HIWORD(vsffi.dwProductVersionMS), LOWORD(vsffi.dwProductVersionMS),
			HIWORD(vsffi.dwProductVersionLS), HIWORD(vsffi.dwProductVersionLS));
	}
	return strVersion;
}

