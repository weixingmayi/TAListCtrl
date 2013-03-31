#pragma once


// CeilListPage dialog

class CeilListPage : public CPropertyPage
{
	DECLARE_DYNAMIC(CeilListPage)

public:
	CeilListPage();
	virtual ~CeilListPage();

// Dialog Data
	enum { IDD = IDD_PROPPAGE_MEDIUM2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
