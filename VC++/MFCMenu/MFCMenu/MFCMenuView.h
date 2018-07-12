
// MFCMenuView.h : CMFCMenuView 类的接口
//

#pragma once


class CMFCMenuView : public CView
{
protected: // 仅从序列化创建
	CMFCMenuView();
	DECLARE_DYNCREATE(CMFCMenuView)

// 特性
public:
	CMFCMenuDoc* GetDocument() const;

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
	virtual ~CMFCMenuView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnShow();
};

#ifndef _DEBUG  // MFCMenuView.cpp 中的调试版本
inline CMFCMenuDoc* CMFCMenuView::GetDocument() const
   { return reinterpret_cast<CMFCMenuDoc*>(m_pDocument); }
#endif

