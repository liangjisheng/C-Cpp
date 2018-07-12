void CCColorDialogDlg::OnColor() 
{
	// COLORREF m_Color
	CColorDialog dlg(m_Color);
	if(dlg.DoModal() == IDOK)		// 判断是否按下确定按钮
	{
		m_Color = dlg.GetColor();	// 获取用户选择的颜色
		Invalidate();				// 重绘窗口
	}
}

HBRUSH CCColorDialogDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
//	if(nCtlColor == CTLCOLOR_STATIC)	// 判断是否为静态文本
//	{
//		HBRUSH brush;
//		brush = CreateSolidBrush(m_Color);
//		return brush;
//	}
	// 指定某个控件的颜色
	if(pWnd->GetDlgCtrlID() == IDC_STATIC1)
	{
		pDC->SetTextColor(RGB(255,0,0));	// 文本颜色
		pDC->SetBkMode(TRANSPARENT);		// 字体背景为透明
		return CreateSolidBrush(m_Color);
	}
	// TODO: Return a different brush if the default is not desired
	return hbr;
}