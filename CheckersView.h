// CheckersView.h : interface of the CCheckersView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHECKERSVIEW_H__D3CB5709_E01B_4A34_A22C_1F5AD74E2079__INCLUDED_)
#define AFX_CHECKERSVIEW_H__D3CB5709_E01B_4A34_A22C_1F5AD74E2079__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
enum STATE {FREE=0, OCCUPIED, BLOCKED,MOVING};
class CCheckersBoard
{
	CRect rect;
	STATE state; // 0 - free, 1 - occupied, 2- blocked

public:
	CCheckersBoard()
	{
	}
	void Init(CRect &inrect,STATE& instate)
	{
		rect = inrect;
		state = state;
	}
	CRect GetRect()
	{
		return rect;
	}
	void SetRect(CRect &inrect)
	{
		rect = inrect;
	}
	enum STATE GetState()
	{
		return state;
	}
	void SetState(STATE instate)
	{
		state = instate;
	}
};
#define MAXHISTORY 100
class CHistory
{ 
	CPoint m_from;
	CPoint m_to;
	CPoint m_removed;
public:
	CHistory()
	{
		m_from.x = m_from.y = m_to.x = m_to.y = m_removed.x = m_removed.y = 0;
	}
	void SetHistory(CPoint from, CPoint to, CPoint removed)
	{
		m_from = from;
		m_to = to;
		m_removed = removed;
	}
	void GetHistory(CPoint &from, CPoint &to, CPoint& removed)
	{
		from = m_from;
		to = m_to;
		removed = m_removed;
	}
};

class CCheckersView : public CView
{
protected: // create from serialization only
	CCheckersView();
	DECLARE_DYNCREATE(CCheckersView)

// Attributes
public:
	CCheckersDoc* GetDocument();
	CCheckersBoard cb[7][7];
	int m_nextin, m_nextout;
	CHistory m_history[MAXHISTORY];	
	bool mouseMoveFlag;
	CRect moveRect;
	CPoint m_point;
	bool m_firstTimeFlag;
	CBitmap m_bitmap;


// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCheckersView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCheckersView();
	void DrawBoard();
	int CheckValidMoves();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCheckersView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnEditUndo();
	afx_msg void OnFileNew();
	afx_msg void OnHelpHowtoplay();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CheckersView.cpp
inline CCheckersDoc* CCheckersView::GetDocument()
   { return (CCheckersDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHECKERSVIEW_H__D3CB5709_E01B_4A34_A22C_1F5AD74E2079__INCLUDED_)
