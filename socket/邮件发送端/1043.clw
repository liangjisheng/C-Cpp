; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSet
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "1043.h"

ClassCount=4
Class1=CMy1043App
Class2=CMy1043Dlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_MY1043_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Class4=CSet
Resource4=IDD_DIALOG1

[CLS:CMy1043App]
Type=0
HeaderFile=1043.h
ImplementationFile=1043.cpp
Filter=N

[CLS:CMy1043Dlg]
Type=0
HeaderFile=1043Dlg.h
ImplementationFile=1043Dlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CMy1043Dlg

[CLS:CAboutDlg]
Type=0
HeaderFile=1043Dlg.h
ImplementationFile=1043Dlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MY1043_DIALOG]
Type=1
Class=CMy1043Dlg
ControlCount=12
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_SENDER,edit,1350631552
Control6=IDC_RECVER,edit,1350631552
Control7=IDC_SUBJECT,edit,1350631552
Control8=IDC_CONFIG,button,1342242816
Control9=IDC_SENDMAIL,button,1342242816
Control10=IDC_RECVMAIL,button,1342242816
Control11=IDC_LOOKHELP,button,1342242816
Control12=IDC_MAILTEXT,edit,1352728644

[DLG:IDD_DIALOG1]
Type=1
Class=CSet
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDC_RESET,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_SERVERADDR,edit,1350631552
Control6=IDC_PORT,edit,1350631552

[CLS:CSet]
Type=0
HeaderFile=Set.h
ImplementationFile=Set.cpp
BaseClass=CDialog
Filter=D
LastObject=CSet
VirtualFilter=dWC

