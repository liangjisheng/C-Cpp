#pragma once

// 0517Active_1PropPage.h : Declaration of the CMy0517Active_1PropPage property page class.


// CMy0517Active_1PropPage : See 0517Active_1PropPage.cpp for implementation.

class CMy0517Active_1PropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CMy0517Active_1PropPage)
	DECLARE_OLECREATE_EX(CMy0517Active_1PropPage)

// Constructor
public:
	CMy0517Active_1PropPage();

// Dialog Data
	enum { IDD = IDD_PROPPAGE_MY0517ACTIVE_1 };

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	DECLARE_MESSAGE_MAP()
};

