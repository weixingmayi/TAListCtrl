#include "StdAfx.h"
#include "TAColList.h"


// TAColList

IMPLEMENT_DYNAMIC(TAColList, TAListCtrl)

TAColList::TAColList()
{
	m_FirstColItemInfo.bEnable = FALSE;
	m_FirstItemInfo.bEnable = FALSE;
}

TAColList::~TAColList()
{
	Cleanup();
}


BEGIN_MESSAGE_MAP(TAColList, CListCtrl)
END_MESSAGE_MAP()

ListCtrlItemInfo* TAColList::GetItemInfo( int _nItem, int _nSubItem )
{
	if (_nSubItem == 0)
	{
		return &m_FirstItemInfo;
	}
	return &m_pListItemInfo[_nSubItem - 1][_nItem];
}


int TAColList::GetColCount()
{
	return m_pListItemInfo.size() + 1;
}

int TAColList::InsertRow( int _nRow, LPCTSTR _strHeading, LCDType _eType )
{
	//there should be only one col, used as col header
	ASSERT(m_pListItemInfo.size() == 0);
	ListCtrlRowColInfo* pInfo = new ListCtrlRowColInfo;
	pInfo->eType = _eType;

	if ((int)m_pListRowInfo.size() <= _nRow)
	{
		m_pListRowInfo.push_back(pInfo);
	}
	else
	{
		m_pListRowInfo.insert(m_pListRowInfo.begin() + _nRow, pInfo);
	}

	if (_eType == LCDT_RADIO || _eType == LCDT_CHECK)
	{
		pInfo->pImageList = &m_CheckList;
	}

	return CListCtrl::InsertItem(_nRow, _strHeading);
}

int TAColList::InsertColumn( int _nCol, LPCTSTR _strName, 
	void* _pData, int _nFormat /*= LVCFMT_LEFT*/, int _nWidth /*= -1*/,
	int _nSubItem /*= -1*/ )
{
	if (_nCol == 0)//第一列
	{
		return CListCtrl::InsertColumn(_nCol, _strName, _nFormat, _nWidth, _nSubItem);
	}
	else
	{
		ASSERT(_nCol != 0);
		int nItemCount = CListCtrl::GetItemCount();
		ListCtrlItemInfo* pInfo = new ListCtrlItemInfo[nItemCount];
		if (_nCol >= (int)m_pListItemInfo.size())
		{
			m_pListItemInfo.push_back(pInfo);
		}
		else
		{
			m_pListItemInfo.insert(m_pListItemInfo.begin() + _nCol, pInfo);
		}

		//复制列状态
		for (int i=0; i<nItemCount; ++i)
		{
			pInfo[i].bEnable = m_pListRowInfo[i]->bEnable;
			pInfo[i].bGrayed = m_pListRowInfo[i]->bGrayed;
		}

		return CListCtrl::InsertColumn(_nCol, _strName, _nFormat, _nWidth, _nSubItem);
	}
}

BOOL TAColList::DeleteColumn( BOOL nCol )
{
	ASSERT(nCol > 0);
	delete []m_pListRowInfo[nCol];
	m_pListRowInfo.erase(m_pListRowInfo.begin() + nCol);

	return CListCtrl::DeleteColumn(nCol);
}

BOOL TAColList::SetRowEnable( int _nRow, BOOL _bEnable )
{
	if (_bEnable != m_pListRowInfo[_nRow]->bEnable)
	{
		int num = m_pListItemInfo.size();
		for (int i=0; i<num; ++i)
		{
			m_pListItemInfo[i][_nRow].bEnable = _bEnable;
		}
	}
	return TRUE;
}

BOOL TAColList::IsRowEnabled( int _nRow )
{
	return m_pListRowInfo[_nRow]->bEnable;
}

BOOL TAColList::SetRowGrayed( int _nRow, BOOL bGrayed )
{
	if (bGrayed != m_pListRowInfo[_nRow]->bGrayed)
	{
		int num = m_pListItemInfo.size();
		for (int i=0; i<num; ++i)
		{
			m_pListItemInfo[i][_nRow].bGrayed = bGrayed;
		}
	}
	return TRUE;
}

BOOL TAColList::IsRowGrayed( int _nRow )
{
	return m_pListRowInfo[_nRow]->bGrayed;
}

void TAColList::SetRowImageList( int _nRow, CImageList* _p )
{
	m_pListRowInfo[_nRow]->pImageList = _p;
}

ListCtrlRowColInfo* TAColList::GetRowColInfo( int _nRow, int _nCol )
{
	if (_nCol == 0)
	{
		return &m_FirstColItemInfo;
	}
	return m_pListRowInfo[_nRow];
}

void TAColList::Cleanup()
{
	int num = (int)m_pListRowInfo.size();
	for (int i=0; i<num; ++i)
	{
		delete m_pListRowInfo[i];
	}

	num = (int)m_pListItemInfo.size();
	for (int i=0; i<num; ++i)
	{
		delete []m_pListItemInfo[i];
	}
	m_pListItemInfo.clear();
	m_pListRowInfo.clear();
}

void TAColList::DeleteAllColumns()
{

}
