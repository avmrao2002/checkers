// CheckersDoc.h : interface of the CCheckersDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHECKERSDOC_H__A2267CC9_D8D8_46A9_8645_39BB9D0E1EC2__INCLUDED_)
#define AFX_CHECKERSDOC_H__A2267CC9_D8D8_46A9_8645_39BB9D0E1EC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCheckersDoc : public CDocument
{
protected: // create from serialization only
	CCheckersDoc();
	DECLARE_DYNCREATE(CCheckersDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCheckersDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCheckersDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCheckersDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHECKERSDOC_H__A2267CC9_D8D8_46A9_8645_39BB9D0E1EC2__INCLUDED_)
