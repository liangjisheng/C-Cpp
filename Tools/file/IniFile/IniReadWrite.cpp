
void CMy04261View::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	m_nXPos = GetPrivateProfileInt(_T("SECTION 1"),		// 节名
									_T("XPos"),			// 项名
									0,					// 没找到次项时的缺省返回值
									_T("D:\\vs2010_projects\\0426-1\\Debug\\test.ini"));	// 配置文件的路径

	m_nYPos = GetPrivateProfileInt(_T("SECTION 1"),
									_T("YPos"),
									0,
									_T("D:\\vs2010_projects\\0426-1\\Debug\\test.ini"));

	TCHAR szbuf[256] = {0};
	// 返回获取到的字符串的实际长度
	int len = GetPrivateProfileString(_T("SECTION 2"),	// 节名
								_T("Text"),				// 项名
								_T("No Text"),			// 没有找到此项时的返回值
								szbuf,					// 缓冲区
								256,					// 缓冲区长度
								_T("D:\\vs2010_projects\\0426-1\\Debug\\test.ini"));		// 配置文件路径
	
	m_strText = szbuf;

	Invalidate();
}


void CMy04261View::OnIniWritexy()
{
	// 写配置文件基本相同，需要把数值类型的变量格式化成字符串在写
	CString str = _T("");

	str.Format(_T("%d"), m_nXPos / 2);
	WritePrivateProfileString(_T("SECTION 1"), _T("XPos"), str, 
		_T("D:\\vs2010_projects\\0426-1\\Debug\\test.ini"));

	str.Format(_T("%d"), m_nYPos / 2);
	WritePrivateProfileString(_T("SECTION 1"), _T("YPos"), str, 
		_T("D:\\vs2010_projects\\0426-1\\Debug\\test.ini"));

	str = _T("WriteText");
	WritePrivateProfileString(_T("SECTION 2"), _T("Text"), str, 
		_T("D:\\vs2010_projects\\0426-1\\Debug\\test.ini"));
}


void CMy04261View::OnIniSection()
{
	TCHAR lpReturnString[256] = {0};
	// 读取指定节名下的所有项，每一项用空格隔开
	int len = GetPrivateProfileSection(_T("SECTION 1"),
									lpReturnString,
									256,
									_T("D:\\vs2010_projects\\0426-1\\Debug\\test.ini"));

	m_strText = _T("");
	for(int i = 0; i < len; i++)
	{
		if(lpReturnString[i] != _T('\0'))
			m_strText += lpReturnString[i];
		else
			m_strText += _T("\r\n");
	}
	//m_strText = lpReturnString;
	// Invalidate();

	// asterisk 星号，加星号
	MessageBox(m_strText, _T("tip"), MB_OKCANCEL | MB_ICONASTERISK);

	memset(lpReturnString, _T('\0'), 256 * sizeof(TCHAR));

	// 读取配置文件中的所有节名
	len = GetPrivateProfileSectionNames(lpReturnString, 256, 
			_T("D:\\vs2010_projects\\0426-1\\Debug\\test.ini"));

	m_strText = _T("");
	for(int i = 0; i < len; i++)
	{
		if(lpReturnString[i] != _T('\0'))
			m_strText += lpReturnString[i];
		else
			m_strText += _T("\r\n");
	}

	MessageBox(m_strText, _T("tip"), MB_OKCANCEL | MB_ICONEXCLAMATION);
}

void CMy04261View::OnDraw(CDC* pDC)
{
	CMy04261Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDC->TextOut(m_nXPos, m_nYPos, m_strText);
}


typedef struct _mytest
{
	int i;
	TCHAR a[30];
	double d;
}mytest;

void CMy04261View::OnIniWritestruct()
{
	mytest mystruct = {0};
	mytest myout;
	mystruct.i = 5;
	_tcscpy(mystruct.a, _T("liangjisheng"));
	mystruct.d = 5.06;

	bool bWrite = WritePrivateProfileStruct(_T("zheng"),
										_T("test"),
										(mytest *)&mystruct,
										sizeof(mystruct),
										_T("D:\\vs2010_projects\\0426-1\\Debug\\testStruct.ini"));
	if(bWrite)
	{
		bool bRead = GetPrivateProfileStruct(_T("zheng"),
						_T("test"),
						(mytest *)&myout,
						sizeof(myout),
						_T("D:\\vs2010_projects\\0426-1\\Debug\\testStruct.ini"));
		if(bRead)
		{
			CString str, strRet;
			str.Format(_T("Integer: %d\r\n"), myout.i);
			strRet = str;
			str.Format(_T("Double: %lf\r\n"), myout.d);
			strRet += str;
			str.Format(_T("Chars: %s"), myout.a);
			strRet += str;

			MessageBox(strRet, _T("tip"), MB_OKCANCEL | MB_ICONHAND);
		}
	}
}