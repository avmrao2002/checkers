// CheckersView.cpp : implementation of the CCheckersView class
//

#include "stdafx.h"
#include "Checkers.h"

#include "CheckersDoc.h"
#include "MainFrm.h"
#include "CheckersView.h"
#include "HowToPlay.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCheckersView

IMPLEMENT_DYNCREATE(CCheckersView, CView)

BEGIN_MESSAGE_MAP(CCheckersView, CView)
	//{{AFX_MSG_MAP(CCheckersView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_EDIT_UNDO, OnEditUndo)
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
	ON_COMMAND(ID_HELP_HOWTOPLAY, OnHelpHowtoplay)
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCheckersView construction/destruction

CCheckersView::CCheckersView()
{
	// TODO: add construction code here
	mouseMoveFlag = false;
	m_point.x = -1;
	m_point.y = -1;
	m_nextin = m_nextout = -1;
	m_firstTimeFlag = false;
	//m_bitmap.LoadBitmap(IDB_BITMAP1);
}

CCheckersView::~CCheckersView()
{
}

BOOL CCheckersView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCheckersView drawing

void CCheckersView::OnDraw(CDC* pDC)
{
	CCheckersDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	 
	//CColorDialog dlg;
	//dlg.DoModal();


	// TODO: add draw code for native data here
//	pbrush =  dc.SelectObject(&redbluebrush);	 
	DrawBoard();

}

/////////////////////////////////////////////////////////////////////////////
// CCheckersView diagnostics

#ifdef _DEBUG
void CCheckersView::AssertValid() const
{
	CView::AssertValid();
}

void CCheckersView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCheckersDoc* CCheckersView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCheckersDoc)));
	return (CCheckersDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCheckersView message handlers

void CCheckersView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	//TODO: Add your message handler code here and/or call default
	
	for(int i = 0; i < 7; i++)
	{
		for( int j = 0; j < 7; j++)
		{
			STATE s = cb[i][j].GetState();
			if(s == FREE && m_firstTimeFlag == false)
			{	
				CRgn rgn;
				CRect rect = cb[i][j].GetRect();
				rgn.CreateEllipticRgn(rect.left, rect.top, rect.right, rect.bottom);	
				 
				if(rgn.PtInRegion(point))
				{					 
					m_point.x = i; m_point.y = j;					 
					m_firstTimeFlag = true;		 		 
					OnInitialUpdate();
					//Invalidate();
					CString str;
					str.Format("Started the game at ball position %d, %d", i+1,j+1);
					((CMainFrame*)((CCheckersApp*)AfxGetApp())->m_pMainWnd)->m_wndStatusBar.SetPaneText(0,str);
					return;	 
				}
			}
			
			else if(s == OCCUPIED)
			{
				CRgn rgn;
				CRect rect = cb[i][j].GetRect();
				rgn.CreateEllipticRgn(rect.left, rect.top, rect.right, rect.bottom);	
				if(rgn.PtInRegion(point))
				{					 
					cb[i][j].SetState(MOVING);
					m_point.x = i;
					m_point.y = j;
					mouseMoveFlag = true;
					//Invalidate();
					CString str;
					str.Format("Ball at position %d, %d is moving", i+1,j+1);
					((CMainFrame*)((CCheckersApp*)AfxGetApp())->m_pMainWnd)->m_wndStatusBar.SetPaneText(0,str);
					CView::OnLButtonDown(nFlags, point);

					return;
				}
			}
		}
	}	 

	CView::OnLButtonDown(nFlags, point);
}
 

