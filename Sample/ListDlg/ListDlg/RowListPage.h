#pragma once
#include "TARowList.h"

// RowListPage dialog

class RowListPage : public CPropertyPage
{
	DECLARE_DYNAMIC(RowListPage)

public:
	RowListPage();
	virtual ~RowListPage();

// Dialog Data
	enum { IDD = IDD_PROPPAGE_MEDIUM };

protected:
	CImageList m_imagelist;
	TARowList m_List;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	void		UpdateList();
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
