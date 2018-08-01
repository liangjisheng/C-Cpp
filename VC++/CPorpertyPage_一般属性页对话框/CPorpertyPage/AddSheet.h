#pragma once

// 一般属性页对话框的创建与现实
// CAddSheet,属性表类，用来存放三个属性页类
// 属性页类的创建和向导对话框的属性页类也基本一样，
// 只是一般属性页对话框中不需要“下一步”和“完成”等按钮，
// 所以去掉属性页类的OnSetActive和OnWizardFinish等重载函数

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