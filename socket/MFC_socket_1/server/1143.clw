; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMy1143Dlg
LastTemplate=CAsyncSocket
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "1143.h"

ClassCount=5
Class1=CMy1143App
Class2=CMy1143Dlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CServerSocket
Class5=CClientSocket
Resource3=IDD_MY1143_DIALOG

[CLS:CMy1143App]
Type=0
HeaderFile=1143.h
ImplementationFile=1143.cpp
Filter=N

[CLS:CMy1143Dlg]
Type=0
HeaderFile=1143Dlg.h
ImplementationFile=1143Dlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_EDIT_RECVTEXT

[CLS:CAboutDlg]
Type=0
HeaderFile=1143Dlg.h
ImplementationFile=1143Dlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MY1143_DIALOG]
Type=1
Class=CMy1143Dlg
ControlCount=5
Control1=IDC_EDIT_RECVTEXT,edit,1352730692
Control2=IDC_EDIT_SENDTEXT,edit,1352728644
Control3=IDC_SEND,button,1342242816
Control4=IDOK,button,1342242817
Control5=IDCANCEL,button,1342242816

[CLS:CServerSocket]
Type=0
HeaderFile=ServerSocket.h
ImplementationFile=ServerSocket.cpp
BaseClass=CAsyncSocket
Filter=N
VirtualFilter=q
LastObject=CServerSocket

[CLS:CClientSocket]
Type=0
HeaderFile=ClientSocket.h
ImplementationFile=ClientSocket.cpp
BaseClass=CAsyncSocket
Filter=N
LastObject=CClientSocket
VirtualFilter=q

