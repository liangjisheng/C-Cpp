; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CClientSocket
LastTemplate=CAsyncSocket
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "1144.h"

ClassCount=4
Class1=CMy1144App
Class2=CMy1144Dlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CClientSocket
Resource3=IDD_MY1144_DIALOG

[CLS:CMy1144App]
Type=0
HeaderFile=1144.h
ImplementationFile=1144.cpp
Filter=N

[CLS:CMy1144Dlg]
Type=0
HeaderFile=1144Dlg.h
ImplementationFile=1144Dlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CMy1144Dlg

[CLS:CAboutDlg]
Type=0
HeaderFile=1144Dlg.h
ImplementationFile=1144Dlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MY1144_DIALOG]
Type=1
Class=CMy1144Dlg
ControlCount=10
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT_ADDR,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_PORT,edit,1350631552
Control5=IDC_CONNECT,button,1342242816
Control6=IDC_EDIT_RECVTEXT,edit,1352730692
Control7=IDC_EDIT_SENDTEXT,edit,1350631552
Control8=IDC_SEND,button,1342242816
Control9=IDOK,button,1342242817
Control10=IDCANCEL,button,1342242816

[CLS:CClientSocket]
Type=0
HeaderFile=ClientSocket.h
ImplementationFile=ClientSocket.cpp
BaseClass=CAsyncSocket
Filter=N
LastObject=CClientSocket
VirtualFilter=q

