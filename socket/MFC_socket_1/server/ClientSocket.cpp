// ClientSocket.cpp : implementation file
//

#include "stdafx.h"
#include "1143.h"
#include "ClientSocket.h"
#include "1143Dlg.h"

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
	CMy1143Dlg * dlg=(CMy1143Dlg *)AfxGetApp()->GetMainWnd();
	dlg->c.Close();
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
	CString strtext;
	CMy1143Dlg * dlg=(CMy1143Dlg *)AfxGetApp()->GetMainWnd();
	if(dlg->c.Receive(buf,512,0)) {
		dlg->m_rEdit.GetWindowText(strtext);
		strtext=strtext+"client:"+buf+"\r\n";
		dlg->m_rEdit.SetWindowText(strtext);
	}
	else {
		dlg->m_rEdit.GetWindowText(strtext);
		strtext=strtext+"½ÓÊÕÊ§°Ü"+"\r\n";
		dlg->m_rEdit.SetWindowText(strtext);
	}
	CAsyncSocket::OnReceive(nErrorCode);
}