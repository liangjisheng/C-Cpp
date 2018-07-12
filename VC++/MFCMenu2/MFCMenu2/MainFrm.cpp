
// MainFrm.cpp : CMainFrame ���ʵ��
// ������ʵ��������һ�����ܣ���Ӧ�ó���Ĵ����У�����һ�����֣��������ֵĸ�ʽ��
// ���� �绰���롣����������������ɰ��»س������ͻ��ڳ���Ĳ˵����ϵİ����˵���
// ��̬����һ���Ӳ˵������Ҹղ��������������Ϊ���е�һ���˵�������ʾ��Ȼ����Լ���
// �������̣������ڳ��򴰿���������һ�����֣�����ʱ���»س����󣬲�����Ҫ������һ��
// �Ӳ˵�������ֱ��������ӵ��Ӳ˵�����Ӳ˵������²˵�����ı����������������
// �����������̬���ɵ��Ӳ˵��е�ĳ���˵���ʱ������ͻ����Ӧ�������͵绰������ʾ��
// ���򴰿��ϡ�

#include "stdafx.h"
#include "MFCMenu2.h"

#include "MainFrm.h"
#include "MFCMenu2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

const int  iMaxUserToolbars = 10;
const UINT uiFirstUserToolBarId = AFX_IDW_CONTROLBAR_FIRST + 40;
const UINT uiLastUserToolBarId = uiFirstUserToolBarId + iMaxUserToolbars - 1;

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	//ON_COMMAND(IDM_HELLO, OnHello)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // ״̬��ָʾ��
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO: �ڴ���ӳ�Ա��ʼ������
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("δ�ܴ���������\n");
		return -1;      // δ�ܴ���
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("δ�ܴ���״̬��\n");
		return -1;      // δ�ܴ���
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: �������Ҫ��ͣ������������ɾ��������
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	//CMenu menu;
	//menu.CreateMenu();
	// BOOL AppendMenu(UINT nFlags, UINT_PTR nIDNewItem = 0, LPCTSTR lpszNewItem = NULL);
	// nFlagsָ������Ӳ˵���Ŀ��״̬��Ϣ
	// MF_CHECKED,MF_UNCHECKED,MF_ENABLED,MF_DISABLED,MF_GRAYED,MF_OWNERDRAW,MF_POPUP
	// MF_SEPARATOR,MF_STRING,MF_MENUBREAK,MF_MENUBARBREAK
	// �ڶ�������ȡ���ڵ�һ��������ֻ�������һ��������ֵ��MF_POPUP,��ônIDNewItem����
	// һ������˵��ľ�����������Ҫ��ӵ��²˵��������ID�������һ��������ֵ��MF_SEPARATOR
	// ��ônIDNewItem��ֵ������
	// ����������ȡֵͬ��ȡ���ڵ�һ�������������һ��������MF_STRING,��lpszNewItem
	// ����ָ��Ҫ��ӵ�����²˵���Ŀ���ı���ָ�롣�����һ��������MF_OWNERDRAW����
	// lpszNewItem����ָ��ò˵���Ŀ��һ���������ݵ�ָ�룬�����һ��������MF_SEPARATOR
	// lpszNewItem��������
	//GetMenu()->AppendMenu(MF_POPUP, (UINT)menu.m_hMenu, _T("test"));
	// ���˵������˵�����֮��Ĺ����Ͽ������߿�����menuΪCMainFrame���
	// ��Ա����
	//menu.Detach();


	//CMenu menu;
	//menu.CreateMenu();
	// ��һ���˵�ָ������һ���˵������ʶ����ʾ�²˵���������ʶ����ʾ�Ĳ˵���֮ǰ
	// ����
	//GetMenu()->InsertMenu(2, MF_POPUP | MF_BYPOSITION, (UINT)menu.m_hMenu, _T("test"));
	// ���Ӳ˵���Ӳ˵���
	//menu.AppendMenu(MF_STRING, IDM_HELLO, _T("hello"));
	//menu.AppendMenu(MF_STRING, 11112, _T("bye"));
	//menu.AppendMenu(MF_STRING, 11113, _T("mybole"));
	// ���ļ��Ӳ˵��������һ���˵���
	//GetMenu()->GetSubMenu(0)->AppendMenu(MF_STRING, 11114, _T("welcome"));
	//menu.Detach();

	// BOOL DeleteMenu(UINT nPosition, UINT nFlags);
	// ɾ��һ���˵���Ŀ�������Ӳ˵��Լ��Ӳ˵��µĲ˵����Ҫȡ���ڵ�����������Ķ���
	// ɾ���༭�Ӳ˵�
	//GetMenu()->DeleteMenu(1, MF_BYPOSITION);
	// ɾ���ļ�����Ĳ˵���
	//GetMenu()->GetSubMenu(0)->DeleteMenu(2, MF_BYPOSITION);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return TRUE;
}

// CMainFrame ���

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame ��Ϣ�������
//void CMainFrame::OnHello()
//{
	//MessageBox(_T("hello"));
//}


// �ÿ�ܴ�����ػ�˵�������Ϣ��
// ����ܴ�������ܵ�һ����Ϣʱ�������Ȼ����Ϣ�������Ӵ���ȥ����
// �˵������ǽ���OnCommand����������ģ���������������������Ϣ��·�ɡ�������д
// OnCommand���ػ���Щ��̬�����Ĳ˵����������Ϣ�������ǲ��ڼ�������·�ɡ�
// �������ڳ�������ʱ�����˵������ɳ�������CFrameWnd��OnWndMsg��������OnCommand
// ��������Ϊ�����ࣺCMainFrame����д�����OnCommand�������˵�������Ϣ�ͻ�
// �ȵ��������������б��������������ü���(���������ࣺCFrameWnd)��OnCommand()
// ����������Ϣ��·�ɡ�
// OnCommand�����Ƕ����е�������Ϣ����·�ɴ���ģ������˵�����������ť���Լ����ټ�
// ��������Ϣ������wParam�Ͷ˵������ֽ��з��õ��Ƿ��͵�ǰ��Ϣ�Ĳ˵�����������
// ���ټ�������ID��LOWORD��Ӹ�����32λֵ��ȡ�õͶ��֣�HIWORD��Ӹ�����32λֵ��
// ȡ�ø߶���

// CView* GetActiveView() const;

BOOL CMainFrame::OnCommand(WPARAM wParam, LPARAM lParam)
{
	// TODO: �ڴ����ר�ô����/����û���
	int MenuCmdID = LOWORD(wParam);
	CMFCMenu2View *pView = (CMFCMenu2View *)GetActiveView();
	if (MenuCmdID >= IDM_PHONE_1 &&
		MenuCmdID < IDM_PHONE_1 + pView->m_strArray.GetSize())
	{
		//MessageBox(_T("Main Frame"));
		// ��������ͼ����������豸���������
		CClientDC dc(pView);
		dc.TextOut(0, 0, pView->m_strArray.GetAt(MenuCmdID - IDM_PHONE_1));
	}

	// CFrameWnd���OnCommand����������Ϣ·�ɣ�����Ϣ������ͼ�࣬�����ͼ���
	// ����Ϣ����Ӧ��������Ӧ����������Ϣ·�ɽ�����
	// ֱ�ӷ���TRUE�󣬱�ʾ��Ϣ·�ɵ�CMainFrame��ͽ����ˣ����ڼ������´��ݣ�
	// Ӧ�ó������ͼ�಻����ܵ�����Ϣ
	return TRUE;
	//return CFrameWnd::OnCommand(wParam, lParam);
}
