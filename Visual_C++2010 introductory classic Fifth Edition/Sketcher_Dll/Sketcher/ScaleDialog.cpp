// ScaleDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "Sketcher.h"
#include "ScaleDialog.h"
#include "afxdialogex.h"


// CScaleDialog 对话框

IMPLEMENT_DYNAMIC(CScaleDialog, CDialog)

CScaleDialog::CScaleDialog(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_SCALE_DLG, pParent)
	, m_Scale(0)
{

}

CScaleDialog::~CScaleDialog()
{
}

void CScaleDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_LBIndex(pDX, IDC_SCALE_LIST, m_Scale);
	DDV_MinMaxInt(pDX, m_Scale, 0, 7);
}


BEGIN_MESSAGE_MAP(CScaleDialog, CDialog)
END_MESSAGE_MAP()


// CScaleDialog 消息处理程序


BOOL CScaleDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// GetDlgItem(） 返回CWnd*类型的指针
	CListBox* pListBox = static_cast<CListBox*>(GetDlgItem(IDC_SCALE_LIST));
	CString scaleStr;
	for (int i = 1; i <= 8; i++)
	{
		scaleStr.Format(_T("Scale %d"), i);
		pListBox->AddString(scaleStr);
	}
	pListBox->SetCurSel(m_Scale);	// Set current scale

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
