#if !defined(AFX_HOWTOPLAY_H__A32D4D52_72E0_46B7_85F2_37A2D062D353__INCLUDED_)
#define AFX_HOWTOPLAY_H__A32D4D52_72E0_46B7_85F2_37A2D062D353__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HowToPlay.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHowToPlay dialog

class CHowToPlay : public CDialog
{
// Construction
public:
	CHowToPlay(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CHowToPlay)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHowToPlay)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CHowToPlay)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HOWTOPLAY_H__A32D4D52_72E0_46B7_85F2_37A2D062D353__INCLUDED_)
