// Num1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CPorpertyPage.h"
#include "Num1.h"
#include "afxdialogex.h"


// CNum1 �Ի���

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


// CNum1 ��Ϣ�������


//BOOL CNum1::OnSetActive()
//{
//	// ��ȡ������,�����Ա�CPropertyPage��
//	CPropertySheet* pSheet = (CPropertySheet*)GetParent();
//	// �������Ա�ֻ����һ����ť
//	pSheet->SetWizardButtons(PSWIZB_NEXT);
//
//	return CPropertyPage::OnSetActive();
//}
