// Set.cpp : implementation file
//

#include "stdafx.h"
#include "1043.h"
#include "Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSet dialog


CSet::CSet(CWnd* pParent /*=NULL*/)
	: CDialog(CSet::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSet)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CSet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSet)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSet, CDialog)
	//{{AFX_MSG_MAP(CSet)
	ON_BN_CLICKED(IDC_RESET, OnReset)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSet message handlers

void CSet::OnOK() 
{
	// TODO: Add extra validation here
	CString strport;
	GetDlgItem(IDC_SERVERADDR)->GetWindowText(m_serveraddr);
	GetDlgItem(IDC_PORT)->GetWindowText(strport);
	m_port=atoi(strport.GetBuffer(1));
	::SendMessage(this->m_hWnd,WM_CLOSE,0,0);	// 关闭设置窗口
	CDialog::OnOK();
}

void CSet::OnReset() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_SERVERADDR)->SetWindowText("");
	GetDlgItem(IDC_PORT)->SetWindowText("");
}

BOOL CSet::OnInitDialog() 
{
	CDialog::OnInitDialog();
	// TODO: Add extra initialization here
	m_serveraddr="1294851990@qq.com";	// 默认服务器地址
	GetDlgItem(IDC_SERVERADDR)->GetWindowText(m_serveraddr);
	GetDlgItem(IDC_PORT)->SetWindowText("25");	// 默认端口号
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
