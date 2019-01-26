CMy819View::CMy819View()
{
	m_bmp.LoadBitmap(IDB_BITMAP2);
	m_overbmp.LoadBitmap(IDB_BITMAP3);
}

void CMy819View::OnDraw(CDC* pDC)
{
	CMy819Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CRect r;
	GetClientRect(&r);
	CRect rcCenter(r.Width()/2-23,r.Height()/2-23,
		r.Width()/2+23,r.Height()/2+23);
	m_bmp_rect=rcCenter;// 显示第一个位图
	showbmp(m_bmp_rect,m_bmp);
}

void CMy819View::showbmp(CRect &rc, CBitmap &bmp)
{
	CClientDC dc(this);
	CDC dcmem;
	dcmem.CreateCompatibleDC(&dc);// 创建兼容的内存
	dcmem.SelectObject(bmp);
	dc.BitBlt(rc.left,rc.top,rc.Width(),rc.Height(),
		&dcmem,0,0,SRCCOPY);// 传送位图到rc表示的矩形区域
}

void CMy819View::OnMouseMove(UINT nFlags, CPoint point) 
{
	if(m_bmp_rect.PtInRect(point)) showbmp(m_bmp_rect,m_overbmp);
	else showbmp(m_bmp_rect,m_bmp);
	CView::OnMouseMove(nFlags, point);
}
