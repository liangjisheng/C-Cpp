
// MFCMenuView.h : CMFCMenuView ��Ľӿ�
//

#pragma once


class CMFCMenuView : public CView
{
protected: // �������л�����
	CMFCMenuView();
	DECLARE_DYNCREATE(CMFCMenuView)

// ����
public:
	CMFCMenuDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMFCMenuView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnShow();
};

#ifndef _DEBUG  // MFCMenuView.cpp �еĵ��԰汾
inline CMFCMenuDoc* CMFCMenuView::GetDocument() const
   { return reinterpret_cast<CMFCMenuDoc*>(m_pDocument); }
#endif

