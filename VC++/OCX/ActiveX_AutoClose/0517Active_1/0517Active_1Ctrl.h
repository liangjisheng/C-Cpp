#pragma once

#include "Dlg1.h"
// 0517Active_1Ctrl.h : Declaration of the CMy0517Active_1Ctrl ActiveX Control class.
// CMy0517Active_1Ctrl : See 0517Active_1Ctrl.cpp for implementation.

class CMy0517Active_1Ctrl : public COleControl
{
	DECLARE_DYNCREATE(CMy0517Active_1Ctrl)

// Constructor
public:
	CMy0517Active_1Ctrl();
	CDlg1 m_dlg;
// Overrides
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// Implementation
protected:
	~CMy0517Active_1Ctrl();

	DECLARE_OLECREATE_EX(CMy0517Active_1Ctrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CMy0517Active_1Ctrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CMy0517Active_1Ctrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CMy0517Active_1Ctrl)		// Type name and misc status

// Message maps
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	};
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

