// ServerSocket.cpp : implementation file
//

#include "stdafx.h"
#include "1143.h"
#include "ServerSocket.h"
#include "1143Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CServerSocket

CServerSocket::CServerSocket()
{
}

CServerSocket::~CServerSocket()
{
	CMy1143Dlg * dlg=(CMy1143Dlg *)AfxGetApp()->GetMainWnd();
	dlg->s.Close();
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CServerSocket, CAsyncSocket)
	//{{AFX_MSG_MAP(CServerSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CServerSocket member functions

void CServerSocket::OnAccept(int nErrorCode) 
{
	CMy1143Dlg * dlg=(CMy1143Dlg *)AfxGetApp()->GetMainWnd();
	if(dlg->s.Accept(dlg->c)) {
		dlg->m_rEdit.SetWindowText("接收客户端连接请求成功......\r\n");
		(dlg->GetDlgItem(IDC_SEND))->EnableWindow(true);
		dlg->m_sEdit.SetFocus();
	}
	else 
		dlg->m_rEdit.SetWindowText("接收客户端连接请求失败......\r\n");
	CAsyncSocket::OnAccept(nErrorCode);
}
