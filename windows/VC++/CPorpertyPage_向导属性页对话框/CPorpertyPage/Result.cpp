// Result.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CPorpertyPage.h"
#include "Result.h"
#include "afxdialogex.h"


// CResult �Ի���

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


// CResult ��Ϣ�������


BOOL CResult::OnSetActive()
{
	// ��ȡ������,�����Ա�CPropertyPage��
	CPropertySheet* pSheet = (CPropertySheet*)GetParent();
	// �������Ա�ֻ����ɰ�ť
	pSheet->SetFinishText(_T("���"));

	return CPropertyPage::OnSetActive();
}


BOOL CResult::OnWizardFinish()
{
	// �������һ������ҳ�ϵ���ɰ�ťʱ������ĳЩ����
	MessageBox(_T("ʹ��˵�������Ķ���."));

	return CPropertyPage::OnWizardFinish();
}
