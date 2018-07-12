
// 0926-4Dlg.h : header file
//

#pragma once


// CMy09264Dlg dialog
class CMy09264Dlg : public CDialogEx
{
// Construction
public:
	CMy09264Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MY09264_DIALOG };

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
private:
	CRect m_Rect;		// 静态文本框的位置
	CFont *m_cfNtr;		// 正常字体
	CFont m_cfUL;		// 下划线字体
	LOGFONT m_lfNtr, m_lfUL;	// 逻辑字体
	COLORREF m_color;	// 字体颜色
	CBrush m_brush;		// 控件背景色
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
