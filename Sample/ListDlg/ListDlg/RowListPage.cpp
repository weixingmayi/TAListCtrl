// RowListPage.cpp : implementation file
//

#include "stdafx.h"
#include "ListDlg.h"
#include "RowListPage.h"
#include "afxdialogex.h"


// RowListPage dialog

IMPLEMENT_DYNAMIC(RowListPage, CPropertyPage)

RowListPage::RowListPage()
	: CPropertyPage(RowListPage::IDD)
{

}

RowListPage::~RowListPage()
{
}

void RowListPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(RowListPage, CPropertyPage)
END_MESSAGE_MAP()


// RowListPage message handlers


BOOL RowListPage::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	m_imagelist.Create(TAListCtrl::COMSTOM_LISTCTRL_IMAGE_SIZE,
		TAListCtrl::COMSTOM_LISTCTRL_IMAGE_SIZE, 
		ILC_COLOR24 | ILC_MASK, 3, 1);
	CBitmap bmp;
	bmp.LoadBitmapW(IDB_BITMAP1);
	m_imagelist.Add(&bmp, RGB(255, 255, 255));

	m_List.SubclassDlgItem(IDC_LIST1, this);
	m_List.OnAttach(0);
	UpdateList();

	return TRUE;
}

void RowListPage::UpdateList()
{
	m_List.InsertColumn(0, _T("No."), LCDT_NO, LVCFMT_LEFT, 30);
	m_List.InsertColumn(1, _T("Float"), LCDT_FLOAT, LVCFMT_CENTER, 50);
	m_List.InsertColumn(2, _T("Int"), LCDT_INT, LVCFMT_CENTER, 50);
	m_List.InsertColumn(3, _T("enum"), LCDT_ENUM, LVCFMT_CENTER, 50);
	m_List.InsertColumn(4, _T("Check"), LCDT_CHECK, LVCFMT_CENTER, 50);
	m_List.InsertColumn(5, _T("Radio"), LCDT_RADIO, LVCFMT_CENTER, 50);
	m_List.InsertColumn(6, _T("Color"), LCDT_COLOR, LVCFMT_CENTER, 50);
	m_List.InsertColumn(7, _T("image"), LCDT_IMAGE, LVCFMT_CENTER, 50);

	m_List.SetColumnImageList(7, &m_imagelist);

	CString intStr, fStr;
	intStr = _T("3");
	fStr = _T("0.023");
	for (int i=0; i<7; ++i)
	{
		m_List.InsertItem(i, NULL, NULL);
		m_List.SetItemText(i, 1, fStr);
		m_List.SetItemText(i, 2, intStr);
		m_List.SetItemText(i, 3, fStr);
		m_List.SetItemColor(i, 6, RGB(0, 255, 0));
		m_List.SetItemImage(i, 7, i%3);
	}
	
}
