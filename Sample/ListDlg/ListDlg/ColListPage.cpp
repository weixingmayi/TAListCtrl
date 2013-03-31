// ColListPage.cpp : implementation file
//

#include "stdafx.h"
#include "ListDlg.h"
#include "ColListPage.h"
#include "afxdialogex.h"


// ColListPage dialog

IMPLEMENT_DYNAMIC(ColListPage, CPropertyPage)

ColListPage::ColListPage()
	: CPropertyPage(ColListPage::IDD)
{

}

ColListPage::~ColListPage()
{
}

void ColListPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ColListPage, CPropertyPage)
END_MESSAGE_MAP()


// ColListPage message handlers


BOOL ColListPage::OnInitDialog()
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

void ColListPage::UpdateList()
{
	m_List.InsertColumn(0, _T("No."), NULL, LVCFMT_LEFT, 50);
	m_List.InsertRow(0, _T("Int"), LCDT_INT);
	m_List.InsertRow(1, _T("Float"), LCDT_FLOAT);
	m_List.InsertRow(2, _T("enum"), LCDT_ENUM);
	m_List.InsertRow(3, _T("Check"), LCDT_CHECK);
	m_List.InsertRow(4, _T("Radio"), LCDT_RADIO);
	m_List.InsertRow(5, _T("Color"), LCDT_COLOR);
	m_List.InsertRow(6, _T("image"), LCDT_IMAGE);

	m_List.SetRowImageList(6, &m_imagelist);

	CString intStr, fStr;
	intStr = _T("3");
	fStr = _T("0.023");
	CString str;
	for (int i=1; i<7; ++i)
	{
		str.Format(_T("Item%d"), i);
		m_List.InsertColumn(i, str, NULL, LVCFMT_CENTER, 50);
		m_List.SetItemText(0, i, intStr);
		m_List.SetItemText(1, i, fStr);
		m_List.SetItemText(2, i, fStr);
		m_List.SetItemColor(5, i, RGB(0, 255, 0));
		m_List.SetItemImage(6, i, i%3);
	}

}
