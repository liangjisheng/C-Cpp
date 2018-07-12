
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
	CRect m_Rect;		// ��̬�ı����λ��
	CFont *m_cfNtr;		// ��������
	CFont m_cfUL;		// �»�������
	LOGFONT m_lfNtr, m_lfUL;	// �߼�����
	COLORREF m_color;	// ������ɫ
	CBrush m_brush;		// �ؼ�����ɫ
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
