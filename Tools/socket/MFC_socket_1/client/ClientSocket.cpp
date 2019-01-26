// ClientSocket.cpp : implementation file
//

#include "stdafx.h"
#include "1144.h"
#include "ClientSocket.h"
#include "1144Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClientSocket

CClientSocket::CClientSocket()
{
}

CClientSocket::~CClientSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CClientSocket, CAsyncSocket)
	//{{AFX_MSG_MAP(CClientSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CClientSocket member functions

void CClientSocket::OnReceive(int nErrorCode) 
{
	char buf[512]="";
	CString recvtext;
	CMy1144Dlg * dlg=(CMy1144Dlg *)AfxGetApp()->GetMainWnd();
	dlg->m_rEdit.GetWindowText(recvtext);
	dlg->c.Receive(buf,512,0);	 // 0表示正常接收发送数据
	recvtext=recvtext+"server:"+buf+"\r\n";
	dlg->m_rEdit.SetWindowText(recvtext);
	CAsyncSocket::OnReceive(nErrorCode);
}
