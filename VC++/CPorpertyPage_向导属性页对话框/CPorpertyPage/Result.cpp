// Result.cpp : 实现文件
//

#include "stdafx.h"
#include "CPorpertyPage.h"
#include "Result.h"
#include "afxdialogex.h"


// CResult 对话框

IMPLEMENT_DYNAMIC(CResult, CPropertyPage)

CResult::CResult()
	: CPropertyPage(IDD_RESULT_DIALOG)
{

}

CResult::~CResult()
{
}

void CResult::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CResult, CPropertyPage)
END_MESSAGE_MAP()


// CResult 消息处理程序


BOOL CResult::OnSetActive()
{
	// 获取父窗口,即属性表CPropertyPage类
	CPropertySheet* pSheet = (CPropertySheet*)GetParent();
	// 设置属性表只有完成按钮
	pSheet->SetFinishText(_T("完成"));

	return CPropertyPage::OnSetActive();
}


BOOL CResult::OnWizardFinish()
{
	// 单击最后一个属性页上的完成按钮时，进行某些处理
	MessageBox(_T("使用说明向导以阅读完."));

	return CPropertyPage::OnWizardFinish();
}
