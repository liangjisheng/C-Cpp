// AddSheet.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CPorpertyPage.h"
#include "AddSheet.h"


// CAddSheet

IMPLEMENT_DYNAMIC(CAddSheet, CPropertySheet)

CAddSheet::CAddSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
	// �����������ҳ�����Ա�
	AddPage(&m_Num1);
	AddPage(&m_Num2);
	AddPage(&m_Result);
}

CAddSheet::CAddSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	// �����������ҳ�����Ա�
	AddPage(&m_Num1);
	AddPage(&m_Num2);
	AddPage(&m_Result);
}

CAddSheet::~CAddSheet()
{
}


BEGIN_MESSAGE_MAP(CAddSheet, CPropertySheet)
END_MESSAGE_MAP()


// CAddSheet ��Ϣ�������
