BOOL CMy1245Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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
	
	UINT array[4];
	for(int i=0;i<4;i++)
		array[i]=1001+i;
	m_StatusBar.Create(this);
	// 添加窗格
	m_StatusBar.SetIndicators(array,sizeof(array)/sizeof(UINT));
	for(int n=0;n<4;n++)
		m_StatusBar.SetPaneInfo(n,array[n],0,100);	// 设置窗格宽度

	CTime time = CTime::GetCurrentTime();
	m_StatusBar.SetPaneText(0,"当前用户:");
	m_StatusBar.SetPaneText(1,"TM");
	m_StatusBar.SetPaneText(2,"当前日期:");
	m_StatusBar.SetPaneText(3,time.Format("%Y-%m-%d"));
	// 显示状态栏
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,0);

	RECT m_rect;
	m_StatusBar.GetItemRect(3,&m_rect);	// 获取第4个窗格的区域
	m_Progress.SetParent(&m_StatusBar);	// 设置进度条的父窗口为状态栏
	m_Progress.MoveWindow(&m_rect);		// 设置进度条显示的位置
	m_Progress.ShowWindow(SW_SHOW);		// 显示进度条控件
	m_Progress.SetRange(0,30);			// 设置进度条范围
	m_Progress.SetPos(20);				// 设置进度条当前位置
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}