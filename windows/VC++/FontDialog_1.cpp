
//CEdit	m_Text;
//CFont m_Font;

void CFontDialogDlg::OnFont() 
{
	CFont* TempFont = m_Text.GetFont();	// 获取编辑框当前字体
	LOGFONT LogFont;
	TempFont->GetLogFont(&LogFont);		// 获取字体信息
	CFontDialog dlg(&LogFont);			// 初始化字体信息
	if(dlg.DoModal() == IDOK)
	{
		m_Font.Detach();		// 分离字体
		LOGFONT temp;
		dlg.GetCurrentFont(&temp);
		m_Font.CreateFontIndirect(&temp);	// 直接创建字体
		m_Text.SetFont(&m_Font);			// 设置字体
	}
}