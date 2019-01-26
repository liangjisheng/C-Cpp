// 0602Active1PropPage.cpp : Implementation of the CMy0602Active1PropPage property page class.

#include "stdafx.h"
#include "0602Active1.h"
#include "0602Active1PropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CMy0602Active1PropPage, COlePropertyPage)



// Message map

BEGIN_MESSAGE_MAP(CMy0602Active1PropPage, COlePropertyPage)
END_MESSAGE_MAP()



// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CMy0602Active1PropPage, "MY0602ACTIVE1.My0602Active1PropPage.1",
	0xff3524a3, 0xb4e8, 0x43b6, 0x96, 0xf6, 0x45, 0x35, 0x88, 0x71, 0x95, 0x3a)



// CMy0602Active1PropPage::CMy0602Active1PropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CMy0602Active1PropPage

BOOL CMy0602Active1PropPage::CMy0602Active1PropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_MY0602ACTIVE1_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}



// CMy0602Active1PropPage::CMy0602Active1PropPage - Constructor

CMy0602Active1PropPage::CMy0602Active1PropPage() :
	COlePropertyPage(IDD, IDS_MY0602ACTIVE1_PPG_CAPTION)
{
}



// CMy0602Active1PropPage::DoDataExchange - Moves data between page and properties

void CMy0602Active1PropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}



// CMy0602Active1PropPage message handlers
