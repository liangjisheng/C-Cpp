
// HWDetectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "HWDetect.h"
#include "HWDetectDlg.h"
#include "afxdialogex.h"

#pragma comment(lib, "Setupapi.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

static const GUID GUID_DEVINTERFACE_LIST[] = 
{
	// GUID_DEVINTERFACE_USB_DEVICE
	{ 0xA5DCBF10, 0x6530, 0x11D2, { 0x90, 0x1F, 0x00, 0xC0, 0x4F, 0xB9, 0x51, 0xED } },

	//GUID_DEVINTERFACE_VOLUME
	{ 0x53f5630d, 0xb6bf, 0x11d0, { 0x94, 0xf2, 0x00, 0xa0, 0xc9, 0x1e, 0xfb, 0x8b } },

	// GUID_DEVINTERFACE_DISK
	{ 0x53f56307, 0xb6bf, 0x11d0, { 0x94, 0xf2, 0x00, 0xa0, 0xc9, 0x1e, 0xfb, 0x8b } },

	// GUID_DEVINTERFACE_HID, 
	{ 0x4D1E55B2, 0xF16F, 0x11CF, { 0x88, 0xCB, 0x00, 0x11, 0x11, 0x00, 0x00, 0x30 } },

	// GUID_NDIS_LAN_CLASS
	{ 0xad498944, 0x762f, 0x11d0, { 0x8d, 0xcb, 0x00, 0xc0, 0x4f, 0xc3, 0x35, 0x8c } },

	// USB Raw Device
	{ 0xa5dcbf10, 0x6530, 0x11d2, { 0x90, 0x1f, 0x00, 0xc0, 0x4f, 0xb9, 0x51, 0xed} },

	// Palm
	{ 0x784126bf, 0x4190, 0x11d4, { 0xb5, 0xc2, 0x00, 0xc0, 0x4f, 0x68, 0x7a, 0x67} }
};

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


CHWDetectDlg::CHWDetectDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CHWDetectDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CHWDetectDlg::~CHWDetectDlg()
{
	// 退出时反注册
	::UnregisterDeviceNotification(hDevNotify);         
	hDevNotify = NULL;
}

void CHWDetectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CHWDetectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DEVMODECHANGE()
	// ON_MESSAGE(WM_DEVICECHANGE, OnDeviceChange)
	ON_WM_DEVICECHANGE()
	ON_WM_QUERYENDSESSION()
END_MESSAGE_MAP()


// CHWDetectDlg message handlers

BOOL CHWDetectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	DEV_BROADCAST_DEVICEINTERFACE NotificationFilter;
	ZeroMemory( &NotificationFilter, sizeof(NotificationFilter));
	NotificationFilter.dbcc_size = sizeof(DEV_BROADCAST_DEVICEINTERFACE);
	NotificationFilter.dbcc_devicetype = DBT_DEVTYP_DEVICEINTERFACE;
	//NotificationFilter.dbcc_devicetype = DBT_DEVTYP_VOLUME;
	
	for(int i = 0; i < sizeof(GUID_DEVINTERFACE_LIST) / sizeof(GUID); i++) 
	{
		//NotificationFilter.dbcc_classguid = GUID_DEVINTERFACE_LIST[1];
		NotificationFilter.dbcc_classguid = GUID_DEVINTERFACE_LIST[i];
		hDevNotify = RegisterDeviceNotification(this->GetSafeHwnd(), 
			&NotificationFilter, DEVICE_NOTIFY_WINDOW_HANDLE);
		if( !hDevNotify )
			return FALSE;
	}

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CHWDetectDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CHWDetectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CHWDetectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CHWDetectDlg::OnDevModeChange(LPTSTR lpDeviceName)
{
	MessageBox(lpDeviceName, _T("title"), MB_OKCANCEL);

	CDialogEx::OnDevModeChange(lpDeviceName);
}


