
// ListCtrl_3Dlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CListCtrl_3Dlg dialog
class CListCtrl_3Dlg : public CDialogEx
{
// Construction
public:
	CListCtrl_3Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_LISTCTRL_3_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonSelect();		// ��ȡѡ�а�ť
	afx_msg void OnBnClickedButtonDelete();		// ɾ����ť
	CComboBox m_wndStyle;						// �б�ؼ������Ͽ����
	CListCtrl m_wndList;						// �б�ؼ�
	void InitListCtrl();						// ��ʼ���б�ؼ�
	afx_msg void OnCbnSelchangeCombo1();		// �����Ͽ�ı�
	// �б�ؼ���˫���¼�
	afx_msg void OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);
	void ShowFile(CString strPath);				// ��ʾ�ļ�
};
