// Num1.cpp : 实现文件
//

#include "stdafx.h"
#include "CPorpertyPage.h"
#include "Num1.h"
#include "afxdialogex.h"


// CNum1 对话框

IMPLEMENT_DYNAMIC(CNum1, CPropertyPage)

CNum1::CNum1()
	: CPropertyPage(IDD_NUM1_DIALOG)
{

}

CNum1::~CNum1()
{
}

void CNum1::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CNum1, CPropertyPage)
END_MESSAGE_MAP()


// CNum1 消息处理程序


//BOOL CNum1::OnSetActive()
//{
//	// 获取父窗口,即属性表CPropertyPage类
//	CPropertySheet* pSheet = (CPropertySheet*)GetParent();
//	// 设置属性表只有下一步按钮
//	pSheet->SetWizardButtons(PSWIZB_NEXT);
//
//	return CPropertyPage::OnSetActive();
//}
