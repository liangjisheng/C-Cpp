// CourseDlg.cpp : implementation file
//

#include "stdafx.h"
#include "1057.h"
#include "CourseDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCourseDlg dialog


CCourseDlg::CCourseDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCourseDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCourseDlg)
	m_strNo = _T("");
	m_strName = _T("");
	m_strSpecial = _T("");
	m_strType = _T("");
	m_nOpen = 0;
	m_nHours = 0;
	m_dCredit = 0.0;
	//}}AFX_DATA_INIT
}


void CCourseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCourseDlg)
	DDX_Control(pDX, IDC_SPIN1, m_spinOpen);
	DDX_Control(pDX, IDC_COMBO_SPECIAL, m_comboSpecial);
	DDX_Text(pDX, IDC_COURSENO, m_strNo);
	DDX_Text(pDX, IDC_COURSENAME, m_strName);
	DDX_CBString(pDX, IDC_COMBO_SPECIAL, m_strSpecial);
	DDX_CBString(pDX, IDC_COMBO_TYPE, m_strType);
	DDX_Text(pDX, IDC_OPEN, m_nOpen);
	DDX_Text(pDX, IDC_COURSEHOURS, m_nHours);
	DDX_Text(pDX, IDC_CREDIT, m_dCredit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCourseDlg, CDialog)
	//{{AFX_MSG_MAP(CCourseDlg)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCourseDlg message handlers

BOOL CCourseDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	// TODO: Add extra initialization here
	m_spinOpen.SetRange(1,8);
	m_nHours=60;
	m_dCredit=2.0;
	m_nOpen=1;
	m_strType="专修";
	m_comboSpecial.AddString("数学系");
	m_comboSpecial.AddString("经济管理学院");
	m_comboSpecial.AddString("计算机科学与技术");
	m_strSpecial="数学系";
	UpdateData(false);	// 从变量到控件
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CCourseDlg::OnAdd() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	m_strNo.TrimLeft();
	if(m_strNo.IsEmpty()) {
		MessageBox("课程号不能为空");
		return ;
	}
	m_strName.TrimLeft();
	if(m_strName.IsEmpty()) {
		MessageBox("课程名不能为空");
		return ;
	}
	CDialog::OnOK();
}
