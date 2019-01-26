// ExtDlg.cpp : implementation file
//

#include "stdafx.h"
// #include "	\ add additional includes here"
#include "ExtDlg.h"
#include"Resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExtDlg dialog


CExtDlg::CExtDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CExtDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExtDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CExtDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CExtDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CExtDlg, CDialog)
	//{{AFX_MSG_MAP(CExtDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExtDlg message handlers
