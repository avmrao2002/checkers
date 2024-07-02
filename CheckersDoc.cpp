// CheckersDoc.cpp : implementation of the CCheckersDoc class
//

#include "stdafx.h"
#include "Checkers.h"

#include "CheckersDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCheckersDoc

IMPLEMENT_DYNCREATE(CCheckersDoc, CDocument)

BEGIN_MESSAGE_MAP(CCheckersDoc, CDocument)
	//{{AFX_MSG_MAP(CCheckersDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCheckersDoc construction/destruction

CCheckersDoc::CCheckersDoc()
{
	// TODO: add one-time construction code here

}

CCheckersDoc::~CCheckersDoc()
{
}

BOOL CCheckersDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCheckersDoc serialization

void CCheckersDoc::Serialize(CArchive& ar)
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
// CCheckersDoc diagnostics

#ifdef _DEBUG
void CCheckersDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCheckersDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCheckersDoc commands
