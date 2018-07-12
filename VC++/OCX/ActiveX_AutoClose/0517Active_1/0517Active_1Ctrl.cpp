// 0517Active_1Ctrl.cpp : Implementation of the CMy0517Active_1Ctrl ActiveX Control class.

#include "stdafx.h"
#include "0517Active_1.h"
#include "0517Active_1Ctrl.h"
#include "0517Active_1PropPage.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CMy0517Active_1Ctrl, COleControl)



// Message map

BEGIN_MESSAGE_MAP(CMy0517Active_1Ctrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()



// Dispatch map

BEGIN_DISPATCH_MAP(CMy0517Active_1Ctrl, COleControl)
	DISP_FUNCTION_ID(CMy0517Active_1Ctrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()



// Event map

BEGIN_EVENT_MAP(CMy0517Active_1Ctrl, COleControl)
END_EVENT_MAP()



// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CMy0517Active_1Ctrl, 1)
	PROPPAGEID(CMy0517Active_1PropPage::guid)
END_PROPPAGEIDS(CMy0517Active_1Ctrl)



// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CMy0517Active_1Ctrl, "MY0517ACTIVE_1.My0517Active_1Ctrl.1",
	0xa945df92, 0xb075, 0x4b25, 0xb9, 0x36, 0xad, 0x37, 0xc2, 0x36, 0x33, 0x20)



// Type library ID and version

IMPLEMENT_OLETYPELIB(CMy0517Active_1Ctrl, _tlid, _wVerMajor, _wVerMinor)



// Interface IDs

const IID IID_DMy0517Active_1 = { 0xC1138B13, 0xA897, 0x4C80, { 0x9A, 0xBF, 0xCF, 0x8C, 0xC9, 0x3A, 0x84, 0xEC } };
const IID IID_DMy0517Active_1Events = { 0xAD4B7141, 0xA2DF, 0x4018, { 0x8A, 0xCB, 0x1C, 0xBA, 0x56, 0x5B, 0xCD, 0xA7 } };


// Control type information

static const DWORD _dwMy0517Active_1OleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CMy0517Active_1Ctrl, IDS_MY0517ACTIVE_1, _dwMy0517Active_1OleMisc)



// CMy0517Active_1Ctrl::CMy0517Active_1CtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CMy0517Active_1Ctrl

BOOL CMy0517Active_1Ctrl::CMy0517Active_1CtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_MY0517ACTIVE_1,
			IDB_MY0517ACTIVE_1,
			afxRegApartmentThreading,
			_dwMy0517Active_1OleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}



// CMy0517Active_1Ctrl::CMy0517Active_1Ctrl - Constructor

CMy0517Active_1Ctrl::CMy0517Active_1Ctrl()
{
	InitializeIIDs(&IID_DMy0517Active_1, &IID_DMy0517Active_1Events);
	// TODO: Initialize your control's instance data here.
}



// CMy0517Active_1Ctrl::~CMy0517Active_1Ctrl - Destructor

CMy0517Active_1Ctrl::~CMy0517Active_1Ctrl()
{
	// TODO: Cleanup your control's instance data here.
}



// CMy0517Active_1Ctrl::OnDraw - Drawing function

void CMy0517Active_1Ctrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	if (!pdc)
		return;

	// TODO: Replace the following code with your own drawing code.
	// pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	// pdc->Ellipse(rcBounds);
}



// CMy0517Active_1Ctrl::DoPropExchange - Persistence support

void CMy0517Active_1Ctrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.
}



// CMy0517Active_1Ctrl::OnResetState - Reset control to default state

void CMy0517Active_1Ctrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}



// CMy0517Active_1Ctrl::AboutBox - Display an "About" box to the user

void CMy0517Active_1Ctrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_MY0517ACTIVE_1);
	dlgAbout.DoModal();
}



// CMy0517Active_1Ctrl message handlers


int CMy0517Active_1Ctrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_dlg.Create(IDD_DIALOG1, this); 

	return 0;
}


void CMy0517Active_1Ctrl::OnSize(UINT nType, int cx, int cy)
{
	COleControl::OnSize(nType, cx, cy);

	CRect rc;
	GetClientRect(&rc);
	m_dlg.MoveWindow(&rc);
}
