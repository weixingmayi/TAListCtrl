#pragma once
#include "TAColList.h"

// ColListPage dialog

class ColListPage : public CPropertyPage
{
	DECLARE_DYNAMIC(ColListPage)

public:
	ColListPage();
	virtual ~ColListPage();

// Dialog Data
	enum { IDD = IDD_PROPPAGE_MEDIUM1 };

protected:
	CImageList m_imagelist;
	TAColList m_List;

	void	UpdateList();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
