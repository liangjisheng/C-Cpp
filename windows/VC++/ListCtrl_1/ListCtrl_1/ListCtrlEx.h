#pragma once

// CListCtrlEx

class CListCtrlEx : public CListCtrl
{
	DECLARE_DYNAMIC(CListCtrlEx)
// 数据
public:
	int			m_hoverIndex;			// 当前热点项目索引(热点就是鼠标停在某一行上)
	bool		m_mouseTrack;			// 是否追踪鼠标移动事件
	bool		m_if_hotLine;			// 是否改变热点行的颜色
	COLORREF	m_oddItemBkColor;		// 奇数行背景颜色
	COLORREF	m_oddItemTextColor;		// 奇数行文字颜色
	COLORREF	m_evenItemBkColor;		// 偶数行背景颜色
	COLORREF	m_evenItemTextColor;	// 偶数行文字颜色
	COLORREF	m_hoverItemBkColor;		// 热点行背景颜色
	COLORREF	m_hoverItemTextColor;	// 热点行文字颜色
	COLORREF	m_selectItemBkColor;	// 选中行背景颜色
	COLORREF	m_selectItemTextColor;	// 选中行文字颜色

public:
	void SetOddItemBkColor(COLORREF color);
	void SetOddItemTextColor(COLORREF color);
	void SetEvenItemBkColor(COLORREF color);
	void SetEvenItemTextColor(COLORREF color);
	void SetHoverItemBkColor(COLORREF color);
	void SetHoverItemTextColor(COLORREF color);
	void SetSelectItemBkColor(COLORREF color);
	void SetSelectItemTextColor(COLORREF color);

public:
	CListCtrlEx();
	virtual ~CListCtrlEx();

protected:
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnMouseLeave();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPaint();
	afx_msg void OnNMCustomdraw(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnColumnclick(NMHDR *pNMHDR, LRESULT *pResult);
};


