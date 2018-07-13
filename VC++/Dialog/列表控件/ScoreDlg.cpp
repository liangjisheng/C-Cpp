// ScoreDlg.cpp : implementation file
//

#include "stdafx.h"
#include "1060.h"
#include "ScoreDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScoreDlg dialog


CScoreDlg::CScoreDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CScoreDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CScoreDlg)
	m_strCourseNo = _T("");
	m_dScore = 0.0;
	m_dCredit = 0.0;
	m_strStuNo = _T("");
	m_strAddText.Empty();
	//}}AFX_DATA_INIT
}


void CScoreDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CScoreDlg)
	DDX_Text(pDX, IDC_EDIT_COURSENO, m_strCourseNo);
	DDX_Text(pDX, IDC_EDIT_CREDIT, m_dScore);
	DDX_Text(pDX, IDC_EDIT_SCORE, m_dCredit);
	DDX_Text(pDX, IDC_EDIT_SNO, m_strStuNo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CScoreDlg, CDialog)
	//{{AFX_MSG_MAP(CScoreDlg)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScoreDlg message handlers

void CScoreDlg::OnAdd() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_strStuNo.TrimLeft();	// 清楚左边的空格
	if(m_strStuNo.IsEmpty()) {
		MessageBox("学号不能为空"); return ;
	}
	m_strCourseNo.TrimLeft();
	if(m_strCourseNo.IsEmpty()) {
		MessageBox("课程号不能为空"); return ;
	}
	CDialog::OnOK();
}

BOOL CScoreDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	if(!m_strAddText.IsEmpty())
		GetDlgItem(IDC_ADD)->SetWindowText(m_strAddText);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
