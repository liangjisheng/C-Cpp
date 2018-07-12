// SignalLampDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SignalLamp.h"
#include "SignalLampDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define  SIGNALLAMPTIMER 1

// CSignalLampDlg �Ի���
CSignalLampDlg::CSignalLampDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSignalLampDlg::IDD, pParent)
{
	m_nState	= 0;
	m_hIcon		= AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSignalLampDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CUSTOM_DEMO, m_slDemo);
	DDX_Radio(pDX, IDC_RADIO_NORMAL, m_nState);
}

BEGIN_MESSAGE_MAP(CSignalLampDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_RADIO_NORMAL, &CSignalLampDlg::OnBnClickedRadioNormal)
	ON_BN_CLICKED(IDC_RADIO_WARNING, &CSignalLampDlg::OnBnClickedRadioNormal)
	ON_BN_CLICKED(IDC_RADIO_DISABLE, &CSignalLampDlg::OnBnClickedRadioNormal)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CSignalLampDlg ��Ϣ�������

BOOL CSignalLampDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	SetTimer(SIGNALLAMPTIMER, 300, NULL);		// Ĭ��OnTimer()

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CSignalLampDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ��������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù����ʾ��
//
HCURSOR CSignalLampDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CSignalLampDlg::OnBnClickedRadioNormal()
{
	UpdateData();

	m_slDemo.SetState((CSignalLampCtrl::StateType)m_nState);
}

void CSignalLampDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	if(m_nState < 3)
	{
		m_slDemo.SetState((CSignalLampCtrl::StateType)m_nState);
		m_nState++;
		if(3 == m_nState)
			m_nState = 0;
	}

	CDialog::OnTimer(nIDEvent);
}
