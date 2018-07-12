
/**********************************************************************
 * �ļ���:RegOperator.cpp
 * �ļ�����:��ͷ�ļ��ж������ĳ�Ա����������ʵ��
 * ������:����ʥ 20171104
 * �汾��:1.0
 * �޸ļ�¼:
***********************************************************************/

#include "RegOperator.h"

/***********************************************************************
 * �� �� ��: s2ws
 * ��    ��: const std::string& [IN]
 * ��������: ���ֽ�ת���ַ�
 * �� �� ֵ: Ŀ����ַ�
 * �׳��쳣��
***********************************************************************/
const std::wstring CRegOperator::s2ws(const std::string &s)
{
	// locale old_loc = locale::global(locale(""));

	const char* src_str = s.c_str();
	const size_t buffer_size = s.size() + 1;
	wchar_t* dst_wstr = new wchar_t[buffer_size];
	wmemset(dst_wstr, 0, buffer_size);
	mbstowcs(dst_wstr, src_str, buffer_size);
	wstring result = dst_wstr;
	delete []dst_wstr;
	dst_wstr = NULL;

	// locale::global(old_loc);
	return result;
}

/***********************************************************************
 * �� �� ��: ws2s
 * ��    ��: const std::wstring& [IN]
 * ��������: ���ַ�ת���ֽ�
 * �� �� ֵ: Ŀ����ֽ�
 * �׳��쳣��
***********************************************************************/
const std::string CRegOperator::ws2s(const std::wstring& ws)
{
	// locale old_loc = locale::global(locale(""));

	const wchar_t* src_wstr = ws.c_str();
	size_t buffer_size = ws.size() * 4 + 1;
	char* dst_src = new char[buffer_size];
	memset(dst_src, 0, buffer_size);
	wcstombs(dst_src, src_wstr, buffer_size);
	string result = dst_src;
	delete [] dst_src;
	dst_src = NULL;

	// locale::global(old_loc);
	return result;
}

/***********************************************************************
 * �� �� ��: CRegOperator
 * ��    ��: HKEY [IN] : Ĭ����HKEY_LOCAL_MACHINE
 * ��������: ���캯������ʼ������
 * �� �� ֵ: ��
 * �׳��쳣��
***********************************************************************/
CRegOperator::CRegOperator(HKEY hkey /* = HKEY_LOCAL_MACHINE */)
{
	m_hKey = hkey;
}

/***********************************************************************
 * �� �� ��: ~CRegOperator
 * ��    ��: NULL [IN]
 * ��������: �����������رմ򿪵�ע�����
 * �� �� ֵ: ��
 * �׳��쳣��
***********************************************************************/
CRegOperator::~CRegOperator()
{
	Close();
}

/***********************************************************************
 * �� �� ��: Close
 * ��    ��: NULL [IN]
 * ��������: �رմ򿪼��ľ��
 * �� �� ֵ: void
 * �׳��쳣��
***********************************************************************/
void CRegOperator::Close()
{
	if(m_hKey)
	{
		RegCloseKey(m_hKey);
		m_hKey = NULL;
	}
}

/***********************************************************************
 * �� �� ��: SetHKEY
 * ��    ��: LPCTSTR [IN] : ����ֵ
 * ��������: �ɴ���ĸ����ַ������õ�ǰ�����ĸ�����ֵ
 * �� �� ֵ: void
 * �׳��쳣��
***********************************************************************/
bool CRegOperator::SetHKEY(LPCTSTR strKey)
{
	assert(m_hKey);
	assert(strKey);

	if(0 == _tcscmp(strKey, _T("HKEY_CLASSES_ROOT")))
	{
		m_hKey = HKEY_CLASSES_ROOT;
		return true;
	}
	if(0 == _tcscmp(strKey, _T("HKEY_CURRENT_USER")))
	{
		m_hKey = HKEY_CURRENT_USER;
		return true;
	}
	if(0 == _tcscmp(strKey, _T("HKEY_LOCAL_MACHINE")))
	{
		m_hKey = HKEY_LOCAL_MACHINE;
		return true;
	}
	if(0 == _tcscmp(strKey, _T("HKEY_USERS")))
	{
		m_hKey = HKEY_USERS;
		return true;
	}
	if(0 == _tcscmp(strKey, _T("HKEY_PERFORMANCE_DATA")))
	{
		m_hKey = HKEY_PERFORMANCE_DATA;
		return true;
	}
	if(0 == _tcscmp(strKey, _T("HKEY_PERFORMANCE_TEXT")))
	{
		m_hKey = HKEY_PERFORMANCE_TEXT;
		return true;
	}
	if(0 == _tcscmp(strKey, _T("HKEY_PERFORMANCE_NLSTEXT")))
	{
		m_hKey = HKEY_PERFORMANCE_NLSTEXT;
		return true;
	}

	// �Բ���ϵͳ�汾���в���
#if(WINVER >= 0x0400)
	if(0 == _tcscmp(strKey, _T("HKEY_CURRENT_CONFIG")))
	{
		m_hKey = HKEY_CURRENT_CONFIG;
		return true;
	}
	if(0 == _tcscmp(strKey, _T("HKEY_DYN_DATA")))
	{
		m_hKey = HKEY_DYN_DATA;
		return true;
	}
#endif

	return false;
}

