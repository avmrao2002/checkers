// HowToPlay.cpp : implementation file
//

#include "stdafx.h"
#include "Checkers.h"
#include "HowToPlay.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHowToPlay dialog


CHowToPlay::CHowToPlay(CWnd* pParent /*=NULL*/)
	: CDialog(CHowToPlay::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHowToPlay)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CHowToPlay::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHowToPlay)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHowToPlay, CDialog)
	//{{AFX_MSG_MAP(CHowToPlay)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHowToPlay message handlers
