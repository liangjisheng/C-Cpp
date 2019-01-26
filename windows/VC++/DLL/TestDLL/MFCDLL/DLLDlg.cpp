// DLLDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCDLL.h"
#include "DLLDlg.h"


// CDLLDlg dialog

IMPLEMENT_DYNAMIC(CDLLDlg, CDialog)

CDLLDlg::CDLLDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDLLDlg::IDD, pParent)
{

}

CDLLDlg::~CDLLDlg()
{
}

void CDLLDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDLLDlg, CDialog)
END_MESSAGE_MAP()


// CDLLDlg message handlers
