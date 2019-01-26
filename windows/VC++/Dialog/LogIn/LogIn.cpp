// LogIn.cpp : implementation file
//

#include "stdafx.h"
#include "1001.h"
#include "LogIn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLogIn dialog


CLogIn::CLogIn(CWnd* pParent /*=NULL*/)
	: CDialog(CLogIn::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLogIn)
	m_password = _T("");
	m_username = _T("");
	//}}AFX_DATA_INIT
}


void CLogIn::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLogIn)
	DDX_Text(pDX, IDC_PASSWORD, m_password);
	DDX_Text(pDX, IDC_USERNAME, m_username);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLogIn, CDialog)
	//{{AFX_MSG_MAP(CLogIn)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLogIn message handlers

void CLogIn::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(true);
	if(m_username!="lishuyu" || m_password!="lishuyu") {
		MessageBox("用户名或密码错误");
		return ;
	}
	CDialog::OnOK();
}