// 实现某些功能的时候使用到了USB设备，需要根据USB设备的插拔来更改程序的状态，
// 这个时候就用到了WM_DEVICECHANGE消息。
// 需要注意的是：
// 1. WM_DEVICECHANGE消息只能手动添加，类向导中没有
// 2. 这个消息只有顶层窗口才会收到（如果你是开发嵌在网页中的OCX，那么你无法在OCX的ctrl中接收到这个消息）
// nEventType 事件类型。有关可能取值的描述参见说明部分。
// dwData 包含了与事件有关的数据的结构的地址。它的含义依赖于给定的事件。
BOOL CHWDetectDlg::OnDeviceChange(UINT nEventType, DWORD dwData)
{
	PDEV_BROADCAST_HDR lpdb = (PDEV_BROADCAST_HDR)dwData;  
	switch (nEventType)        
	{        
		// 有设备插入并且可用
	case DBT_DEVICEARRIVAL:
		// MessageBox(_T("设备已经成功插入"), _T("title"), MB_OKCANCEL);
		// 需要根据DEV_BROADCAST_HDR中的dbch_devicetype值来确定设备类型

		if (lpdb -> dbch_devicetype == DBT_DEVTYP_VOLUME)					// 逻辑磁盘盘卷
		{  
			PDEV_BROADCAST_VOLUME lpdbv = (PDEV_BROADCAST_VOLUME)lpdb;  
			TCHAR szVol[100] = {0};					//卷标
			TCHAR szBuffer[100] = {0};				//缓冲
			DWORD dwVol = 0;						//盘符
			int i = 0;
			DWORD dwDrive = lpdbv->dbcv_unitmask;
			for (i = 0 ; i < 32 ; i++)
			{
				if (dwDrive & (1 << i))				//找到第一个可用的逻辑盘符，神笔在这里。
					break;        
			}
			::wsprintf(szBuffer, TEXT("得到新的设备%c"), 'A' + i);
			//::AfxMessageBox(szBuffer,1,0);
			::wsprintf(szBuffer, TEXT("%c:\\"), 'A' + i);
			// 通过盘符得到卷标信息
			::GetVolumeInformation(szBuffer, szVol, 32, &dwVol, NULL, NULL, NULL, 0);
			::AfxMessageBox(szVol, 1, 0);

			//TCHAR c = FirstDriveFromMask(lpdbv ->dbcv_unitmask);			//得到u盘盘符  
			//CString str(c);
			//MessageBox(str, _T("title"), MB_OKCANCEL);
		}

		if(lpdb->dbch_devicetype == DBT_DEVTYP_DEVICEINTERFACE)				// 某类设备的接口
		{
			 PDEV_BROADCAST_DEVICEINTERFACE pDevInf = (PDEV_BROADCAST_DEVICEINTERFACE)lpdb;
			 // 通过PDEV_BROADCAST_DEVICEINTERFACE的dbcc_name是不能知道哪个设备安装到了当前系统，
			 // dbcc_name仅仅是操作系统内部使用来作为ID的，想要获取设备描述信息或者设备别名有2中方法
			 // 1 直接读注册表, \\HKLM\SYSTEM\CurrentControlSet\Enum\USB\Vid_04e8&Pid_503b\0002F9A9828E0F06
			 // 2 使用 SetupDiXxx 系列API,下面的这行代码使用SetupDiXxx系列来获取设备描述信息
			 UpdateDevice(pDevInf, dwData);
			 //UpDateDevice_1(pDevInf, dwData);

			 CString szDevId = pDevInf->dbcc_name + 4;
			 int idx = szDevId.ReverseFind(_T('#'));
			 ASSERT( -1 != idx );
			 szDevId.Truncate(idx);
			 szDevId.Replace(_T('#'), _T('\\'));

			 CFile file(_T("insert.txt"), CFile::modeCreate | CFile::modeWrite |CFile::modeNoTruncate);
			 file.SeekToEnd();
			 szDevId = szDevId.Left(szDevId.ReverseFind(_T('\\')));
			 szDevId += _T("\r\n");
			 file.Write(szDevId, sizeof(TCHAR) * szDevId.GetLength());
			 file.Close();
		}

		if(lpdb->dbch_devicetype == DBT_DEVTYP_HANDLE)						// 文件系统句柄
		{
			PDEV_BROADCAST_HANDLE pDevHnd = (PDEV_BROADCAST_HANDLE)lpdb;
			MessageBox(_T("DBT_DEVTYP_HANDLE"), _T("title"), MB_OKCANCEL);
		}

		if(lpdb->dbch_devicetype == DBT_DEVTYP_OEM)							// OEM或IHV厂商自定义设定的设备类型. 
		{
			 PDEV_BROADCAST_OEM pDevOem = (PDEV_BROADCAST_OEM)lpdb;
			MessageBox(_T("DBT_DEVTYP_OEM"), _T("title"), MB_OKCANCEL);
		}

		if(lpdb->dbch_devicetype == DBT_DEVTYP_PORT)						// 端口设备(串行或者并行)
		{
			PDEV_BROADCAST_PORT lpdbv = (PDEV_BROADCAST_PORT)lpdb;   
			int len = _tcslen(lpdbv->dbcp_name);  
			CString name(lpdbv->dbcp_name);									//COM8  
			MessageBox(name, _T("title"), MB_OKCANCEL);
		}

		break;

		// 设备已经成功移出
	case DBT_DEVICEREMOVECOMPLETE:
		if (lpdb -> dbch_devicetype == DBT_DEVTYP_VOLUME)					// 逻辑磁盘盘卷
		{  
			PDEV_BROADCAST_VOLUME lpdbv = (PDEV_BROADCAST_VOLUME)lpdb;  
			TCHAR szVol[100] = {0};					//卷标
			TCHAR szBuffer[100] = {0};				//缓冲
			DWORD dwVol = 0;						//盘符
			int i = 0;
			DWORD dwDrive = lpdbv->dbcv_unitmask;
			for (i = 0 ; i < 32 ; i++)
			{
				if (dwDrive & (1 << i))				//找到第一个可用的逻辑盘符，神笔在这里。
					break;        
			}
			::wsprintf(szBuffer, TEXT("得到新的设备%c"), 'A' + i);
			//::AfxMessageBox(szBuffer,1,0);
			::wsprintf(szBuffer, TEXT("%c:\\"), 'A' + i);
			// 通过盘符得到卷标信息
			::GetVolumeInformation(szBuffer, szVol, 32, &dwVol, NULL, NULL, NULL, 0);
			::AfxMessageBox(szVol, 1, 0);

			// TCHAR c = FirstDriveFromMask(lpdbv ->dbcv_unitmask);			//得到u盘盘符  
			// CString str(c);
			// MessageBox(str, _T("title"), MB_OKCANCEL);
		}

		if(lpdb->dbch_devicetype == DBT_DEVTYP_DEVICEINTERFACE)				// 某类设备的接口
		{
			PDEV_BROADCAST_DEVICEINTERFACE pDevInf = (PDEV_BROADCAST_DEVICEINTERFACE)lpdb;
			// 通过PDEV_BROADCAST_DEVICEINTERFACE的dbcc_name是不能知道哪个设备安装到了当前系统，
			// dbcc_name仅仅是操作系统内部使用来作为ID的，想要获取设备描述信息或者设备别名有2中方法
			// 1 直接读注册表, \\HKLM\SYSTEM\CurrentControlSet\Enum\USB\Vid_04e8&Pid_503b\0002F9A9828E0F06
			// 2 使用 SetupDiXxx 系列API,下面的这行代码使用SetupDiXxx系列来获取设备描述信息
			UpdateDevice(pDevInf, dwData);
			//UpDateDevice_1(pDevInf, dwData);

			CString szDevId = pDevInf->dbcc_name + 4;
			int idx = szDevId.ReverseFind(_T('#'));
			ASSERT( -1 != idx );
			szDevId.Truncate(idx);
			szDevId.Replace(_T('#'), _T('\\'));

			CFile file(_T("leave.txt"), CFile::modeCreate | CFile::modeWrite |CFile::modeNoTruncate);
			file.SeekToEnd();
			szDevId = szDevId.Left(szDevId.ReverseFind(_T('\\')));
			szDevId += _T("\r\n");
			file.Write(szDevId, sizeof(TCHAR) * szDevId.GetLength());
			file.Close();
		}

		if(lpdb->dbch_devicetype == DBT_DEVTYP_HANDLE)						// 文件系统句柄
		{
			PDEV_BROADCAST_HANDLE pDevHnd = (PDEV_BROADCAST_HANDLE)lpdb;
			MessageBox(_T("DBT_DEVTYP_HANDLE"), _T("title"), MB_OKCANCEL);
		}

		if(lpdb->dbch_devicetype == DBT_DEVTYP_OEM)							// OEM或IHV厂商自定义设定的设备类型. 
		{
			PDEV_BROADCAST_OEM pDevOem = (PDEV_BROADCAST_OEM)lpdb;
			MessageBox(_T("DBT_DEVTYP_OEM"), _T("title"), MB_OKCANCEL);
		}

		if(lpdb->dbch_devicetype == DBT_DEVTYP_PORT)						// 端口设备(串行或者并行)
		{
			PDEV_BROADCAST_PORT lpdbv = (PDEV_BROADCAST_PORT)lpdb;   
			int len = _tcslen(lpdbv->dbcp_name);  
			CString name(lpdbv->dbcp_name);									//COM8  
			MessageBox(name, _T("title"), MB_OKCANCEL);
		}

		break;

		// 允许清除被请求的设备。任何应用程序都可以拒绝这个请求并取消清除操作。  
	case DBT_DEVICEQUERYREMOVE:
		break;
		// 清除设备的请求被取消了
	case DBT_DEVICEQUERYREMOVEFAILED:
		break;
		//  设备将要被清除。不能拒绝
	case DBT_DEVICEREMOVEPENDING:
		break;
		// 与设备有关的事件
	case DBT_DEVICETYPESPECIFIC:
		break;
		// 当前配置发生了变化
	case DBT_CONFIGCHANGED:
		break;
		// 设备节点发生了变化
	case DBT_DEVNODES_CHANGED:
		break;
	default:
		break;
	}        
	return FALSE;    
}


