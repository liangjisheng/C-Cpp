// CDlgNoMo.cpp : implementation file
//

#include "stdafx.h"
#include "1033.h"
#include "CDlgNoMo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCDlgNoMo dialog


CCDlgNoMo::CCDlgNoMo(CWnd* pParent /*=NULL*/)
	: CDialog(CCDlgNoMo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCDlgNoMo)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CCDlgNoMo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCDlgNoMo)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCDlgNoMo, CDialog)
	//{{AFX_MSG_MAP(CCDlgNoMo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCDlgNoMo message handlers