void CCheckersView::DrawBoard()
{
 
	CClientDC dc(this);	
	/*create compatible bitmap*/
	CDC ldc;
	ldc.CreateCompatibleDC(&dc);
	CBitmap localbmp;
	//m_bitmap.CreateBitmap(833,555,1,16,0x000000);
	//BITMAP bp={0,1000,490,3000,1,24,0x00000000};
	//localbmp.CreateBitmapIndirect(&bp);

	//m_bitmap.CreateCompatibleBitmap(&dc,833,555);
	//BITMAP bmp={0,835,555,1670,1,16,0x000000};
	//m_bitmap = bmp;
	localbmp.LoadBitmap(IDB_BITMAP_BASE);
	ldc.SelectObject(&localbmp);	
	
	//m_bitmap.GetBitmap(&bmp);

	//m_bitmap.CreateBitmap(800,800,1,256,&a);
	//ldc.SelectObject(&m_bitmap);
	CRect crect = cb[3][3].GetRect();
	/*fill dark green color*/
	COLORREF backcr(RGB(20,140,17));
	CBrush backcolorbrush;
	backcolorbrush.CreateSolidBrush(backcr);
	CRect clientrect;
	GetClientRect(clientrect);
	ldc.FillRect(&clientrect,&backcolorbrush);


	/*red color brush*/
	COLORREF redcr(RGB(255,0,0));
	CBrush redbrush;
	redbrush.CreateSolidBrush(redcr);


	/*redblue color brush*/
	COLORREF redbluecr(RGB(255,0,255));
	CBrush redbluebrush;
	redbluebrush.CreateSolidBrush(redbluecr);

	CBrush* pbrush = ldc.SelectObject(&redbluebrush);

	ldc.Ellipse(crect.left - 200, crect.top - 200,
				crect.right + 200, crect.bottom + 200);

	 
	COLORREF bluecr(RGB(0,255,255));//ball color
	CBrush bluebrush;
	bluebrush.CreateSolidBrush(bluecr);

	COLORREF greencr(RGB(0,255,0));
	CBrush greenbrush;
	greenbrush.CreateSolidBrush(greencr);
	 
	ldc.SelectObject(bluebrush);

	ldc.Ellipse(crect.left - 180, crect.top - 180,
		crect.right + 180, crect.bottom + 180);

	pbrush =  ldc.SelectObject(&redbluebrush);
	 

	for(int i = 0; i < 7; i++)
	{
		for( int j = 0; j < 7; j++)
		{
			STATE s = cb[i][j].GetState();
			if(s == BLOCKED)
				continue;
			else if(s == FREE || s == MOVING)
			{
			
				CRect rect = cb[i][j].GetRect();
				ldc.SelectObject(&greenbrush);
				ldc.Ellipse(rect);	
				ldc.SelectObject(&redbluebrush);
			}
			else if( s == OCCUPIED)
			{
				CRect rect = cb[i][j].GetRect();
				ldc.Ellipse(rect);				
			}
		}
	}

	if(mouseMoveFlag == true)
	{
		CRect rect = moveRect;
		ldc.Ellipse(moveRect);		
	}
	dc.BitBlt(0,0,600,700,&ldc,0,0,SRCCOPY);
 
	int count =0;
	if((count = CheckValidMoves()) > 0  && m_firstTimeFlag == true)
	{		 
		if(count == 1)
		{
			if(AfxMessageBox("Congratulations!! You won the game, Want To Play another game", MB_YESNO) == IDYES)
			{
				OnFileNew();				
			}
			return;
		}
		if(AfxMessageBox("Sorry! No Valid Moves, Want To Play another game", MB_YESNO) == IDYES)
		{
			OnFileNew();

		}		 
	}
	 
}

void CCheckersView::OnInitialUpdate() 
{
 	CView::OnInitialUpdate();
	/** set blocked state **********/
	STATE s = BLOCKED;
	cb[0][0].SetState(s);  cb[0][1].SetState(s);
	cb[0][5].SetState(s);  cb[0][6].SetState(s); 
	cb[1][0].SetState(s);  cb[1][1].SetState(s);
	cb[1][5].SetState(s);  cb[1][6].SetState(s); 
	cb[5][0].SetState(s);  cb[5][1].SetState(s);  
	cb[5][5].SetState(s);  cb[5][6].SetState(s); 
	cb[6][0].SetState(s);  cb[6][1].SetState(s);
	cb[6][5].SetState(s);  cb[6][6].SetState(s);  
	int x = 100,y = 71;
	for( int i = 0; i < 7; i++)
	{
		x = 100;
		for(int j=0; j < 7; j++)
		{
			if(cb[i][j].GetState() != BLOCKED)
			{
				CRect rect(x,y, x+ 30, y+30);
				cb[i][j].SetRect(rect);
				STATE s;
				if(m_firstTimeFlag  == false)
				{
					s = FREE;
				}
				else
				{
					s = OCCUPIED;
				}
				cb[i][j].SetState(s);
				 
			}
			else
			{
				CRect rect(x,y, x+ 30, y+30);
				cb[i][j].SetRect(rect);
			}
			x += 50;
		}
		y += 50;
	} 
	if(m_firstTimeFlag  == true)
	{
		s = FREE;
		cb[m_point.x][m_point.y].SetState(s);
	}
	else
	{
	((CMainFrame*)((CCheckersApp*)AfxGetApp())->m_pMainWnd)->m_wndStatusBar.SetPaneText(0,"Click on any empty circle to start the game ...");		
	}
	m_nextin = 0;
 
	
	// Add your specialized code here and/or call the base class
	
}

