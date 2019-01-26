
/**********************************************************************
 * 文件名:RegOperator.cpp
 * 文件描述:对头文件中定义的类的成员函数进行了实现
 * 创建人:梁基圣 20171104
 * 版本号:1.0
 * 修改记录:
***********************************************************************/

#include "RegOperator.h"

/***********************************************************************
 * 函 数 名: s2ws
 * 参    数: const std::string& [IN]
 * 功能描述: 多字节转宽字符
 * 返 回 值: 目标宽字符
 * 抛出异常：
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
 * 函 数 名: ws2s
 * 参    数: const std::wstring& [IN]
 * 功能描述: 宽字符转多字节
 * 返 回 值: 目标多字节
 * 抛出异常：
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
 * 函 数 名: CRegOperator
 * 参    数: HKEY [IN] : 默认是HKEY_LOCAL_MACHINE
 * 功能描述: 构造函数，初始化根键
 * 返 回 值: 无
 * 抛出异常：
***********************************************************************/
CRegOperator::CRegOperator(HKEY hkey /* = HKEY_LOCAL_MACHINE */)
{
	m_hKey = hkey;
}

/***********************************************************************
 * 函 数 名: ~CRegOperator
 * 参    数: NULL [IN]
 * 功能描述: 析构函数，关闭打开的注册表句柄
 * 返 回 值: 无
 * 抛出异常：
***********************************************************************/
CRegOperator::~CRegOperator()
{
	Close();
}

/***********************************************************************
 * 函 数 名: Close
 * 参    数: NULL [IN]
 * 功能描述: 关闭打开键的句柄
 * 返 回 值: void
 * 抛出异常：
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
 * 函 数 名: SetHKEY
 * 参    数: LPCTSTR [IN] : 根键值
 * 功能描述: 由传入的根键字符串设置当前操作的根键的值
 * 返 回 值: void
 * 抛出异常：
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

	// 对操作系统版本进行测试
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
 * 函 数 名: OpenKey
 * 参    数: LPCTSTR [IN] : 子键字符串
 * 功能描述: 通过传入子键的字符串打开注册表相应的位置
 * 返 回 值: bool
 * 抛出异常：
***********************************************************************/
bool CRegOperator::OpenKey(LPCTSTR lpSubKey)
{
	assert(m_hKey);
	assert(lpSubKey);

	HKEY hKey;
	long lReturn = RegOpenKeyEx(m_hKey, lpSubKey, 0, KEY_READ | KEY_WRITE | KEY_EXECUTE, &hKey);

	// 成功打开
	if(ERROR_SUCCESS == lReturn)
	{
		m_hKey = hKey;
		return true;
	}

	return false;
}

/***********************************************************************
 * 函 数 名: CreateKey
 * 参    数: LPCTSTR [IN] : 子键字符串
 * 功能描述: 通过传入子键的字符串打开(存在子键)或者创建(不存在子键)相应的子键
 * 返 回 值: bool
 * 抛出异常：
***********************************************************************/
bool CRegOperator::CreateKey(LPCTSTR lpSubKey)
{
	assert(m_hKey);
	assert(lpSubKey);

	HKEY hKey;
	DWORD dw;
	long lReturn = RegCreateKeyEx(m_hKey, lpSubKey, 0, NULL, 
		REG_OPTION_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, &dw);

	// 成功打开或者创建句柄
	if(ERROR_SUCCESS == lReturn)
	{
		m_hKey = hKey;
		return true;
	}

	// 打开或者创建失败
	return false;
}

/***********************************************************************
 * 函 数 名: DeleteKey
 * 参    数: LPCTSTR LPCTSTR [IN] : 根键值 子键值
 * 功能描述: 通过传入的根键和子键，将子键删除，不能包含子键
 * 返 回 值: bool
 * 抛出异常：
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
 * 函 数 名: DeleteValue 
 * 参    数: LPCTSTR [IN] : 要删除键值的名称
 * 功能描述: 通过传入键值名称，删除对应的键值
 * 返 回 值: bool
 * 抛出异常：
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
 * 函 数 名: SaveKey  
 * 参    数: LPCTSTR [IN] : 待保存的文件名
 * 功能描述: 通过保存的文件名称，保存对应的子键
 * 返 回 值: bool
 * 抛出异常：
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
 * 函 数 名: RestoreKey   
 * 参    数: LPCTSTR [IN] : 待恢复的文件名
 * 功能描述: 通过文件名称，从其中导入注册表中
 * 返 回 值: bool
 * 抛出异常：
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
 * 函 数 名: Read   
 * 参    数: LPCTSTR CString [IN] : 键值 读取值的类型
 * 功能描述: 将指定位置的CString类型的值读出
 * 返 回 值: bool
 * 抛出异常：
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
 * 函 数 名: Read   
 * 参    数: LPCTSTR DWORD [IN] : 键值 读取值的类型
 * 功能描述: 将指定位置的DWORD类型的值读出
 * 返 回 值: bool
 * 抛出异常：
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
 * 函 数 名: Read
 * 参    数: LPCTSTR int [IN] : 键值 读取值的类型
 * 功能描述: 将指定位置的int类型的值读出
 * 返 回 值: bool
 * 抛出异常：
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
 * 函 数 名: Write 
 * 参    数: LPCTSTR LPCTSTR [IN] : 键值 写入值的类型
 * 功能描述: 将LPCTSTR类型的值写入指定位置
 * 返 回 值: bool
 * 抛出异常：
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
 * 函 数 名: Write 
 * 参    数: LPCTSTR DWORD [IN] : 键值 写入值的类型
 * 功能描述: 将DWORD类型的值写入指定位置
 * 返 回 值: bool
 * 抛出异常：
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
 * 函 数 名: Write 
 * 参    数: LPCTSTR int [IN] : 键值 写入值的类型
 * 功能描述: 将int类型的值写入指定位置
 * 返 回 值: bool
 * 抛出异常：
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

