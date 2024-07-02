; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainFrame
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Checkers.h"
LastPage=0

ClassCount=6
Class1=CCheckersApp
Class2=CCheckersDoc
Class3=CCheckersView
Class4=CMainFrame

ResourceCount=3
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Resource2=IDD_ABOUTBOX
Class6=CHowToPlay
Resource3=IDD_DIALOG1

[CLS:CCheckersApp]
Type=0
HeaderFile=Checkers.h
ImplementationFile=Checkers.cpp
Filter=N
LastObject=CCheckersApp
BaseClass=CWinApp
VirtualFilter=AC

[CLS:CCheckersDoc]
Type=0
HeaderFile=CheckersDoc.h
ImplementationFile=CheckersDoc.cpp
Filter=N

[CLS:CCheckersView]
Type=0
HeaderFile=CheckersView.h
ImplementationFile=CheckersView.cpp
Filter=C
LastObject=CCheckersView
BaseClass=CView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=Checkers.cpp
ImplementationFile=Checkers.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=6
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_APP_EXIT
Command3=ID_EDIT_UNDO
Command4=ID_VIEW_STATUS_BAR
Command5=ID_APP_ABOUT
Command6=ID_HELP_HOWTOPLAY
CommandCount=6

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[DLG:IDD_DIALOG1]
Type=1
Class=CHowToPlay
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352

[CLS:CHowToPlay]
Type=0
HeaderFile=HowToPlay.h
ImplementationFile=HowToPlay.cpp
BaseClass=CDialog
Filter=D
LastObject=CHowToPlay

