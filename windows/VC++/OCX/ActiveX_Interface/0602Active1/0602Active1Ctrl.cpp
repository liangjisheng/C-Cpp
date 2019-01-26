// 0602Active1Ctrl.cpp : Implementation of the CMy0602Active1Ctrl ActiveX Control class.

#include "stdafx.h"
#include "0602Active1.h"
#include "0602Active1Ctrl.h"
#include "0602Active1PropPage.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CMy0602Active1Ctrl, COleControl)



// Message map

BEGIN_MESSAGE_MAP(CMy0602Active1Ctrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()



// Dispatch map

BEGIN_DISPATCH_MAP(CMy0602Active1Ctrl, COleControl)
	DISP_FUNCTION_ID(CMy0602Active1Ctrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CMy0602Active1Ctrl, "GetLiveHeadPath", dispidGetLiveHeadPath, GetLiveHeadPath, VT_BSTR, VTS_NONE)
END_DISPATCH_MAP()



// Event map

BEGIN_EVENT_MAP(CMy0602Active1Ctrl, COleControl)
END_EVENT_MAP()



// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CMy0602Active1Ctrl, 1)
	PROPPAGEID(CMy0602Active1PropPage::guid)
END_PROPPAGEIDS(CMy0602Active1Ctrl)



// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CMy0602Active1Ctrl, "MY0602ACTIVE1.My0602Active1Ctrl.1",
	0x8ae0abe5, 0x47af, 0x401f, 0xa8, 0x41, 0xf2, 0x71, 0x6a, 0x65, 0xdb, 0xc2)



// Type library ID and version

IMPLEMENT_OLETYPELIB(CMy0602Active1Ctrl, _tlid, _wVerMajor, _wVerMinor)



// Interface IDs

const IID IID_DMy0602Active1 = { 0x9569208, 0x5136, 0x4866, { 0x97, 0xDE, 0x4D, 0xE9, 0x89, 0xFE, 0x15, 0x17 } };
const IID IID_DMy0602Active1Events = { 0xCAB606D9, 0xCE9E, 0x49CD, { 0xB4, 0xA5, 0x67, 0xB7, 0xB7, 0xD9, 0x9, 0xB0 } };


// Control type information

static const DWORD _dwMy0602Active1OleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CMy0602Active1Ctrl, IDS_MY0602ACTIVE1, _dwMy0602Active1OleMisc)



// CMy0602Active1Ctrl::CMy0602Active1CtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CMy0602Active1Ctrl

BOOL CMy0602Active1Ctrl::CMy0602Active1CtrlFactory::UpdateRegistry(BOOL bRegister)
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
			IDS_MY0602ACTIVE1,
			IDB_MY0602ACTIVE1,
			afxRegApartmentThreading,
			_dwMy0602Active1OleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}



// CMy0602Active1Ctrl::CMy0602Active1Ctrl - Constructor

CMy0602Active1Ctrl::CMy0602Active1Ctrl()
{
	InitializeIIDs(&IID_DMy0602Active1, &IID_DMy0602Active1Events);
	// TODO: Initialize your control's instance data here.
}



// CMy0602Active1Ctrl::~CMy0602Active1Ctrl - Destructor

CMy0602Active1Ctrl::~CMy0602Active1Ctrl()
{
	// TODO: Cleanup your control's instance data here.
}



// CMy0602Active1Ctrl::OnDraw - Drawing function

void CMy0602Active1Ctrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	if (!pdc)
		return;

	// TODO: Replace the following code with your own drawing code.
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}



// CMy0602Active1Ctrl::DoPropExchange - Persistence support

void CMy0602Active1Ctrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.
}



// CMy0602Active1Ctrl::OnResetState - Reset control to default state

void CMy0602Active1Ctrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}



// CMy0602Active1Ctrl::AboutBox - Display an "About" box to the user

void CMy0602Active1Ctrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_MY0602ACTIVE1);
	dlgAbout.DoModal();
}



// CMy0602Active1Ctrl message handlers


BSTR CMy0602Active1Ctrl::GetLiveHeadPath(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult = _T("");
	CTime tm = CTime::GetCurrentTime();
	strResult = tm.Format(_T("%Y%m%d%H%M%S"));

	return strResult.AllocSysString();
}


BOOL CMy0602Active1Ctrl::IsInvokeAllowed(DISPID /*dispid*/)
{
	

	return TRUE;
}
