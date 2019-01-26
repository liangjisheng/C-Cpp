// 1258Doc.cpp : implementation of the CMy1258Doc class
//

#include "stdafx.h"
#include "1258.h"

#include "1258Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMy1258Doc

IMPLEMENT_DYNCREATE(CMy1258Doc, CDocument)

BEGIN_MESSAGE_MAP(CMy1258Doc, CDocument)
	//{{AFX_MSG_MAP(CMy1258Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy1258Doc construction/destruction

CMy1258Doc::CMy1258Doc()
{
	// TODO: add one-time construction code here

}

CMy1258Doc::~CMy1258Doc()
{
}

BOOL CMy1258Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMy1258Doc serialization

void CMy1258Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMy1258Doc diagnostics

#ifdef _DEBUG
void CMy1258Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy1258Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMy1258Doc commands
