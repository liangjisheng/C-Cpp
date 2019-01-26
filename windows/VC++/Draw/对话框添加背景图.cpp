BOOL CMy12081Dlg::OnEraseBkgnd(CDC* pDC)
{
	// 为对话框添加背景图片
	CDialogEx::OnEraseBkgnd(pDC);
	CBitmap m_bitmap;
	m_bitmap.LoadBitmap(IDB_BITMAP1);

	if (!m_bitmap.m_hObject)
		return FALSE;

	CRect rect;
	GetClientRect(&rect);
	CDC dc;
	dc.CreateCompatibleDC(pDC);
	CBitmap *pOldBitmap = dc.SelectObject(&m_bitmap);
	int bmw, bmh;
	BITMAP bmap;
	m_bitmap.GetBitmap(&bmap);
	bmw = bmap.bmWidth;
	bmh = bmap.bmHeight;
	int xo = 0, yo = 0;
	
	// 函数从源矩形中复制一个位图到目标矩形，必要时按目前目标设备设置的模式进行图像的拉伸或压缩
	// BitBlt不会对图形进行拉伸或压缩以适应目标设备的大小
	pDC->BitBlt(xo, yo, rect.Width(), rect.Height(), &dc, 0, 0, SRCCOPY);

	// StretchBlt会对图形进行拉伸或压缩以适应目标设备的大小
	// pDC->StretchBlt(xo, yo, rect.Width(), rect.Height(), &dc, 0, 0, bmw, bmh, SRCCOPY);

	dc.SelectObject(pOldBitmap);

	return TRUE;
	// return CDialogEx::OnEraseBkgnd(pDC);
}