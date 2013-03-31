
// ListDlgDlg.h : header file
//

#pragma once
#include "RowListPage.h"
#include "ColListPage.h"
#include "CeilListPage.h"

// CListDlgDlg dialog
class CListDlgDlg : public CPropertySheet
{
// Construction
public:
	CListDlgDlg(CWnd* pParent = NULL);	// standard constructor

// Implementation
protected:
	HICON m_hIcon;
	RowListPage m_rowPage;
	ColListPage	m_colPage;
	CeilListPage	m_ceilPage;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
