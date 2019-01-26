// SignalLampDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "SignalLamp.h"
#include "SignalLampDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define  SIGNALLAMPTIMER 1

// CSignalLampDlg 对话框
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


// CSignalLampDlg 消息处理程序

BOOL CSignalLampDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	SetTimer(SIGNALLAMPTIMER, 300, NULL);		// 默认OnTimer()

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CSignalLampDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标显示。
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
