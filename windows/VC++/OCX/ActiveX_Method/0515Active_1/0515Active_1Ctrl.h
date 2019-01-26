#pragma once

#include "Dlg.h"
// 0515Active_1Ctrl.h : Declaration of the CMy0515Active_1Ctrl ActiveX Control class.
// CMy0515Active_1Ctrl : See 0515Active_1Ctrl.cpp for implementation.

class CMy0515Active_1Ctrl : public COleControl
{
	DECLARE_DYNCREATE(CMy0515Active_1Ctrl)

// Constructor
public:
	CMy0515Active_1Ctrl();

// Overrides
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// Implementation
protected:
	~CMy0515Active_1Ctrl();

	DECLARE_OLECREATE_EX(CMy0515Active_1Ctrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CMy0515Active_1Ctrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CMy0515Active_1Ctrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CMy0515Active_1Ctrl)		// Type name and misc status

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
		dispiddNum2 = 3,
		dispiddNum1 = 2,
		dispidAdd = 1L
	};
	CDlg m_dlg;
	
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
public:
	DOUBLE Add(DOUBLE dNum1, DOUBLE dNum2);
	void OndNum1Changed(void);
	DOUBLE m_dNum1;
	void OndNum2Changed(void);
	DOUBLE m_dNum2;
};

