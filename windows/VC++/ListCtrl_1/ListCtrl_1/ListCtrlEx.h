#pragma once

// CListCtrlEx

class CListCtrlEx : public CListCtrl
{
	DECLARE_DYNAMIC(CListCtrlEx)
// ����
public:
	int			m_hoverIndex;			// ��ǰ�ȵ���Ŀ����(�ȵ�������ͣ��ĳһ����)
	bool		m_mouseTrack;			// �Ƿ�׷������ƶ��¼�
	bool		m_if_hotLine;			// �Ƿ�ı��ȵ��е���ɫ
	COLORREF	m_oddItemBkColor;		// �����б�����ɫ
	COLORREF	m_oddItemTextColor;		// ������������ɫ
	COLORREF	m_evenItemBkColor;		// ż���б�����ɫ
	COLORREF	m_evenItemTextColor;	// ż����������ɫ
	COLORREF	m_hoverItemBkColor;		// �ȵ��б�����ɫ
	COLORREF	m_hoverItemTextColor;	// �ȵ���������ɫ
	COLORREF	m_selectItemBkColor;	// ѡ���б�����ɫ
	COLORREF	m_selectItemTextColor;	// ѡ����������ɫ

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


