#pragma once

// һ������ҳ�Ի���Ĵ�������ʵ
// CAddSheet,���Ա��࣬���������������ҳ��
// ����ҳ��Ĵ������򵼶Ի��������ҳ��Ҳ����һ����
// ֻ��һ������ҳ�Ի����в���Ҫ����һ�����͡���ɡ��Ȱ�ť��
// ����ȥ������ҳ���OnSetActive��OnWizardFinish�����غ���

#include "Num1.h"
#include "Num2.h"
#include "Result.h"

class CAddSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CAddSheet)

public:
	CAddSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CAddSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	virtual ~CAddSheet();
private:
	CNum1 m_Num1;
	CNum2 m_Num2;
	CResult m_Result;

protected:
	DECLARE_MESSAGE_MAP()
};