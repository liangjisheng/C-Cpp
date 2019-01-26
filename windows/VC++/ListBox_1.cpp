CListBox m_ListBox;

m_ListBox.AddString(_T("test0"));
m_ListBox.AddString(_T("test1"));
m_ListBox.AddString(_T("test2"));
m_ListBox.AddString(_T("test3"));
m_ListBox.AddString(_T("test4"));
m_ListBox.InsertString(2, _T("insert"));

// LBS_EXTENDEDSEL 支持多重选择 在点击列表框项时按住Shift键或Ctrl键即可选择多个项。
// LBS_MULTICOLUMN 指定一个水平滚动的多列列表框
// LBS_MULTIPLESEL 支持多重选择 列表项的选择状态随着用户对该项单机或双击鼠标而翻转
// LBS_NOINTEGRALHEIGHT 列表框的尺寸由应用程序而不是Windows指定
// LBS_NOREDRAW 当选择发生变化时防止列表框被更新，可发送消息改变改变该风格
// LBS_NOTIFY 当用户单击或双击鼠标时通知父窗口
// LBS_OWNERDRAWFIXED 指定自绘式列表框，即由父窗口负责绘制列表框的内容，并且列表项具有相同的高度
// LBS_SORT 使插入列表框中的项按升序排列
// LBS_STANDARD 相当于指定了WS_BORDER|WS_VSCROLL|LBS_SORT
// LBS_USETABSTOPS 使列表框在显示列表项时识别并扩展制表符('\t')，默认的制表宽度是32个对话框单位
// LBS_WANTKEYBOARDINPUT 允许列表框的父窗口接收WM_VKEYTOITEM和WM_CHARTOITEM消息，以响应键盘输入
// LBS_DISABLENOSCROLL 使列表框在不需要滚动时显示一个禁止的垂直滚动条

// dwStyle可以是以上所列风格的组合。与其他控件一样，除了这些风格一般还要为列表框控件
// 设置WS_CHILD、WS_VISIBLE、WS_TABSTOP、WS_BORDER、WS_VSCROLL等风格。一般创建单选列
// 表框时，风格要设置为：WS_CHILD|WS_VISIBLE|WS_TABSTOP|LBS_STANDARD，如果不希望列表
// 框排序显示则应去掉LBS_STANDARD。创建多选列表框时，只需要在单选列表框风风格后添加
// LBS_MULTIPLESEL或LBS_EXTENDEDSEL风格。


// 选项改变
void CListBox_1Dlg::OnLbnSelchangeList1()
{
	int nIndex = m_ListBox.GetCurSel();
	CString str = _T("");
	m_ListBox.GetText(nIndex, str);
	SetDlgItemText(IDC_EDIT1, str);
}
