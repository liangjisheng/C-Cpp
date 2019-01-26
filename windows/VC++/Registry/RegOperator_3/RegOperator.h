
/***********************************************************************
 * 文件名:RegOperator.h
 * 文件描述:对注册表常见操作进行封装
 * 创建人:梁基圣 20171104
 * 版本号:1.0
 * 修改记录:
***********************************************************************/

#ifndef REGOP_H_
#define REGOP_H_

#include <afx.h>
#include <assert.h>
#include <string>
using std::string;
using std::wstring;

class CRegOperator
{
private:
	HKEY m_hKey;		// 当前操作根键的句柄
public:
	static const std::wstring s2ws(const std::string &s);
	static const std::string ws2s(const std::wstring& ws);

	CRegOperator(HKEY hkey = HKEY_LOCAL_MACHINE);
	// 设置当前操作的根键
	bool SetHKEY(LPCTSTR strKey);
	// 读写的形式打开注册表
	bool OpenKey(LPCTSTR lpSubKey);
	// 关闭键句柄
	void Close();
	// 创建的形式打开注册表
	bool CreateKey(LPCTSTR lpSubKey);
	// 删除相应的子键(子键为空)
	bool DeleteKey(LPCTSTR lphKey, LPCTSTR lpSubKey);
	// 删除子键处相应的键值
	bool DeleteValue(LPCTSTR lpValueName);
	// 把当前键值保存到指定文件
	bool SaveKey(LPCTSTR lpFileName);
	// 从指定注册表文件中恢复
	bool RestoreKey(LPCTSTR lpFileName);
	// 读出REG_SZ类型的值
	bool Read(LPCTSTR lpValueName, CString* lpVal);
	// 读出REG_DWORD类型的值
	bool Read(LPCTSTR lpValueName, DWORD* pdwVal);
	// 读出INT类型的值
	bool Read(LPCTSTR lpValueName, int* pnVal);
	// bool写入REG_SZ类型的值
	bool Write(LPCTSTR lpSubKey, LPCTSTR lpVal);
	// 写入DWORD类型的值
	bool Write(LPCTSTR lpSubKey, DWORD dwVal);
	// 写入INT类型的值
	bool Write(LPCTSTR lpSubKey, int nVal);

	virtual ~CRegOperator();
};

#endif // REGOP_H_