void CMy1055View::OnDraw(CDC* pDC)
{
	CMy1055Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	SetTimer(1,1000,NULL);
	srand(time(0));
	start=CTime::GetCurrentTime();
	end=CTime::GetCurrentTime();
	int count=rand()%100;
	//while(end-start<1 || flag) {
	//if(flag) {
	for(int i=0;i<count;i++) 
	{
		CBrush bs;
		bs.CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		pDC->SelectObject(&bs);
		CPen mypen;
		mypen.CreatePen(PS_SOLID,1,RGB(rand()%255,rand()%255,rand()%255));
		pDC->SelectObject(&mypen);
		CRect r,rect;
		GetClientRect(&r);
		int left,top,right,bottom;
		int radius=rand()%100;
		left=rand()%r.right;
		top=rand()%r.bottom;
		right=left+2*radius;
		bottom=top+2*radius;
		rect.SetRect(left,top,right,bottom);
		pDC->Ellipse(rect);
		//end=CTime::GetCurrentTime();
		//}
		//}
	}
}