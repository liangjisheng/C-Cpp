#pragma once

// 0602Active1PropPage.h : Declaration of the CMy0602Active1PropPage property page class.


// CMy0602Active1PropPage : See 0602Active1PropPage.cpp for implementation.

class CMy0602Active1PropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CMy0602Active1PropPage)
	DECLARE_OLECREATE_EX(CMy0602Active1PropPage)

// Constructor
public:
	CMy0602Active1PropPage();

// Dialog Data
	enum { IDD = IDD_PROPPAGE_MY0602ACTIVE1 };

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	DECLARE_MESSAGE_MAP()
};

