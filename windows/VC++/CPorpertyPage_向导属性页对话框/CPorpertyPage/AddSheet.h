#pragma once

// CAddSheet,属性表类，用来存放三个属性页类
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