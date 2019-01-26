
/***********************************************************************
 * �ļ���:RegOperator.h
 * �ļ�����:��ע������������з�װ
 * ������:����ʥ 20171104
 * �汾��:1.0
 * �޸ļ�¼:
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
	HKEY m_hKey;		// ��ǰ���������ľ��
public:
	static const std::wstring s2ws(const std::string &s);
	static const std::string ws2s(const std::wstring& ws);

	CRegOperator(HKEY hkey = HKEY_LOCAL_MACHINE);
	// ���õ�ǰ�����ĸ���
	bool SetHKEY(LPCTSTR strKey);
	// ��д����ʽ��ע���
	bool OpenKey(LPCTSTR lpSubKey);
	// �رռ����
	void Close();
	// ��������ʽ��ע���
	bool CreateKey(LPCTSTR lpSubKey);
	// ɾ����Ӧ���Ӽ�(�Ӽ�Ϊ��)
	bool DeleteKey(LPCTSTR lphKey, LPCTSTR lpSubKey);
	// ɾ���Ӽ�����Ӧ�ļ�ֵ
	bool DeleteValue(LPCTSTR lpValueName);
	// �ѵ�ǰ��ֵ���浽ָ���ļ�
	bool SaveKey(LPCTSTR lpFileName);
	// ��ָ��ע����ļ��лָ�
	bool RestoreKey(LPCTSTR lpFileName);
	// ����REG_SZ���͵�ֵ
	bool Read(LPCTSTR lpValueName, CString* lpVal);
	// ����REG_DWORD���͵�ֵ
	bool Read(LPCTSTR lpValueName, DWORD* pdwVal);
	// ����INT���͵�ֵ
	bool Read(LPCTSTR lpValueName, int* pnVal);
	// boolд��REG_SZ���͵�ֵ
	bool Write(LPCTSTR lpSubKey, LPCTSTR lpVal);
	// д��DWORD���͵�ֵ
	bool Write(LPCTSTR lpSubKey, DWORD dwVal);
	// д��INT���͵�ֵ
	bool Write(LPCTSTR lpSubKey, int nVal);

	virtual ~CRegOperator();
};

#endif // REGOP_H_