void CCheckersView::OnMouseMove(UINT nFlags, CPoint p) 
{

	// TODO: Add your message handler code here and/or call default
	//TODO: Add your message handler code here and/or call default	 
	if(mouseMoveFlag == false)
		return;
	int static i = 0;
	i++;
 //	if(i % 3 == 0)
	{
		CRect rect( p.x -15, p.y - 15, p.x + 15, p.y + 15);				 
		moveRect = rect;
		//dc.Ellipse(rect);
		//COLORREF cr(RGB(255,0,0));
		//dc.FillSolidRect(rect,cr);	 
		
		CRect rect1(p.x - 15, p.y - 15, p.x + 15, p.y + 15);
		//InvalidateRect(rect1);
		
		DrawBoard();
		//Invalidate(TRUE);
	}
	CView::OnMouseMove(nFlags, p);	
}

void CCheckersView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default	 
	if(mouseMoveFlag == false)
	{
		//validate();
		return;
	}
	
	mouseMoveFlag = false;
	moveRect =0;
    for(int i = 0; i < 7; i++)
	{
		for( int j = 0; j < 7; j++)
		{
			STATE s = cb[i][j].GetState();
			if(s == BLOCKED) 
				continue;
			else if(s == MOVING )
			{
				CRgn rgn;
				CRect rect = cb[i][j].GetRect();
				rgn.CreateEllipticRgn(rect.left, rect.top, rect.right, rect.bottom);	
				if(rgn.PtInRegion(point))
				{
					cb[i][j].SetState(OCCUPIED);
					InvalidateRect(rect);
					m_point.x = m_point.y = -1;
					CString str;
					str.Format("Ball moved to position %d, %d", i+1,j+1);
					((CMainFrame*)((CCheckersApp*)AfxGetApp())->m_pMainWnd)->m_wndStatusBar.SetPaneText(0,str);
					CView::OnLButtonUp(nFlags, point);
					return;
				}
			}
			else if(s == FREE)
			{
				CRgn rgn;
				CRect rect = cb[i][j].GetRect();
				rgn.CreateEllipticRgn(rect.left, rect.top, rect.right, rect.bottom);	
				if(rgn.PtInRegion(point))
				{
					CPoint rm;
					bool validFlag  = false;
					if( m_point.x + 2  == i && m_point.y == j)
					{ 
						if(cb[i-1][j].GetState()== OCCUPIED)
						{
							rm.x = i-1;
							rm.y=j;
							cb[i-1][j].SetState(FREE);
							validFlag = true;
						}
					}
					else if( m_point.x == i && m_point.y + 2 == j)
					{
						if(cb[i][j -1].GetState()== OCCUPIED)
						{
							rm.x = i;
							rm.y = j-1;
							cb[i][j-1].SetState(FREE);
							validFlag = true;
						}
					}
					else if( m_point.x -2 == i && m_point.y  == j)
					{
						if(cb[i+1][j].GetState()== OCCUPIED)
						{
							rm.x = i+1;
							rm.y = j;
							cb[i+1][j].SetState(FREE);
							validFlag = true;
						}
					}
					else if( m_point.x == i && m_point.y - 2 == j)
					{
						if(cb[i][j+1].GetState()== OCCUPIED)
						{
							rm.x = i;
							rm.y = j+1;
							cb[i][j+1].SetState(FREE);
							validFlag = true;
						}
					}
					if(validFlag == true)
					{
						CPoint pt(i,j);
						m_nextin += 1;						
						m_history[m_nextin].SetHistory(m_point,pt,rm);
						CString str;
						str.Format("Ball moved to position %d, %d", i+1,j+1);
						((CMainFrame*)((CCheckersApp*)AfxGetApp())->m_pMainWnd)->m_wndStatusBar.SetPaneText(0,str);
						
						cb[i][j].SetState(OCCUPIED);
						cb[m_point.x][m_point.y].SetState(FREE);

						InvalidateRect(rect);
						return;
					}
					else
					{
						CString str;
						str.Format("Ball can't move to positioin %d, %d", i+1,j+1);
						((CMainFrame*)((CCheckersApp*)AfxGetApp())->m_pMainWnd)->m_wndStatusBar.SetPaneText(0,str);
					}
				}
				else
				{
					///alidateRect(rect);
				}
					
			}			 
			else
			{
				CRgn rgn;
				CRect rect = cb[i][j].GetRect();
				rgn.CreateEllipticRgn(rect.left, rect.top, rect.right, rect.bottom);	
				if(rgn.PtInRegion(point))
				{
					CString str;
					str.Format("Ball can't move to positioin %d, %d", i+1,j+1);
					((CMainFrame*)((CCheckersApp*)AfxGetApp())->m_pMainWnd)->m_wndStatusBar.SetPaneText(0,str);
				}
			}
		}
	}	
	for(int k = 0; k < 7 ; k++)
	{
		for( int l = 0; l < 7; l++)
		{
			if(cb[k][l].GetState() == MOVING)
			{			 
				CString str;
				str.Format("Invalid move, ball can't move");
				((CMainFrame*)((CCheckersApp*)AfxGetApp())->m_pMainWnd)->m_wndStatusBar.SetPaneText(0,str);
				cb[k][l].SetState(OCCUPIED);
				InvalidateRect(cb[k][l].GetRect());
				CView::OnLButtonUp(nFlags, point);
				return;
			}
		}
	}					 
	CString str;
	str.Format("Invalid move, ball can't move");
	((CMainFrame*)((CCheckersApp*)AfxGetApp())->m_pMainWnd)->m_wndStatusBar.SetPaneText(0,str);
	CView::OnLButtonUp(nFlags, point);
}

