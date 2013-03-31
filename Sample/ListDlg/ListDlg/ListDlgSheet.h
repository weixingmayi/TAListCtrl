#pragma once
#include "RowListPage.h"
#include "ColListPage.h"
#include "CeilListPage.h"


// ListDlgSheet

class ListDlgSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(ListDlgSheet)

public:
	ListDlgSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	ListDlgSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	virtual ~ListDlgSheet();

protected:
	HICON			m_hIcon;
	RowListPage		m_rowPage;
	ColListPage		m_colPage;
	CeilListPage	m_ceilPage;

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg HCURSOR OnQueryDragIcon();
};


