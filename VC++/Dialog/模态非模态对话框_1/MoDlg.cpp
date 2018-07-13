// MoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "999.h"
#include "MoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMoDlg dialog


CMoDlg::CMoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMoDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMoDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMoDlg, CDialog)
	//{{AFX_MSG_MAP(CMoDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMoDlg message handlers
