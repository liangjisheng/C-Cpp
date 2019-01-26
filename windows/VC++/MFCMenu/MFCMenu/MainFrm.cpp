
// MainFrm.cpp : CMainFrame ���ʵ��
//

#include "stdafx.h"
#include "MFCMenu.h"

#include "MainFrm.h"

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
	ON_UPDATE_COMMAND_UI(ID_FILE_NEW, &CMainFrame::OnUpdateFileNew)
	ON_COMMAND(IDM_SHOW, &CMainFrame::OnShow)
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
	m_bAutoMenuEnable = FALSE;
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

	// ���ļ�����һ���Ӳ˵���������Ϊ0�����ļ����Ӳ˵��µġ��½����˵����������Ϊ0 
	// �Բ˵���˵�����Ҫ����ĳ���˵���ȿ���ͨ���ò˵���ı�ʶID��Ҳ����ͨ����λ��
	// ������ʵ�ַ��ʡ��������Ӳ˵���˵��ֻ��ͨ�������Ž��з��ʣ���Ϊ�Ӳ˵���û�б�ʶ�ŵ�

	// �еĲ˵����ϻش򹳣����������͵Ĳ˵�Ϊ��ǲ˵�
	// �ڿ�ܴ����У���ȡ����Ĳ˵���ָ��
	// CMenu* GetMenu() const;
	// CMenu��һ��MFC�࣬��Windows�˵����HMENU��һ����װ���ṩ��һЩ��˵������йصĳ�Ա����
	// ��ȡһ���˵����Ӳ˵���ֻ��ͨ�������Ż���Ӳ˵�
	// CMenu* GetSubMenu(int nPos) const;

	// ������������������ִ��CMenu�����ָ�룬GetMenu��CWnd�ĳ�Ա����������ָ�����˵���
	// �����ָ�룻GetSubMenu��CMenu�ĳ�Ա������������posָ�����Ӳ˵���ָ��

	// UINT CheckMenuItem(UINT nIDCheckItem, UINT nCheck);
	// ��һ������ָ����Ҫ����Ĳ˵��ȡֵ�ɵڶ�������������
	// �ڶ�������nCheckָ���������ò˵���Լ���ζ�λ�ò˵����λ��
	// MF_CHECKED,			���ò˵���ĸ�ѡ���
	// MF_UNCHECKED,		�Ƴ��˵���ĸ�ѡ���
	// MF_BYPOSITION,		���ݲ˵����λ�������ʲ˵����һ�������ǲ˵����������
	// MF_BYCOMMAND			���ݲ˵�������������ʲ˵����һ�������ǲ˵��������ID

	// GetMenu()->GetSubMenu(0)->CheckMenuItem(0, MF_BYPOSITION | MF_CHECKED);
	GetMenu()->GetSubMenu(0)->CheckMenuItem(ID_FILE_NEW, MF_BYCOMMAND | MF_CHECKED);

	// ��ЩӦ�ó�����Ӳ˵�����һ���˵������Դ�����ʽ��ʾ�ģ���������ʽ��ʾ�ľ��Ǹ��Ӳ˵���
	// Ĭ�ϲ˵������CMenu���SetDefaultItem()��Ա�������Ĭ�ϲ˵��������
	// BOOL SetDefaultItem(UINT uItem, BOOL fByPos = FALSE);
	// fByPos������ͨ���˵�����������ͨ���˵��������ID�����ʲ˵���
	// �ѡ��ļ����Ӳ˵�����ġ��򿪡��˵�������Ϊ���Ӳ˵���Ĭ�ϲ˵���

	//GetMenu()->GetSubMenu(0)->SetDefaultItem(1, TRUE);
	GetMenu()->GetSubMenu(0)->SetDefaultItem(ID_FILE_OPEN, FALSE);

	// һ���Ӳ˵�ֻ����һ��Ĭ�ϲ˵���
	GetMenu()->GetSubMenu(0)->SetDefaultItem(5, TRUE);


	// BOOL SetMenuItemBitmaps(UINT nPosition, UINT nFlags, const CBitmap& pBmpUnchecked,
	//							const CBitmap* pBmpChecked);
	// ��һ��������ȡֵҲ���еڶ�������������������һ����
	// ����������ָ����ȡ���˵���ѡ��״̬ʱ��λͼ��
	// ���ĸ�����ָ��ѡ�в˵���ʱ��ʾ��λͼ�����������ò˵�����ʾ����λͼ��
	// ��������ѡ�к�δѡ��״̬
	// ���ܰ�λͼ��Ϊ�ֲ�������ʹ�ã�����OnCreate()�������ڳ����оͿ�����λͼ��

	// int GetSystemMetrics(int nIndex);
	// ֻ��һ������������ָ��ϣ����ȡ�Ĳ���ϵͳ��Ϣ�����ò�����ֵΪSM_CXMENUCHECK
	// ����SM_CYMENUCHECKʱ�������������ȡ��ǲ˵����ϱ��ͼ�ε�Ĭ�ϳߴ�

	/*CString str = _T("");
	str.Format(_T("x = %d, y = %d"), GetSystemMetrics(SM_CXMENUCHECK),
		GetSystemMetrics(SM_CYMENUCHECK));
	MessageBox(str, _T("title"), MB_OKCANCEL);
	m_bitmap.LoadBitmap(IDB_BITMAP1);
	GetMenu()->GetSubMenu(0)->SetMenuItemBitmaps(0, MF_BYPOSITION, &m_bitmap, &m_bitmap);*/


	// ���ò˵����һ������Ҳ���ɵڶ�������������
	// MF_DISABLED,MF_ENABLED,MF_GRAYED
	// UINT EnableMenuItem(UINT nIDEnableItem, UINT nEnable);
	// �˵��Ļ�ɫ��ʾ�����״̬�ǲ�ͬ�ģ����ֻ�����˱�ң�û�����ý��ã�
	// ������˵���ǿ���ʹ�õģ�һ���MF_DISABLED��MF_GRAYED����һ��
	// ����ô�������Ǳ����

	// һ����CMainFrame��Ĺ��캯���аѳ�Ա����m_bAutoMenuEnable����ΪFALSE��
	// �Ͳ���Ҫ��ON_UPDATE_COMMAND_UI��ON_COMMAND��Ϣ������Ӧ�ˣ�CMenu���
	// EnableMenuItem�����ܹ�����������ʵ����MFCΪ�˵��ṩ��һ��������»���
	// ����������ʱ�����ݴ˻���ȥ�ж��Ǹ��˵�����ʹ�ã��Ǹ��˵����ܹ�ʹ�ã�Ȼ��
	// ��ʾ����Ӧ��״̬��Ĭ������£����в˵���ĸ��¶�����MFC��������»�����ɵ�
	// ����������Լ����Ĳ˵����״̬���Ǿͱ����m_bAutoMenuEnable����ΪFALSE
	// ֮�������Լ��Բ˵���ĸ��²��������ã��ڹ��캯��������ΪFALSE
	GetMenu()->GetSubMenu(0)->EnableMenuItem(1, MF_BYPOSITION | MF_DISABLED | MF_GRAYED);

	// BOOL SetMenu(CMenu *pMenu);		����Ϊ�յ�ʱ���Ƴ��˵�
	SetMenu(NULL);

	// �ڱ���У�����ʹ���Զ�����������ܲ˵��⣬�������Լ�����һ���˵���Դ������
	// ͨ�����ַ�ʽ������ʵ�ֶ�̬��������˵��Ĺ���
	// ����Ĳ˵�������һ���ֲ����󣬵���OnCreate()����֮��ͻ���ʧ������һ���
	// �˵��ͻᱨ�쳣��һ�ְ취�ǽ�����˵�������ɿ����ĳ�Ա����
	// ��һ�ַ���������˵�������Ϊ�ֲ����󣬵��ڵ���SetMenu()�Ѵ˶������ó�
	// ���ڵĲ˵�֮����������CMenu�����һ����Ա����Detach���Ա�Ѳ˵������
	// ����˵�������롣

	// SetMenu��Ѳ˵�����Ϊ�����ָ�����²˵������´����ػ棬�Է�ӳ�˵�������
	// �仯��ͬʱҲ���ò˵����������Ȩ�������ڶ��󡣶�����Detach��Ѳ˵����
	// ������˵�������룬�������������˵�������������ڽ���ʱ��������ȥ����
	// һ�������ھ���ӵ��Ȩ�Ĳ˵�������˵��ڴ�������ʱ�Զ����١�
	CMenu me;
	me.LoadMenu(IDR_MAINFRAME);
	SetMenu(&me);
	me.Detach();

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