void CCheckersView::OnEditUndo() 
{
	// TODO: Add your command handler code here
	if(m_nextin >=0)
	{
		CPoint from, to, rm;
		m_history[m_nextin].GetHistory(from,to,rm);
		m_nextin--;
		if(cb[from.x][from.y].GetState() != BLOCKED)
			cb[from.x][from.y].SetState(OCCUPIED);
		if(cb[to.x][to.y].GetState() != BLOCKED)
			cb[to.x][to.y].SetState(FREE);
		if(cb[rm.x][rm.y].GetState()!= BLOCKED)
			cb[rm.x][rm.y].SetState(OCCUPIED);
		Invalidate();
	}
	else
	{
		OnFileNew();
	}
}
 

void CCheckersView::OnFileNew() 
{
	((CMainFrame*)((CCheckersApp*)AfxGetApp())->m_pMainWnd)->m_wndStatusBar.SetPaneText(0,"Click on any empty circle to start the game ...");
	m_firstTimeFlag = false;
	((CCheckersApp*)AfxGetApp())->OnFileNew();
}

BOOL CCheckersView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
	 
	return CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}
int CCheckersView::CheckValidMoves()
{
	bool validFlag  = false;
	int occCount = 0;
	for(int i=0; i < 7; i++)
	{
		for(int j=0; j < 7; j++)
		{
			if(cb[i][j].GetState() == OCCUPIED)
			{
				if(
					( j+1 < 7 && j+2 < 7 && cb[i][j+1].GetState()== OCCUPIED &&cb[i][j+2].GetState() == FREE ) ||
					(j-1 >= 0 && j-2 >=0 && cb[i][j-1].GetState()== OCCUPIED &&cb[i][j-2].GetState() == FREE) ||
					(i+1 < 7 && i+2 < 7 && cb[i+1][j].GetState()== OCCUPIED &&cb[i+2][j].GetState() == FREE) ||
					(i-1 >= 0 && i-2 >=0 && cb[i-1][j].GetState()== OCCUPIED &&cb[i-2][j].GetState() == FREE) )
				{
					return 0;
				}		
				occCount++;
			}
			else if(cb[i][j].GetState() == MOVING)
			{
				return 0;
			}
		}
	}
	return occCount;
}

void CCheckersView::OnHelpHowtoplay() 
{
	CHowToPlay howtoplay;
	howtoplay.DoModal();
}

BOOL CCheckersView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
//	DrawBoard();
/*	CRect rect; 
	COLORREF cr;
	CRgn rgn1;
	CRect crect = cb[3][3].GetRect();
	rgn1.CreateEllipticRgn(crect.left - 180, crect.top - 180,
		crect.right + 180, crect.bottom + 180);
	CRgn rgn2;	 
	rgn2.CreateEllipticRgn(crect.left - 200, crect.top - 200,
		crect.right + 200, crect.bottom + 200);
	if(rgn1.PtInRegion(m_point))
	{
		COLORREF cr1(RGB(0,0,255));
		cr = cr1;
	}
	else if(rgn2.PtInRegion(m_point))
	{
		COLORREF cr1(RGB(255,0,255));
		cr = cr1;
	}
	else
	{
		COLORREF cr1(RGB(20,140,17));
		cr = cr1;
	}	 
	pDC->SetBkColor(cr);
	CBrush brush(cr);
	pDC->SelectObject(brush);
	GetClientRect(&rect);
	pDC->FillRect(&rect,&brush);
	//turn CView::OnEraseBkgnd(pDC);*/
	return true;
}