TCHAR CHWDetectDlg::FirstDriveFromMask(ULONG unitmask)
{  
	char i;  
	for (i = 0; i < 26; ++i)  
	{  
		if (unitmask & 0x1)//看该驱动器的状态是否发生了变化  
			break;  
		unitmask = unitmask >> 1;  
	}  
	return (i + 'A');  
}  


void CHWDetectDlg::UpdateDevice(PDEV_BROADCAST_DEVICEINTERFACE pDevInf, WPARAM wParam)
{
	// 通过dbcc_name来获得设备描述信息或是设备别名
	// 1 首先通过SetupDiGetClassDevs()来获得设备信息集 HDEVINFO，这个操作等同于是一个获取目录句柄的过程。
	// 2 接着使用SetupDiEnumDeviceInfo()来遍历出这个设备信息集内的所有设备，
	// 这个操作等同于遍历目录列表。对于每个遍历出的，我们可以获得SP_DEVINFO_DATA,这个等同于是文件句柄。
	// 3 在上面的枚举过程中，使用SetupDiGetDeviceInstanceId()来读取每个设备的实例ID，
	// 这个操作等同于是读文件的属性，一个设备的实例ID类似这个：”USB\Vid_04e8&Pid_503b\0002F9A9828E0F06”,
	// 和dbcc_name非常像。
	// 4 如果设备的实例ID等同于dbcc_name，则通过SetupDiGetDeviceRegistryProperty()来获取设备描述信息或是设备别名信息。

	// dbcc_name:
	// \\?\USB#Vid_04e8&Pid_503b#0002F9A9828E0F06#{a5dcbf10-6530-11d2-901f-00c04fb951ed}
	// convert to
	// USB\Vid_04e8&Pid_503b\0002F9A9828E0F06

	ASSERT(lstrlen(pDevInf->dbcc_name) > 4);
	CString szDevId = pDevInf->dbcc_name + 4;
	int idx = szDevId.ReverseFind(_T('#'));
	ASSERT( -1 != idx );
	szDevId.Truncate(idx);
	szDevId.Replace(_T('#'), _T('\\'));
	szDevId.MakeUpper();

	CString szClass;
	idx = szDevId.Find(_T('\\'));
	ASSERT(-1 != idx );
	szClass = szDevId.Left(idx);

	// if we are adding device, we only need present devices
	// otherwise, we need all devices
	DWORD dwFlag = DBT_DEVICEARRIVAL != wParam
		? DIGCF_ALLCLASSES : (DIGCF_ALLCLASSES | DIGCF_PRESENT);
	HDEVINFO hDevInfo = SetupDiGetClassDevs(NULL, szClass, NULL, dwFlag);
	if( INVALID_HANDLE_VALUE == hDevInfo )
	{
		AfxMessageBox(CString("SetupDiGetClassDevs(): ")
			+ _com_error(GetLastError()).ErrorMessage(), MB_ICONEXCLAMATION);
		return;
	}

	SP_DEVINFO_DATA* pspDevInfoData =
		(SP_DEVINFO_DATA*)HeapAlloc(GetProcessHeap(), 0, sizeof(SP_DEVINFO_DATA));
	pspDevInfoData->cbSize = sizeof(SP_DEVINFO_DATA);
	for(int i=0; SetupDiEnumDeviceInfo(hDevInfo,i,pspDevInfoData); i++)
	{
		DWORD DataT ;
		DWORD nSize=0 ;
		TCHAR buf[MAX_PATH] = {0};

		if ( !SetupDiGetDeviceInstanceId(hDevInfo, pspDevInfoData, buf, sizeof(buf), &nSize) )
		{
			AfxMessageBox(CString("SetupDiGetDeviceInstanceId(): ")
				+ _com_error(GetLastError()).ErrorMessage(), MB_ICONEXCLAMATION);
			break;
		}

		if ( szDevId == buf )
		{
			// device found
			if ( SetupDiGetDeviceRegistryProperty(hDevInfo, pspDevInfoData,
				SPDRP_FRIENDLYNAME, &DataT, (PBYTE)buf, sizeof(buf), &nSize) ) 
			{
				// do nothing
				MessageBox(buf, _T("title"), MB_OKCANCEL);
			}
			else if ( SetupDiGetDeviceRegistryProperty(hDevInfo, pspDevInfoData,
				SPDRP_DEVICEDESC, &DataT, (PBYTE)buf, sizeof(buf), &nSize) ) 
			{
				// do nothing
				MessageBox(buf, _T("title"), MB_OKCANCEL);
			}
			else
			{
				lstrcpy(buf, _T("Unknown"));
			}
			// update UI
			// .....
			// .....
			break;
		}
	}

	if ( pspDevInfoData ) 
		HeapFree(GetProcessHeap(), 0, pspDevInfoData);
	SetupDiDestroyDeviceInfoList(hDevInfo);
}