/***********************************************************************
 * �� �� ��: OpenKey
 * ��    ��: LPCTSTR [IN] : �Ӽ��ַ���
 * ��������: ͨ�������Ӽ����ַ�����ע�����Ӧ��λ��
 * �� �� ֵ: bool
 * �׳��쳣��
***********************************************************************/
bool CRegOperator::OpenKey(LPCTSTR lpSubKey)
{
	assert(m_hKey);
	assert(lpSubKey);

	HKEY hKey;
	long lReturn = RegOpenKeyEx(m_hKey, lpSubKey, 0, KEY_READ | KEY_WRITE | KEY_EXECUTE, &hKey);

	// �ɹ���
	if(ERROR_SUCCESS == lReturn)
	{
		m_hKey = hKey;
		return true;
	}

	return false;
}

/***********************************************************************
 * �� �� ��: CreateKey
 * ��    ��: LPCTSTR [IN] : �Ӽ��ַ���
 * ��������: ͨ�������Ӽ����ַ�����(�����Ӽ�)���ߴ���(�������Ӽ�)��Ӧ���Ӽ�
 * �� �� ֵ: bool
 * �׳��쳣��
***********************************************************************/
bool CRegOperator::CreateKey(LPCTSTR lpSubKey)
{
	assert(m_hKey);
	assert(lpSubKey);

	HKEY hKey;
	DWORD dw;
	long lReturn = RegCreateKeyEx(m_hKey, lpSubKey, 0, NULL, 
		REG_OPTION_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, &dw);

	// �ɹ��򿪻��ߴ������
	if(ERROR_SUCCESS == lReturn)
	{
		m_hKey = hKey;
		return true;
	}

	// �򿪻��ߴ���ʧ��
	return false;
}

/***********************************************************************
 * �� �� ��: DeleteKey
 * ��    ��: LPCTSTR LPCTSTR [IN] : ����ֵ �Ӽ�ֵ
 * ��������: ͨ������ĸ������Ӽ������Ӽ�ɾ�������ܰ����Ӽ�
 * �� �� ֵ: bool
 * �׳��쳣��
***********************************************************************/
bool CRegOperator::DeleteKey(LPCTSTR lphKey, LPCTSTR lpSubKey)
{
	assert(m_hKey);
	assert(lphKey);
	assert(lpSubKey);

	SetHKEY(lphKey);
	long lReturn = RegDeleteKey(m_hKey, lpSubKey);
	if(ERROR_SUCCESS == lReturn)
		return true;

	return false;
}

/***********************************************************************
 * �� �� ��: DeleteValue 
 * ��    ��: LPCTSTR [IN] : Ҫɾ����ֵ������
 * ��������: ͨ�������ֵ���ƣ�ɾ����Ӧ�ļ�ֵ
 * �� �� ֵ: bool
 * �׳��쳣��
***********************************************************************/
bool CRegOperator::DeleteValue(LPCTSTR lpValueName)
{
	assert(m_hKey);
	assert(lpValueName);

	long lReturn = RegDeleteValue(m_hKey, lpValueName);
	if(ERROR_SUCCESS == lReturn)
		return true;

	return false;
}

/***********************************************************************
 * �� �� ��: SaveKey  
 * ��    ��: LPCTSTR [IN] : ��������ļ���
 * ��������: ͨ��������ļ����ƣ������Ӧ���Ӽ�
 * �� �� ֵ: bool
 * �׳��쳣��
***********************************************************************/
bool CRegOperator::SaveKey(LPCTSTR lpFileName)
{
	assert(m_hKey);
	assert(lpFileName);

	long lReturn = RegSaveKey(m_hKey, lpFileName, NULL);
	if(ERROR_SUCCESS == lReturn)
		return true;

	return false;
}

/***********************************************************************
 * �� �� ��: RestoreKey   
 * ��    ��: LPCTSTR [IN] : ���ָ����ļ���
 * ��������: ͨ���ļ����ƣ������е���ע�����
 * �� �� ֵ: bool
 * �׳��쳣��
***********************************************************************/
bool CRegOperator::RestoreKey(LPCTSTR lpFileName)
{
	assert(m_hKey);
	assert(lpFileName);
	
	long lReturn = RegRestoreKey(m_hKey, lpFileName, 0);
	if(ERROR_SUCCESS == lReturn)
		return true;

	return false;
}

