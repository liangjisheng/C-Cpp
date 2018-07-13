// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMy1126Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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
		// 3D文字的实现
		CPaintDC dc(this);
		CString str;
		str="VC++6.0";
		CFont m_fontLogo;
		m_fontLogo.CreateFont(44,0,0,0,55,false,false,0,0,0,0,0,0,"Arial");
		dc.SetBkMode(TRANSPARENT);
		CRect rect;
		GetClientRect(&rect);
		CFont * pOldFont=dc.SelectObject(&m_fontLogo);
		COLORREF OldColor=dc.SetTextColor(::GetSysColor(COLOR_3DHILIGHT));
		dc.DrawText(str,rect+CPoint(3,3),
			DT_SINGLELINE | DT_LEFT | DT_VCENTER | DT_CENTER);
		dc.SetTextColor(::GetSysColor(COLOR_3DSHADOW));
		dc.DrawText(str,rect,
			DT_SINGLELINE | DT_LEFT | DT_VCENTER | DT_CENTER);

		dc.SetTextColor(OldColor);
		dc.SelectObject(pOldFont);
		CDialog::OnPaint();
	}
}