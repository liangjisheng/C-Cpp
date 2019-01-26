// CDlgMo.cpp : implementation file
//

#include "stdafx.h"
#include "1033.h"
#include "CDlgMo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCDlgMo dialog


CCDlgMo::CCDlgMo(CWnd* pParent /*=NULL*/)
	: CDialog(CCDlgMo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCDlgMo)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CCDlgMo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCDlgMo)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCDlgMo, CDialog)
	//{{AFX_MSG_MAP(CCDlgMo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCDlgMo message handlers

void CCDlgMo::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}
