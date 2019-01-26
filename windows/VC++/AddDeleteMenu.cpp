void CMainFrame::OnAdd() 
{
	CMenu addmenu, *mainmenu;
	if(!addmenu.LoadMenu(IDR_MENU1)) {
		MessageBox("菜单装入失败!","title",MB_OK | MB_ICONERROR);
		return ;
	}
	CString str=""; // 要增加的菜单项的标签
	mainmenu=AfxGetMainWnd()->GetMenu();
	// 将菜单插入到第二项菜单之前，菜单项从0开始算起
	for(unsigned i=0;i<addmenu.GetMenuItemCount();i++) {
		str = ('a' + i);
		mainmenu->InsertMenu(i,MF_POPUP | MF_BYPOSITION | MF_STRING,
			(UINT)addmenu.GetSubMenu(i)->m_hMenu,str);
	}
	mainmenu->Detach();
	addmenu.Detach();
	DrawMenuBar();	 // 重画菜单

	//CString stra='a',strlen;
	//strlen.Format("%d",sizeof(stra));
	//MessageBox("sizeof(stra)="+strlen,"title",MB_OK);
}

void CMainFrame::OnDelete() 
{
	CMenu * mainmenu;
	CMenu addmenu;
	CString str;
	mainmenu=GetMenu();
	int beforecount=mainmenu->GetMenuItemCount();
	addmenu.LoadMenu(IDR_MENU1);
	int addmenucount=addmenu.GetMenuItemCount();

	//for(int i=mainmenu->GetMenuItemCount()-1-beforecount;i>=0;i--) {
	for(int i=0;i<addmenucount;i++) {
		// char ch;
		// mainmenu->GetMenuString(i,str,MF_BYPOSITION); // 获取菜单caption
		// strcpy(&ch,str);
		// if(ch>='a' && ch<='e')
			mainmenu->DeleteMenu(i,MF_BYPOSITION);
	}
	addmenu.Detach();
	mainmenu->Detach();
	DrawMenuBar();
}
