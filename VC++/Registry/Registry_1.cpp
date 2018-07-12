void COperateRegDlg::OnButtonWrite() 
{
	HKEY hroot;				// 定义注册表句柄
	DWORD action;
	CString keyname;
	m_KeyName.GetWindowText(keyname);
	keyname += _T("\\");
	// 在注册表中创建键名
	RegCreateKeyEx(HKEY_CURRENT_USER,keyname,0,NULL,0,
		KEY_WRITE,NULL,&hroot,&action);
	CString itemname;
	m_ItemName.GetWindowText(itemname);		// 获取项名
	CString itemvalue;
	m_ItemValue.GetWindowText(itemvalue);	// 获取项值
	DWORD size = itemvalue.GetLength();

	if(ERROR_SUCCESS == RegSetValueEx(hroot,itemname,0,
		REG_SZ,(unsigned char*)itemvalue.GetBuffer(0),size))	// 设置项值
		MessageBox("Successful!");
	itemvalue.ReleaseBuffer();
	RegCloseKey(hroot);
}

void COperateRegDlg::OnButtonRead() 
{
	HKEY hroot;
	CString keyname;
	m_KeyName.GetWindowText(keyname);
	// 打开注册表键值
	RegOpenKeyEx(HKEY_CURRENT_USER,keyname,0,KEY_READ,&hroot);
	CString itemname;
	m_ItemName.GetWindowText(itemname);
	DWORD type = REG_SZ;		// 设置项的数据类型
	CString strData = "";
	unsigned char RegData[MAX_PATH] = {0};
	DWORD size = MAX_PATH;
	// 从注册表中获取项信息
	RegQueryValueEx(hroot,itemname,0,&type,RegData,&size);
	strData = RegData;
	RegCloseKey(hroot);
	MessageBox(strData,"title");
}