// HelloDlg.cpp : implementation file
//

#include "stdafx.h"
#include "1096.h"
#include "HelloDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHelloDlg dialog


CHelloDlg::CHelloDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHelloDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHelloDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CHelloDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHelloDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHelloDlg, CDialog)
	//{{AFX_MSG_MAP(CHelloDlg)
	ON_BN_CLICKED(IDC_HELLO, OnHello)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHelloDlg message handlers

void CHelloDlg::OnHello() 
{
	// TODO: Add your control notification handler code here
	AfxMessageBox("调用DLL对话框");
}
