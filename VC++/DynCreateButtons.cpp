
// 对于所有动态创建的5个按钮(ID号在IDC_D_BTN ~ IDC_D_BTN+5-1之间)
// 定义其消息映射函数为OnButtonClick函数，根据其输入ID分辨具体响应那个按钮
// 若是单个按钮，则消息映射为ON_BN_CLICKED(IDC_BUTTON_ID, OnButtonFunc)
ON_COMMAND_RANGE(IDC_D_BTN, IDC_D_BTN + 5 - 1, OnButtonClick)



// #define  IDC_D_BTN 10000

void CMy0515buttonDlg::OnBnClickedButton1()
{
	CButton* pBtn = new CButton[5];
	const TCHAR* pszCaption[5] = { _T("first"), _T("second"), _T("third"), _T("fourth"), _T("fifth") };
	DWORD dwStyle = WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON;
	for(int i = 0; i < 5; i++)
		pBtn[i].Create(pszCaption[i], dwStyle, CRect(20 + 100 * i, 20, 100 + 100 * i, 60), this, IDC_D_BTN + i);
}


void CMy0515buttonDlg::OnButtonClick(UINT uID)
{
	switch(uID)
	{
	case IDC_D_BTN:	MessageBox(_T("first button.")); break;
	case IDC_D_BTN + 1:	MessageBox(_T("second button.")); break;
	case IDC_D_BTN + 2:	MessageBox(_T("thrid button.")); break;
	case IDC_D_BTN + 3:	MessageBox(_T("fourth button.")); break;
	case IDC_D_BTN + 4:	MessageBox(_T("fifth button.")); break;
	default: break;
	}
}
