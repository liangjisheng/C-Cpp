// ConvertImageDlg.h : header file
//

#if !defined(AFX_CONVERTIMAGEDLG_H__0B375D14_CF49_498E_BE4C_5DB70BABE4BA__INCLUDED_)
#define AFX_CONVERTIMAGEDLG_H__0B375D14_CF49_498E_BE4C_5DB70BABE4BA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "GdiPlus\\GdiPlus.h"
using namespace Gdiplus;
#pragma comment(lib,"GdiPlus.lib")

/////////////////////////////////////////////////////////////////////////////
// CConvertImageDlg dialog

class CConvertImageDlg : public CDialog
{
// Construction
public:
	CConvertImageDlg(CWnd* pParent = NULL);	// standard constructor
	
	GdiplusStartupInput m_Gdiplus;	// 定义初始变量
	ULONG_PTR m_pGdiToken;			// 定义GDI符号
	CString m_FileName;				// 记录文件名称

	int GetCodesClsid(const WCHAR* format,CLSID* pClsid);
	BOOL TestButtonState(UINT BTNID);	// 根据按钮的命令ID判断按钮是否被选中
// Dialog Data
	//{{AFX_DATA(CConvertImageDlg)
	enum { IDD = IDD_CONVERTIMAGE_DIALOG };
	CEdit	m_ImageName;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CConvertImageDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CConvertImageDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnCancel();
	afx_msg void OnOk();
	afx_msg void OnConvert();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONVERTIMAGEDLG_H__0B375D14_CF49_498E_BE4C_5DB70BABE4BA__INCLUDED_)
