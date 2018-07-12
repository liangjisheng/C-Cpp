
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
	// �˳�ʱ��ע��
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


// ʵ��ĳЩ���ܵ�ʱ��ʹ�õ���USB�豸����Ҫ����USB�豸�Ĳ�������ĳ����״̬��
// ���ʱ����õ���WM_DEVICECHANGE��Ϣ��
// ��Ҫע����ǣ�
// 1. WM_DEVICECHANGE��Ϣֻ���ֶ���ӣ�������û��
// 2. �����Ϣֻ�ж��㴰�ڲŻ��յ���������ǿ���Ƕ����ҳ�е�OCX����ô���޷���OCX��ctrl�н��յ������Ϣ��
// nEventType �¼����͡��йؿ���ȡֵ�������μ�˵�����֡�
// dwData ���������¼��йص����ݵĽṹ�ĵ�ַ�����ĺ��������ڸ������¼���
BOOL CHWDetectDlg::OnDeviceChange(UINT nEventType, DWORD dwData)
{
	PDEV_BROADCAST_HDR lpdb = (PDEV_BROADCAST_HDR)dwData;  
	switch (nEventType)        
	{        
		// ���豸���벢�ҿ���
	case DBT_DEVICEARRIVAL:
		// MessageBox(_T("�豸�Ѿ��ɹ�����"), _T("title"), MB_OKCANCEL);
		// ��Ҫ����DEV_BROADCAST_HDR�е�dbch_devicetypeֵ��ȷ���豸����

		if (lpdb -> dbch_devicetype == DBT_DEVTYP_VOLUME)					// �߼������̾�
		{  
			PDEV_BROADCAST_VOLUME lpdbv = (PDEV_BROADCAST_VOLUME)lpdb;  
			TCHAR szVol[100] = {0};					//���
			TCHAR szBuffer[100] = {0};				//����
			DWORD dwVol = 0;						//�̷�
			int i = 0;
			DWORD dwDrive = lpdbv->dbcv_unitmask;
			for (i = 0 ; i < 32 ; i++)
			{
				if (dwDrive & (1 << i))				//�ҵ���һ�����õ��߼��̷�����������
					break;        
			}
			::wsprintf(szBuffer, TEXT("�õ��µ��豸%c"), 'A' + i);
			//::AfxMessageBox(szBuffer,1,0);
			::wsprintf(szBuffer, TEXT("%c:\\"), 'A' + i);
			// ͨ���̷��õ������Ϣ
			::GetVolumeInformation(szBuffer, szVol, 32, &dwVol, NULL, NULL, NULL, 0);
			::AfxMessageBox(szVol, 1, 0);

			//TCHAR c = FirstDriveFromMask(lpdbv ->dbcv_unitmask);			//�õ�u���̷�  
			//CString str(c);
			//MessageBox(str, _T("title"), MB_OKCANCEL);
		}

		if(lpdb->dbch_devicetype == DBT_DEVTYP_DEVICEINTERFACE)				// ĳ���豸�Ľӿ�
		{
			 PDEV_BROADCAST_DEVICEINTERFACE pDevInf = (PDEV_BROADCAST_DEVICEINTERFACE)lpdb;
			 // ͨ��PDEV_BROADCAST_DEVICEINTERFACE��dbcc_name�ǲ���֪���ĸ��豸��װ���˵�ǰϵͳ��
			 // dbcc_name�����ǲ���ϵͳ�ڲ�ʹ������ΪID�ģ���Ҫ��ȡ�豸������Ϣ�����豸������2�з���
			 // 1 ֱ�Ӷ�ע���, \\HKLM\SYSTEM\CurrentControlSet\Enum\USB\Vid_04e8&Pid_503b\0002F9A9828E0F06
			 // 2 ʹ�� SetupDiXxx ϵ��API,��������д���ʹ��SetupDiXxxϵ������ȡ�豸������Ϣ
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

		if(lpdb->dbch_devicetype == DBT_DEVTYP_HANDLE)						// �ļ�ϵͳ���
		{
			PDEV_BROADCAST_HANDLE pDevHnd = (PDEV_BROADCAST_HANDLE)lpdb;
			MessageBox(_T("DBT_DEVTYP_HANDLE"), _T("title"), MB_OKCANCEL);
		}

		if(lpdb->dbch_devicetype == DBT_DEVTYP_OEM)							// OEM��IHV�����Զ����趨���豸����. 
		{
			 PDEV_BROADCAST_OEM pDevOem = (PDEV_BROADCAST_OEM)lpdb;
			MessageBox(_T("DBT_DEVTYP_OEM"), _T("title"), MB_OKCANCEL);
		}

		if(lpdb->dbch_devicetype == DBT_DEVTYP_PORT)						// �˿��豸(���л��߲���)
		{
			PDEV_BROADCAST_PORT lpdbv = (PDEV_BROADCAST_PORT)lpdb;   
			int len = _tcslen(lpdbv->dbcp_name);  
			CString name(lpdbv->dbcp_name);									//COM8  
			MessageBox(name, _T("title"), MB_OKCANCEL);
		}

		break;

		// �豸�Ѿ��ɹ��Ƴ�
	case DBT_DEVICEREMOVECOMPLETE:
		if (lpdb -> dbch_devicetype == DBT_DEVTYP_VOLUME)					// �߼������̾�
		{  
			PDEV_BROADCAST_VOLUME lpdbv = (PDEV_BROADCAST_VOLUME)lpdb;  
			TCHAR szVol[100] = {0};					//���
			TCHAR szBuffer[100] = {0};				//����
			DWORD dwVol = 0;						//�̷�
			int i = 0;
			DWORD dwDrive = lpdbv->dbcv_unitmask;
			for (i = 0 ; i < 32 ; i++)
			{
				if (dwDrive & (1 << i))				//�ҵ���һ�����õ��߼��̷�����������
					break;        
			}
			::wsprintf(szBuffer, TEXT("�õ��µ��豸%c"), 'A' + i);
			//::AfxMessageBox(szBuffer,1,0);
			::wsprintf(szBuffer, TEXT("%c:\\"), 'A' + i);
			// ͨ���̷��õ������Ϣ
			::GetVolumeInformation(szBuffer, szVol, 32, &dwVol, NULL, NULL, NULL, 0);
			::AfxMessageBox(szVol, 1, 0);

			// TCHAR c = FirstDriveFromMask(lpdbv ->dbcv_unitmask);			//�õ�u���̷�  
			// CString str(c);
			// MessageBox(str, _T("title"), MB_OKCANCEL);
		}

		if(lpdb->dbch_devicetype == DBT_DEVTYP_DEVICEINTERFACE)				// ĳ���豸�Ľӿ�
		{
			PDEV_BROADCAST_DEVICEINTERFACE pDevInf = (PDEV_BROADCAST_DEVICEINTERFACE)lpdb;
			// ͨ��PDEV_BROADCAST_DEVICEINTERFACE��dbcc_name�ǲ���֪���ĸ��豸��װ���˵�ǰϵͳ��
			// dbcc_name�����ǲ���ϵͳ�ڲ�ʹ������ΪID�ģ���Ҫ��ȡ�豸������Ϣ�����豸������2�з���
			// 1 ֱ�Ӷ�ע���, \\HKLM\SYSTEM\CurrentControlSet\Enum\USB\Vid_04e8&Pid_503b\0002F9A9828E0F06
			// 2 ʹ�� SetupDiXxx ϵ��API,��������д���ʹ��SetupDiXxxϵ������ȡ�豸������Ϣ
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

		if(lpdb->dbch_devicetype == DBT_DEVTYP_HANDLE)						// �ļ�ϵͳ���
		{
			PDEV_BROADCAST_HANDLE pDevHnd = (PDEV_BROADCAST_HANDLE)lpdb;
			MessageBox(_T("DBT_DEVTYP_HANDLE"), _T("title"), MB_OKCANCEL);
		}

		if(lpdb->dbch_devicetype == DBT_DEVTYP_OEM)							// OEM��IHV�����Զ����趨���豸����. 
		{
			PDEV_BROADCAST_OEM pDevOem = (PDEV_BROADCAST_OEM)lpdb;
			MessageBox(_T("DBT_DEVTYP_OEM"), _T("title"), MB_OKCANCEL);
		}

		if(lpdb->dbch_devicetype == DBT_DEVTYP_PORT)						// �˿��豸(���л��߲���)
		{
			PDEV_BROADCAST_PORT lpdbv = (PDEV_BROADCAST_PORT)lpdb;   
			int len = _tcslen(lpdbv->dbcp_name);  
			CString name(lpdbv->dbcp_name);									//COM8  
			MessageBox(name, _T("title"), MB_OKCANCEL);
		}

		break;

		// ���������������豸���κ�Ӧ�ó��򶼿��Ծܾ��������ȡ�����������  
	case DBT_DEVICEQUERYREMOVE:
		break;
		// ����豸������ȡ����
	case DBT_DEVICEQUERYREMOVEFAILED:
		break;
		//  �豸��Ҫ����������ܾܾ�
	case DBT_DEVICEREMOVEPENDING:
		break;
		// ���豸�йص��¼�
	case DBT_DEVICETYPESPECIFIC:
		break;
		// ��ǰ���÷����˱仯
	case DBT_CONFIGCHANGED:
		break;
		// �豸�ڵ㷢���˱仯
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
		if (unitmask & 0x1)//������������״̬�Ƿ����˱仯  
			break;  
		unitmask = unitmask >> 1;  
	}  
	return (i + 'A');  
}  


void CHWDetectDlg::UpdateDevice(PDEV_BROADCAST_DEVICEINTERFACE pDevInf, WPARAM wParam)
{
	// ͨ��dbcc_name������豸������Ϣ�����豸����
	// 1 ����ͨ��SetupDiGetClassDevs()������豸��Ϣ�� HDEVINFO�����������ͬ����һ����ȡĿ¼����Ĺ��̡�
	// 2 ����ʹ��SetupDiEnumDeviceInfo()������������豸��Ϣ���ڵ������豸��
	// ���������ͬ�ڱ���Ŀ¼�б�����ÿ���������ģ����ǿ��Ի��SP_DEVINFO_DATA,�����ͬ�����ļ������
	// 3 �������ö�ٹ����У�ʹ��SetupDiGetDeviceInstanceId()����ȡÿ���豸��ʵ��ID��
	// ���������ͬ���Ƕ��ļ������ԣ�һ���豸��ʵ��ID�����������USB\Vid_04e8&Pid_503b\0002F9A9828E0F06��,
	// ��dbcc_name�ǳ���
	// 4 ����豸��ʵ��ID��ͬ��dbcc_name����ͨ��SetupDiGetDeviceRegistryProperty()����ȡ�豸������Ϣ�����豸������Ϣ��

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
	
	// ���ػ�����log off��ʱ��ᷢ�ʹ���Ϣ

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
	 
	//�õ�����������
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

	//end of �õ��豸���
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
	m_OpenDevice.SetWindowText("�ر��豸");*/
}

