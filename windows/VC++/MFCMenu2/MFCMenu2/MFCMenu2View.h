
// MFCMenu2View.h : CMFCMenu2View 类的接口
//

#pragma once
#include "MFCMenu2Doc.h"

class CMFCMenu2View : public CView
{
protected: // 仅从序列化创建
	CMFCMenu2View();
	DECLARE_DYNCREATE(CMFCMenu2View)

// 特性
public:
	CMFCMenu2Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMFCMenu2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
private:
	int m_nIndex;		// 用来指示当前是第几次按下回车键
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

#ifndef _DEBUG  // MFCMenu2View.cpp 中的调试版本
inline CMFCMenu2Doc* CMFCMenu2View::GetDocument() const
   { return reinterpret_cast<CMFCMenu2Doc*>(m_pDocument); }
#endif

