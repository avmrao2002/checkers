// Checkers.h : main header file for the CHECKERS application
//

#if !defined(AFX_CHECKERS_H__5C1AFC00_9BA5_4050_84B4_10FF1083EDF0__INCLUDED_)
#define AFX_CHECKERS_H__5C1AFC00_9BA5_4050_84B4_10FF1083EDF0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCheckersApp:
// See Checkers.cpp for the implementation of this class
//

class CCheckersApp : public CWinApp
{
public:
	CCheckersApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCheckersApp)
	public:
	virtual BOOL InitInstance();
	virtual BOOL InitApplication();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CCheckersApp)
	afx_msg void OnAppAbout();
	afx_msg void OnFileNew();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHECKERS_H__5C1AFC00_9BA5_4050_84B4_10FF1083EDF0__INCLUDED_)
