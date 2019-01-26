// 0515Active_1PropPage.cpp : Implementation of the CMy0515Active_1PropPage property page class.

#include "stdafx.h"
#include "0515Active_1.h"
#include "0515Active_1PropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CMy0515Active_1PropPage, COlePropertyPage)



// Message map

BEGIN_MESSAGE_MAP(CMy0515Active_1PropPage, COlePropertyPage)
END_MESSAGE_MAP()



// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CMy0515Active_1PropPage, "MY0515ACTIVE_1.My0515Active_1PropPage.1",
	0x2803dc4, 0x1e06, 0x4835, 0x8e, 0x61, 0xe8, 0xd5, 0x10, 0x33, 0xf6, 0xb7)



// CMy0515Active_1PropPage::CMy0515Active_1PropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CMy0515Active_1PropPage

BOOL CMy0515Active_1PropPage::CMy0515Active_1PropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_MY0515ACTIVE_1_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}



// CMy0515Active_1PropPage::CMy0515Active_1PropPage - Constructor

CMy0515Active_1PropPage::CMy0515Active_1PropPage() :
	COlePropertyPage(IDD, IDS_MY0515ACTIVE_1_PPG_CAPTION)
{
}



// CMy0515Active_1PropPage::DoDataExchange - Moves data between page and properties

void CMy0515Active_1PropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}



// CMy0515Active_1PropPage message handlers