BOOL CHWDetectDlg::OnQueryEndSession()
{
	if (!CDialogEx::OnQueryEndSession())
		return FALSE;
	
	// 当关机或者log off的时候会发送此消息

	return TRUE;
}


void CHWDetectDlg::UpDateDevice_1(PDEV_BROADCAST_DEVICEINTERFACE pDevInf, WPARAM wParam)
{
	ASSERT(lstrlen(pDevInf->dbcc_name) > 4);
	CString szDevId = pDevInf->dbcc_name + 4;
	int idx = szDevId.ReverseFind(_T('#'));
	ASSERT( -1 != idx );
	szDevId.Truncate(idx);
	szDevId.Replace(_T('#'), _T('\\'));
	szDevId.MakeUpper();

	CString szClass;
	idx = szDevId.Find(_T('\\'));
	ASSERT(-1 != idx );
	szClass = szDevId.Left(idx);
	DWORD dwFlag = DBT_DEVICEARRIVAL != wParam
		? DIGCF_ALLCLASSES : (DIGCF_ALLCLASSES | DIGCF_PRESENT);
	// HDEVINFO hDevInfo = SetupDiGetClassDevs(NULL, szClass, NULL, dwFlag);

	HDEVINFO info = SetupDiGetClassDevs(NULL, szClass, NULL, dwFlag);
	if(info == INVALID_HANDLE_VALUE)
	{
		MessageBox(_T("No HDEVINFO avaliable for this GUID\n"), _T("title"), MB_OKCANCEL);
		//AfxMessageBox(_T("No HDEVINFO avaliable for this GUID\n"), MB_OKCANCEL);
		return ;
	}
	 
	SP_INTERFACE_DEVICE_DATA ifdata;
	ifdata.cbSize = sizeof(ifdata);
	DWORD instance = 0;
	SP_DEVINFO_DATA* pspDevInfoData =
		(SP_DEVINFO_DATA*)HeapAlloc(GetProcessHeap(), 0, sizeof(SP_DEVINFO_DATA));
	pspDevInfoData->cbSize = sizeof(SP_DEVINFO_DATA);
	if(!SetupDiEnumDeviceInterfaces(info, pspDevInfoData, &ifdata.InterfaceClassGuid, instance, &ifdata))
	{
		MessageBox(_T("No SP_INTERFACE_DEVICE_DATA available for this GUID instance\n"), 
			_T("title"), MB_OKCANCEL);
		// AfxMessageBox("No SP_INTERFACE_DEVICE_DATA available for this GUID instance");
		SetupDiDestroyDeviceInfoList(info);
		return ;
	}
	 
	//得到符号链接名
	DWORD ReqLen;
	SetupDiGetDeviceInterfaceDetail(info, &ifdata, NULL, 0, &ReqLen, NULL);
	PSP_INTERFACE_DEVICE_DETAIL_DATA ifDetail=(PSP_INTERFACE_DEVICE_DETAIL_DATA)new char[ReqLen];
	if(ifDetail == NULL)
	{
		MessageBox(_T("Error 1"), _T("title"), MB_OKCANCEL);
		// AfxMessageBox(CString(_T("Error 1")));
		SetupDiDestroyDeviceInfoList(info);
		return ;
	}
	ifDetail->cbSize = sizeof(SP_INTERFACE_DEVICE_DETAIL_DATA);
	if(!SetupDiGetDeviceInterfaceDetail(info, &ifdata, ifDetail, ReqLen, NULL, NULL))
	{
		MessageBox(_T("Error 2"), _T("title"), MB_OKCANCEL);
		// AfxMessageBox("Error 2");
		SetupDiDestroyDeviceInfoList(info);
		delete ifDetail;
		ifDetail = NULL;
		return ;
	}
	char buff[256] = {0};
	char * format = "Symbolic link is %s\n";
	sprintf(buff, format, ifDetail->DevicePath);
	HANDLE rv = CreateFile(ifDetail->DevicePath, GENERIC_READ|GENERIC_WRITE,
		FILE_SHARE_READ|FILE_SHARE_WRITE,NULL,
		OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL|FILE_FLAG_OVERLAPPED,NULL);

	//end of 得到设备句柄
	delete ifDetail;
	ifDetail = NULL;
	if ( pspDevInfoData ) 
	{
		HeapFree(GetProcessHeap(), 0, pspDevInfoData);
		pspDevInfoData = NULL;
	}
	SetupDiDestroyDeviceInfoList(info);

	/*hDevice=rv;
	DWORD ThreadId;
	hThread=CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)UpDate,this,0,&ThreadId);*/
	/*m_EchoLed1.EnableWindow(TRUE);
	m_EchoLed2.EnableWindow(TRUE);
	m_OpenDevice.SetWindowText("关闭设备");*/
}

