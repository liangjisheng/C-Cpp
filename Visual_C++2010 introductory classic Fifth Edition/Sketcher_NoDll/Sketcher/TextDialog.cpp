// TextDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Sketcher.h"
#include "TextDialog.h"
#include "afxdialogex.h"


// CTextDialog �Ի���

IMPLEMENT_DYNAMIC(CTextDialog, CDialog)

CTextDialog::CTextDialog(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_TEXT_DLG, pParent)
	, m_TextString(_T(""))
{

}

CTextDialog::~CTextDialog()
{
}

void CTextDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_TEXT, m_TextString);
	DDV_MaxChars(pDX, m_TextString, 100);
}


BEGIN_MESSAGE_MAP(CTextDialog, CDialog)
END_MESSAGE_MAP()


// CTextDialog ��Ϣ�������
