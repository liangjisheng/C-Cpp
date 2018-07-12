// SignalLampCtrl.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SignalLamp.h"
#include "SignalLampCtrl.h"


// CSignalLampCtrl

IMPLEMENT_DYNAMIC(CSignalLampCtrl, CWnd)

CSignalLampCtrl::CSignalLampCtrl()
{
	//ע��ؼ���
	RegisterCtrlClass();

	nIDBitmap	= IDB_BITMAP_GREEN;
}

CSignalLampCtrl::~CSignalLampCtrl()
{
}

void CSignalLampCtrl::RegisterCtrlClass()
{
	HINSTANCE hInstance = AfxGetInstanceHandle();

	WNDCLASS	wndclsCtrl;
	ZeroMemory(&wndclsCtrl, sizeof(WNDCLASS));

	if(::GetClassInfo(hInstance, STR_CLASS_NAME, &wndclsCtrl))
		return;

	//���ÿؼ�����Ϣ
	wndclsCtrl.style			= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wndclsCtrl.lpfnWndProc		= ::DefWindowProc;
	wndclsCtrl.cbClsExtra		= 0;
	wndclsCtrl.cbWndExtra		= 0;
	wndclsCtrl.hInstance		= hInstance;
	wndclsCtrl.hIcon			= NULL;
	wndclsCtrl.hCursor			= AfxGetApp()->LoadStandardCursor(IDC_ARROW);
	wndclsCtrl.hbrBackground	= NULL;
	wndclsCtrl.lpszMenuName		= NULL;
	wndclsCtrl.lpszClassName	= STR_CLASS_NAME;

	//ע��ؼ���
	AfxRegisterClass(&wndclsCtrl);
}

void CSignalLampCtrl::SetState(StateType nState)
{
	switch(nState)
	{
	case Normal:nIDBitmap = IDB_BITMAP_GREEN;break;
	case Warning:nIDBitmap = IDB_BITMAP_RED;break;
	case Disable:nIDBitmap = IDB_BITMAP_GRAY;break;
	}

	Invalidate();
}


BEGIN_MESSAGE_MAP(CSignalLampCtrl, CWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CSignalLampCtrl ��Ϣ�������

void CSignalLampCtrl::OnPaint()
{
	CBitmap		bmLight;
	BITMAP		bmData;
	CPaintDC	dc(this);
	CDC*		pMemDC = new CDC;

	bmLight.LoadBitmap(nIDBitmap);
	//��ȡλͼ����
	bmLight.GetBitmap(&bmData);

	//��������DC
	pMemDC->CreateCompatibleDC(&dc);

	//��ͼ
	CBitmap		*pOldBitmap	= pMemDC->SelectObject(&bmLight);
	dc.BitBlt(0, 0, bmData.bmWidth, bmData.bmHeight, pMemDC, 0, 0, SRCCOPY);
	pMemDC->SelectObject(pOldBitmap);

	delete	pMemDC;
}

void CSignalLampCtrl::PreSubclassWindow()
{
	CWnd::PreSubclassWindow();

	CRect		rectCtrl;
	CBitmap		bmLight;
	BITMAP		bmData;

	bmLight.LoadBitmap(nIDBitmap);
	//��ȡλͼ����
	bmLight.GetBitmap(&bmData);

	GetWindowRect(rectCtrl);
	rectCtrl.bottom	= rectCtrl.top+bmData.bmHeight;
	rectCtrl.right	= rectCtrl.left+bmData.bmWidth;
	GetParent()->ScreenToClient(rectCtrl);
	MoveWindow(rectCtrl);
}
