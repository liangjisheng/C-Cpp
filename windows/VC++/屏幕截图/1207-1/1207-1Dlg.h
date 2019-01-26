
// 1207-1Dlg.h : header file
//

#pragma once


// CMy12071Dlg dialog
class CMy12071Dlg : public CDialogEx
{
// Construction
public:
	CMy12071Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MY12071_DIALOG };

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
	afx_msg void OnBnClickedButtonCapturescreen1();
	// 截取当前窗口的图片保存下来
	HBITMAP ScreenCapture(HWND hWnd, WORD wbitCount, LPCTSTR lpFileName = NULL);

	afx_msg void OnBnClickedButtonCapturescreen2();
	HBITMAP CopyScreenToBitmap(LPRECT lpRect);
	BOOL SaveBitmapToFile(HBITMAP hBitmap, LPCTSTR lpFileName);

	afx_msg void OnBnClickedCapturescreenGdi();
	// 截取屏幕，strFileName为保存图片的名字
	void GetYou(const CString &strFileName);
	int GetEncoderClsid(const WCHAR* format, CLSID* pClsid);

	afx_msg void OnBnClickedButtonGdidrawline();
	afx_msg void OnBnClickedButtonGdi1();
};
