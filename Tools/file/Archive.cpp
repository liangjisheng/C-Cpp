
void CArchiveDlg::OnButtonWrite() 
{
	CFile file("demo.txt", CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&file,CArchive::store);	// 定义一个存档对象
	int idata = 100;
	char ch = 'a';
	double fdata = 12.12;
	CString str = "lishuyu";
	ar << idata << ch << fdata << str;	// 写入数据
	MessageBox("Write success", "title",MB_OKCANCEL | MB_ICONINFORMATION);
}

void CArchiveDlg::OnButtonRead()
{
	CFile file("demo.txt", CFile::modeRead);
	CArchive ar(&file,CArchive::load);
	int idata;
	char ch;
	double fdata;
	CString str;
	ar >> idata >> ch >> fdata >> str;
	CString strText;
	strText.Format("%d,%c,%lf,%s", idata, ch, fdata, str);
	MessageBox(strText, "title", MB_OKCANCEL | MB_ICONINFORMATION);
}