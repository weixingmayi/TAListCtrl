// ListDlgSheet.cpp : implementation file
//

#include "stdafx.h"
#include "ListDlg.h"
#include "ListDlgSheet.h"


// ListDlgSheet

IMPLEMENT_DYNAMIC(ListDlgSheet, CPropertySheet)

ListDlgSheet::ListDlgSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	AddPage(&m_rowPage);
	AddPage(&m_colPage);
	AddPage(&m_ceilPage);
}

ListDlgSheet::ListDlgSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	AddPage(&m_rowPage);
	AddPage(&m_colPage);
	AddPage(&m_ceilPage);
}

ListDlgSheet::~ListDlgSheet()
{
}


BEGIN_MESSAGE_MAP(ListDlgSheet, CPropertySheet)
	ON_WM_SYSCOMMAND()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// ListDlgSheet message handlers


BOOL ListDlgSheet::OnInitDialog()
{
	BOOL bResult = CPropertySheet::OnInitDialog();

	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	return bResult;
}


void ListDlgSheet::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		
	}
	else
	{
		CPropertySheet::OnSysCommand(nID, lParam);
	}
}


HCURSOR ListDlgSheet::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
