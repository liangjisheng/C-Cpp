// PenDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Sketcher.h"
#include "PenDialog.h"
#include "afxdialogex.h"


// CPenDialog �Ի���

IMPLEMENT_DYNAMIC(CPenDialog, CDialogEx)

CPenDialog::CPenDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PENWIDTH_DLG, pParent)
{
	m_PenWidth = 0;
}

CPenDialog::~CPenDialog()
{
}

void CPenDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPenDialog, CDialogEx)
	ON_BN_CLICKED(IDC_PENWIDTH0, &CPenDialog::OnBnClickedPenwidth0)
	ON_BN_CLICKED(IDC_PENWIDTH3, &CPenDialog::OnBnClickedPenwidth3)
	ON_BN_CLICKED(IDC_PENWIDTH1, &CPenDialog::OnBnClickedPenwidth1)
	ON_BN_CLICKED(IDC_PENWIDTH2, &CPenDialog::OnBnClickedPenwidth2)
	ON_BN_CLICKED(IDC_PENWIDTH4, &CPenDialog::OnBnClickedPenwidth4)
	ON_BN_CLICKED(IDC_PENWIDTH5, &CPenDialog::OnBnClickedPenwidth5)
END_MESSAGE_MAP()


// CPenDialog ��Ϣ�������


BOOL CPenDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// Check the radio button corresponding to the pen width
	switch (m_PenWidth)
	{
	case 1:
		// �ڶ�������Ϊ1����ѡ�е�һ������ID��ʾ�İ�ť��0��ȡ��ѡ��
		// ��ѡ��ť�͸�ѡ�򶼿��Դ���
		CheckDlgButton(IDC_PENWIDTH1, 1);
		break;
	case 2:
		CheckDlgButton(IDC_PENWIDTH2, 1);
		break;
	case 3:
		CheckDlgButton(IDC_PENWIDTH3, 1);
		break;
	case 4:
		CheckDlgButton(IDC_PENWIDTH4, 1);
		break;
	case 5:
		CheckDlgButton(IDC_PENWIDTH5, 1);
		break;
	default:
		CheckDlgButton(IDC_PENWIDTH0, 1);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CPenDialog::OnBnClickedPenwidth0()
{
	m_PenWidth = 0;
}


void CPenDialog::OnBnClickedPenwidth3()
{
	m_PenWidth = 3;
}


void CPenDialog::OnBnClickedPenwidth1()
{
	m_PenWidth = 1;
}


void CPenDialog::OnBnClickedPenwidth2()
{
	m_PenWidth = 2;
}


void CPenDialog::OnBnClickedPenwidth4()
{
	m_PenWidth = 4;
}


void CPenDialog::OnBnClickedPenwidth5()
{
	m_PenWidth = 5;
}
