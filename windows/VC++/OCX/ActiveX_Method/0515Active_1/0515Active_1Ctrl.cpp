// 0515Active_1Ctrl.cpp : Implementation of the CMy0515Active_1Ctrl ActiveX Control class.

#include "stdafx.h"
#include "0515Active_1.h"
#include "0515Active_1Ctrl.h"
#include "0515Active_1PropPage.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CMy0515Active_1Ctrl, COleControl)



// Message map

BEGIN_MESSAGE_MAP(CMy0515Active_1Ctrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
	ON_WM_CREATE()
END_MESSAGE_MAP()



// Dispatch map

BEGIN_DISPATCH_MAP(CMy0515Active_1Ctrl, COleControl)
	DISP_FUNCTION_ID(CMy0515Active_1Ctrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
	DISP_STOCKFUNC_DOCLICK()
	DISP_FUNCTION_ID(CMy0515Active_1Ctrl, "Add", dispidAdd, Add, VT_R8, VTS_R8 VTS_R8)
	DISP_PROPERTY_NOTIFY_ID(CMy0515Active_1Ctrl, "dNum1", dispiddNum1, m_dNum1, OndNum1Changed, VT_R8)
	DISP_PROPERTY_NOTIFY_ID(CMy0515Active_1Ctrl, "dNum2", dispiddNum2, m_dNum2, OndNum2Changed, VT_R8)
END_DISPATCH_MAP()



// Event map

BEGIN_EVENT_MAP(CMy0515Active_1Ctrl, COleControl)
	EVENT_STOCK_CLICK()
END_EVENT_MAP()



// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CMy0515Active_1Ctrl, 1)
	PROPPAGEID(CMy0515Active_1PropPage::guid)
END_PROPPAGEIDS(CMy0515Active_1Ctrl)



// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CMy0515Active_1Ctrl, "MY0515ACTIVE_1.My0515Active_1Ctrl.1",
	0x4e29832b, 0x7197, 0x4b2d, 0x91, 0xf5, 0x1d, 0xc4, 0x49, 0xed, 0x1e, 0x85)



// Type library ID and version

IMPLEMENT_OLETYPELIB(CMy0515Active_1Ctrl, _tlid, _wVerMajor, _wVerMinor)



// Interface IDs

const IID IID_DMy0515Active_1 = { 0xC4892E4A, 0x59BA, 0x48E1, { 0xBF, 0x43, 0x8E, 0xBA, 0xA4, 0x35, 0xA0, 0x69 } };
const IID IID_DMy0515Active_1Events = { 0x558ABAD, 0xEC6B, 0x42D0, { 0xBD, 0xF2, 0xD, 0xA8, 0xFA, 0x3, 0xF5, 0xD0 } };


// Control type information

static const DWORD _dwMy0515Active_1OleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CMy0515Active_1Ctrl, IDS_MY0515ACTIVE_1, _dwMy0515Active_1OleMisc)



// CMy0515Active_1Ctrl::CMy0515Active_1CtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CMy0515Active_1Ctrl

BOOL CMy0515Active_1Ctrl::CMy0515Active_1CtrlFactory::UpdateRegistry(BOOL bRegister)
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
			IDS_MY0515ACTIVE_1,
			IDB_MY0515ACTIVE_1,
			afxRegApartmentThreading,
			_dwMy0515Active_1OleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}



// CMy0515Active_1Ctrl::CMy0515Active_1Ctrl - Constructor

CMy0515Active_1Ctrl::CMy0515Active_1Ctrl()
{
	InitializeIIDs(&IID_DMy0515Active_1, &IID_DMy0515Active_1Events);
	// TODO: Initialize your control's instance data here.
}



// CMy0515Active_1Ctrl::~CMy0515Active_1Ctrl - Destructor

CMy0515Active_1Ctrl::~CMy0515Active_1Ctrl()
{
	// TODO: Cleanup your control's instance data here.
}



// CMy0515Active_1Ctrl::OnDraw - Drawing function

void CMy0515Active_1Ctrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	if (!pdc)
		return;

	// TODO: Replace the following code with your own drawing code.
	//pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	//pdc->Ellipse(rcBounds);
	m_dlg.MoveWindow(rcBounds, true);		// 移动窗口，重新绘制
}



// CMy0515Active_1Ctrl::DoPropExchange - Persistence support

void CMy0515Active_1Ctrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.
}



// CMy0515Active_1Ctrl::OnResetState - Reset control to default state

void CMy0515Active_1Ctrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}



// CMy0515Active_1Ctrl::AboutBox - Display an "About" box to the user

void CMy0515Active_1Ctrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_MY0515ACTIVE_1);
	dlgAbout.DoModal();
}



// CMy0515Active_1Ctrl message handlers


DOUBLE CMy0515Active_1Ctrl::Add(DOUBLE dNum1, DOUBLE dNum2)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	return dNum1 + dNum2;
}


int CMy0515Active_1Ctrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_dlg.Create(IDD_DIALOG1, this);

	return 0;
}


void CMy0515Active_1Ctrl::OndNum1Changed(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your property handler code here

	SetModifiedFlag();
}


void CMy0515Active_1Ctrl::OndNum2Changed(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your property handler code here

	SetModifiedFlag();
}
