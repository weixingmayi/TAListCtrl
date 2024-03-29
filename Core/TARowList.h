#pragma once
#include "talistctrl.h"
class CORE_API TARowList :
	public TAListCtrl
{
	DECLARE_DYNCREATE(TARowList)
public:
	TARowList(void);
	~TARowList(void);

protected:
	//数据
	vector<ListCtrlRowColInfo*>	m_pListColInfo;		//列的数组
	vector<ListCtrlItemInfo*>	m_pListItemInfo;	//item数组的数组

	virtual ListCtrlItemInfo*	GetItemInfo(int _nItem, int _nSubItem);
	virtual ListCtrlRowColInfo*	GetRowColInfo(int _nRow, int _nCol);
	virtual int					GetColCount();


	int			InsertItemWithNo(int _nItem);
	void		DeleteItemWidthNo(int _nItem);

	void		Cleanup(void);
public:
	int			InsertColumn(int _nCol, LPCTSTR _strHeading,  LCDType _eType, 
		int _nFormat = LVCFMT_LEFT,	int _nWidth = -1, int _nSubItem = -1);

	int			InsertItem(int _nItem, LPCTSTR _strName, void* _pData);
	BOOL		DeleteItem(BOOL nItem);

	BOOL		SetColumnEnable(int _nCol, BOOL _bEnable);
	BOOL		IsColumnEnabled(int _nCol);

	BOOL		SetColumnGrayed(int _nCol, BOOL bGrayed);
	BOOL		IsColumnGrayed(int _nCol);

	void		SetColumnImageList(int _nCol,CImageList* _p);
	
	DECLARE_MESSAGE_MAP()
};

