
// HWDetectDlg.h : header file
//

#pragma once


// CHWDetectDlg dialog
class CHWDetectDlg : public CDialogEx
{
// Construction
public:
	CHWDetectDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CHWDetectDlg();
// Dialog Data
	enum { IDD = IDD_HWDETECT_DIALOG };

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
	HDEVNOTIFY hDevNotify;

	afx_msg void OnDevModeChange(LPTSTR lpDeviceName);
	afx_msg BOOL OnDeviceChange(UINT nEventType, DWORD dwData);
	TCHAR FirstDriveFromMask(ULONG unitmask);
	void UpdateDevice(PDEV_BROADCAST_DEVICEINTERFACE pDevInf, WPARAM wParam);
	void UpDateDevice_1(PDEV_BROADCAST_DEVICEINTERFACE pDevInf, WPARAM wParam);
	afx_msg BOOL OnQueryEndSession();
};
