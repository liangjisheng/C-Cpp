void CtestOnSizeDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// m_OldRect在构造函数里初始化为0，所以当第一个调OnSize()的
	// 时候，缩放比例为1.0
	int nWidth = m_OldRect.right - m_OldRect.left;
	int nHeight = m_OldRect.bottom - m_OldRect.top;

	CRect wndRect;
	CWnd* pWnd = NULL;
	double xProp = nWidth == 0 ? 1.0 : cx / (double)(nWidth);
	double yProp = nHeight == 0 ? 1.0 : cy / (double)(nHeight);

	// .h file defined  CDWordArray m_ctrlInfo;
	// .cpp file Init
	// GetClientRect(&m_OldRect);
	// m_ctrlInfo.Add(ID);
	// m_ctrlInfo.Add(IDC_BUTTON1);

	for(int i = 0; i < m_ctrlInfo.GetSize(); i++)
	{
		pWnd = this->GetDlgItem(m_ctrlInfo[i]);
		if(NULL == pWnd)
			continue;

		pWnd->GetWindowRect(&wndRect);						// 获取控件的屏幕坐标
		ScreenToClient(&wndRect);
		wndRect.left = (LONG)(wndRect.left * xProp);		// 计算转换后的客户区坐标
		wndRect.right = (LONG)(wndRect.right * xProp);
		wndRect.top = (LONG)(wndRect.top * yProp);
		wndRect.bottom = (LONG)(wndRect.bottom * yProp);
		pWnd->MoveWindow(wndRect);							// MoveWindow()是针对客户区坐标的
	}

	this->GetClientRect(&m_OldRect);
}


// 响应用户的拖动，此时窗口尚未变更大小
void CtestOnSizeDlg::OnSizing(UINT fwSide, LPRECT pRect)
{
	// fwSide 确定用户调整的方向
	// 取值1-8： Left:1, Right:2, Top:3, Bottom:6, Left+Right:4
	// Right+Top:5, Left+Bottom:7, Right+Bottom:8

	// pRect传入传出参数确定调整后的大小
	// 响应调整：根据用户调整的方向，当用户从左边调宽度时，我们也从左边调
	// 同理高度也是如此
	// 大小限制：当移动的大小超出我们设置的限制时，调整传入的pRect

	/*if(fwSide == 2 || fwSide == 5 || fwSide == 8)
	pRect->right = pRect->left + MinWidth;
	else
	pRect->left = pRect->right - MinWidth;

	if(fwSide == 6 || fwSide == 7 || fwSide == 8)
	pRect->bottom = pRect->top + MinHeight;
	else
	pRect->top = pRect->bottom - MinHeight;*/

	if((pRect->right - pRect->left) < 500)
		pRect->right = pRect->left + 500;
	if((pRect->bottom - pRect->top) < 300)
		pRect->bottom = pRect->top + 300;

	CDialogEx::OnSizing(fwSide, pRect);	
}


void CtestOnSizeDlg::OnGetMinMaxInfo(MINMAXINFO* lpMMI)
{
	// 下面四行代码限制对话框的最小尺寸,最小宽度为500px，最小高度为300px
	if(lpMMI->ptMinTrackSize.x <= 500)
		lpMMI->ptMinTrackSize.x = 500;
	if(lpMMI->ptMinTrackSize.y <= 300)
		lpMMI->ptMinTrackSize.y = 300;
	
	CDialogEx::OnGetMinMaxInfo(lpMMI);
}