/***********************************************************************
 * �� �� ��: Read   
 * ��    ��: LPCTSTR CString [IN] : ��ֵ ��ȡֵ������
 * ��������: ��ָ��λ�õ�CString���͵�ֵ����
 * �� �� ֵ: bool
 * �׳��쳣��
***********************************************************************/
bool CRegOperator::Read(LPCTSTR lpValueName, CString* lpVal)
{
	assert(m_hKey);
	assert(lpValueName);
	assert(lpVal);

	DWORD dwType;
	DWORD dwSize = 200;
	char szString[2048] = {0};
	
	long lReturn = RegQueryValueEx(m_hKey, lpValueName, NULL, &dwType, (BYTE *)szString, &dwSize);

	if(ERROR_SUCCESS == lReturn)
	{
		*lpVal = s2ws(szString).c_str();
		return true;
	}

	return false;
}

/***********************************************************************
 * �� �� ��: Read   
 * ��    ��: LPCTSTR DWORD [IN] : ��ֵ ��ȡֵ������
 * ��������: ��ָ��λ�õ�DWORD���͵�ֵ����
 * �� �� ֵ: bool
 * �׳��쳣��
***********************************************************************/
bool CRegOperator::Read(LPCTSTR lpValueName, DWORD* pdwVal)
{
	assert(m_hKey);
	assert(lpValueName);
	assert(pdwVal);

	DWORD dwType;
	DWORD dwSize = sizeof(DWORD);
	DWORD dwDest;
	long lReturn = RegQueryValueEx(m_hKey, lpValueName, NULL, &dwType, (BYTE *)&dwDest, &dwSize);

	if(ERROR_SUCCESS == lReturn)
	{
		*pdwVal = dwDest;
		return true;
	}

	return false;
}

/***********************************************************************
 * �� �� ��: Read
 * ��    ��: LPCTSTR int [IN] : ��ֵ ��ȡֵ������
 * ��������: ��ָ��λ�õ�int���͵�ֵ����
 * �� �� ֵ: bool
 * �׳��쳣��
***********************************************************************/
bool CRegOperator::Read(LPCTSTR lpValueName, int* pnVal)
{
	assert(m_hKey);
	assert(lpValueName);
	assert(pnVal);

	DWORD dwType;
	DWORD dwSize = sizeof(DWORD);
	DWORD dwDest;
	long lReturn = RegQueryValueEx(m_hKey, lpValueName, NULL, &dwType, (BYTE *)&dwDest, &dwSize);

	if(ERROR_SUCCESS == lReturn)
	{
		*pnVal = dwDest;
		return true;
	}

	return false;
}

/***********************************************************************
 * �� �� ��: Write 
 * ��    ��: LPCTSTR LPCTSTR [IN] : ��ֵ д��ֵ������
 * ��������: ��LPCTSTR���͵�ֵд��ָ��λ��
 * �� �� ֵ: bool
 * �׳��쳣��
***********************************************************************/
bool CRegOperator::Write(LPCTSTR lpValueName, LPCTSTR lpVal)
{
	assert(m_hKey);
	assert(lpValueName);
	assert(lpVal);

	string strVal = ws2s(lpVal);
	long lReturn = RegSetValueEx(m_hKey, lpValueName, 0, REG_SZ, 
		(const BYTE *)strVal.c_str(), strVal.length() + 1);

	if(ERROR_SUCCESS == lReturn)
		return true;

	return false;
}

/***********************************************************************
 * �� �� ��: Write 
 * ��    ��: LPCTSTR DWORD [IN] : ��ֵ д��ֵ������
 * ��������: ��DWORD���͵�ֵд��ָ��λ��
 * �� �� ֵ: bool
 * �׳��쳣��
***********************************************************************/
bool CRegOperator::Write(LPCTSTR lpSubKey, DWORD dwVal)
{
	assert(m_hKey);
	assert(lpSubKey);

	long lReturn = RegSetValueEx(m_hKey, lpSubKey, 0, REG_DWORD, 
		(const BYTE *)&dwVal, sizeof(DWORD));

	if(ERROR_SUCCESS == lReturn)
		return true;

	return false;
}

/***********************************************************************
 * �� �� ��: Write 
 * ��    ��: LPCTSTR int [IN] : ��ֵ д��ֵ������
 * ��������: ��int���͵�ֵд��ָ��λ��
 * �� �� ֵ: bool
 * �׳��쳣��
***********************************************************************/
bool CRegOperator::Write(LPCTSTR lpSubKey, int nVal)
{
	assert(m_hKey);
	assert(lpSubKey);

	DWORD dwValue = (DWORD)nVal;
	long lRerutn = RegSetValueEx(m_hKey, lpSubKey, 0, REG_DWORD, 
		(const BYTE *)&dwValue, sizeof(DWORD));

	if(ERROR_SUCCESS == lRerutn)
		return true;
	
	return false;
}