// UPDATE_COMMAND_UI��Ϣ����Ӧֻ�����ڲ˵����������������ʾ�Ķ����˵�
// (������ʽ�˵�)��Ŀ
// ��Ϊĳ���˵��������һ��UPDATE_COMMAND_UI��Ϣ��Ӧ������MFC�ں�̨�����Ĺ�����:
// ��Ҫ��ʾ�˵�ʱ������ϵͳ����WM_INITMENUPOPUP��Ϣ��Ȼ���ɴ��ڵĻ�����CFrameWnd
// �ӹܡ����ᴴ��һ��CCmdUI���󣬲������ĵ�һ���˵�����������øö����һ����Ա
// ����DoUpdate()�������������CN_UPDATE_COMMAND_UI��Ϣ��������Ϣ����һ��ָ��
// CCmdUI�����ָ�롣����ϵͳ���ж��Ƿ����һ��ON_UPDATE_COMMAND_UI��ȥ�������
// �˵�����Ϣ������ҵ����ͽ��д������������һ���˵����ͬһ��CCmdUI�����
// ����Ϊ��ڶ����˵��������������˳����У�ֱ��������в˵���Ĵ���
// �����MFC���õ�������»��ơ�

void CMainFrame::OnUpdateFileNew(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	// Enable(),SetCheck(), SetText();	ʵ�����ý��ò˵������ñ�ǡ����ò˵����ı�
	// virtual void Enable(BOOL bOn = TRUE);

	// CCmdUI����һ��m_nID��Ա���������ڱ��浱ǰ�˵����������ť����������CCmdUI
	// �����ʾ��UI����ı�ʶ�����Լ���һ���ж�
	if(ID_FILE_NEW == pCmdUI->m_nID)
		pCmdUI->Enable(FALSE);
	// MFC���ò˵�������º���ʱ���Ѿ�ȥȷ�����ض��Ĳ˵��ʵ��Ӧ���������жϣ�
	// �˴�ֻ��Ϊ�˽���֪ʶ

	// CCmdUI�໹��һ����Ա����m_nIndex;�������浱ǰ�˵����λ������
	// �˵���͹��߰�ť��λ���������㷽ʽ��ͬ��Ϊ��֤����״̬����һ�£���ò���
	// �˵����ʶ�򹤾߰�ť��ʶ��ʽ���������á�
}


void CMainFrame::OnShow()
{
	MessageBox(_T("Main show"));
}
