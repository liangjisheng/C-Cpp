// SignalLampCtrl.cpp : 实现文件
//

#include "stdafx.h"
#include "SignalLamp.h"
#include "SignalLampCtrl.h"


// CSignalLampCtrl

IMPLEMENT_DYNAMIC(CSignalLampCtrl, CWnd)

CSignalLampCtrl::CSignalLampCtrl()
{
	//注册控件类
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

	//设置控件类信息
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

	//注册控件类
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



// CSignalLampCtrl 消息处理程序

void CSignalLampCtrl::OnPaint()
{
	CBitmap		bmLight;
	BITMAP		bmData;
	CPaintDC	dc(this);
	CDC*		pMemDC = new CDC;

	bmLight.LoadBitmap(nIDBitmap);
	//获取位图数据
	bmLight.GetBitmap(&bmData);

	//创建兼容DC
	pMemDC->CreateCompatibleDC(&dc);

	//贴图
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
	//获取位图数据
	bmLight.GetBitmap(&bmData);

	GetWindowRect(rectCtrl);
	rectCtrl.bottom	= rectCtrl.top+bmData.bmHeight;
	rectCtrl.right	= rectCtrl.left+bmData.bmWidth;
	GetParent()->ScreenToClient(rectCtrl);
	MoveWindow(rectCtrl);
}
