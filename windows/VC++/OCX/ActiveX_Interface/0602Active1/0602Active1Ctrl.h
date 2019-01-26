#pragma once

// 0602Active1Ctrl.h : Declaration of the CMy0602Active1Ctrl ActiveX Control class.


// CMy0602Active1Ctrl : See 0602Active1Ctrl.cpp for implementation.

class CMy0602Active1Ctrl : public COleControl
{
	DECLARE_DYNCREATE(CMy0602Active1Ctrl)

// Constructor
public:
	CMy0602Active1Ctrl();

// Overrides
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// Implementation
protected:
	~CMy0602Active1Ctrl();

	DECLARE_OLECREATE_EX(CMy0602Active1Ctrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CMy0602Active1Ctrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CMy0602Active1Ctrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CMy0602Active1Ctrl)		// Type name and misc status

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
		dispidGetLiveHeadPath = 1L
	};

	BSTR GetLiveHeadPath(void);
	virtual BOOL IsInvokeAllowed(DISPID /*dispid*/);
};

