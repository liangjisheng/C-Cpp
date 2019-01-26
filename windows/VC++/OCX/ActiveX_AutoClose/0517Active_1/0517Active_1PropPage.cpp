// 0517Active_1PropPage.cpp : Implementation of the CMy0517Active_1PropPage property page class.

#include "stdafx.h"
#include "0517Active_1.h"
#include "0517Active_1PropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CMy0517Active_1PropPage, COlePropertyPage)



// Message map

BEGIN_MESSAGE_MAP(CMy0517Active_1PropPage, COlePropertyPage)
END_MESSAGE_MAP()



// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CMy0517Active_1PropPage, "MY0517ACTIVE_1.My0517Active_1PropPage.1",
	0x581e5704, 0x3153, 0x4a66, 0x87, 0x33, 0x57, 0x12, 0x79, 0xe4, 0x30, 0x3d)



// CMy0517Active_1PropPage::CMy0517Active_1PropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CMy0517Active_1PropPage

BOOL CMy0517Active_1PropPage::CMy0517Active_1PropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_MY0517ACTIVE_1_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}



// CMy0517Active_1PropPage::CMy0517Active_1PropPage - Constructor

CMy0517Active_1PropPage::CMy0517Active_1PropPage() :
	COlePropertyPage(IDD, IDS_MY0517ACTIVE_1_PPG_CAPTION)
{
}



// CMy0517Active_1PropPage::DoDataExchange - Moves data between page and properties

void CMy0517Active_1PropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}



// CMy0517Active_1PropPage message handlers
