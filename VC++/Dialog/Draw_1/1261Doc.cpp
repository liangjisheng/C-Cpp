// 1261Doc.cpp : implementation of the CMy1261Doc class
//

#include "stdafx.h"
#include "1261.h"

#include "1261Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMy1261Doc

IMPLEMENT_DYNCREATE(CMy1261Doc, CDocument)

BEGIN_MESSAGE_MAP(CMy1261Doc, CDocument)
	//{{AFX_MSG_MAP(CMy1261Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy1261Doc construction/destruction

CMy1261Doc::CMy1261Doc()
{
	// TODO: add one-time construction code here

}

CMy1261Doc::~CMy1261Doc()
{
}

BOOL CMy1261Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMy1261Doc serialization

void CMy1261Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		CLine* t;
		POSITION p = list.GetHeadPosition();
		ar<<list.GetCount();	// 把链表节点个数存入文件
		while(p)
		{
			t = (CLine*)list.GetNext(p);
			ar<<t->start<<t->end<<t->color<<t->style<<t->thick;
		}
	}
	else
	{
		CLine* t;
		int n,i;
		ar>>n;
		for(i=0;i<n;i++)
		{
			t = new CLine;
			ar>>t->start>>t->end>>t->color>>t->style>>t->thick;
			list.AddTail((CObject*)t);		// 放入链表
		}

	}
}

/////////////////////////////////////////////////////////////////////////////
// CMy1261Doc diagnostics

#ifdef _DEBUG
void CMy1261Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy1261Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMy1261Doc commands
