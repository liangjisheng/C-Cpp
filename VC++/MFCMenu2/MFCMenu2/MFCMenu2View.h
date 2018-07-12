
// MFCMenu2View.h : CMFCMenu2View ��Ľӿ�
//

#pragma once
#include "MFCMenu2Doc.h"

class CMFCMenu2View : public CView
{
protected: // �������л�����
	CMFCMenu2View();
	DECLARE_DYNCREATE(CMFCMenu2View)

// ����
public:
	CMFCMenu2Doc* GetDocument() const;

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
	virtual ~CMFCMenu2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
private:
	int m_nIndex;		// ����ָʾ��ǰ�ǵڼ��ΰ��»س���
	CMenu m_menu;
	CString m_strLine;
public:
	CStringArray m_strArray;
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnPhone1();
	afx_msg void OnPhone2();
	afx_msg void OnPhone3();
	afx_msg void OnPhone4();
};

#ifndef _DEBUG  // MFCMenu2View.cpp �еĵ��԰汾
inline CMFCMenu2Doc* CMFCMenu2View::GetDocument() const
   { return reinterpret_cast<CMFCMenu2Doc*>(m_pDocument); }
#endif

