#pragma once
#include "CoreExport.h"
#include <vector>
using namespace std;

typedef enum TALISTCTRL_ROWCOLDATATYPE{
	LCDT_UNSET,
	LCDT_TEXT,
	LCDT_INT,
	LCDT_FLOAT,
	LCDT_ENUM,
	LCDT_CHECK,
	LCDT_RADIO,
	LCDT_IMAGE,
	LCDT_COLOR,
	LCDT_TIME,
	LCDT_NO,
}LCDType;

typedef struct TALISTCTRL_ROWCOLINFO{
	//Data
	LCDType			eType;		//type
	vector<CString> strVals;	//string used for enum type
	CImageList*		pImageList;	//imagelist used for image, check and radio

	//status
	BOOL	bEnable;			
	BOOL	bGrayed;

	TALISTCTRL_ROWCOLINFO():pImageList(NULL), bEnable(TRUE), bGrayed(FALSE),
		eType(LCDT_UNSET){};

}ListCtrlRowColInfo;

enum TALISTITEM_STATUS{
	TAITEM_UNSELECTED = 0,
	TAITEM_SELECTED,
	TAITEM_EDITING,
};

typedef struct TALISTCTRL_ITEMINFO{
	//item status
	BOOL				bEnable;
	BOOL				bGrayed;
	TALISTITEM_STATUS	eStatus;

	//data can't be presented by text
	union	TAITEMDATE{
		int			nImage;
		COLORREF	clr;
		BOOL		bChecked;
	}itemData;

	TALISTCTRL_ITEMINFO():bEnable(TRUE),bGrayed(FALSE),
		eStatus(TAITEM_UNSELECTED)
	{
		itemData.nImage = 0;
	};

}ListCtrlItemInfo;

typedef struct TALISTCTRL_ITEMEDITINFO{
	int		nItem;
	int		nSubItem;
	LCDType eType;

	union ITEMDATA{
		int nData;
		int nImage;
		COLORREF clr;
		BOOL bChecked;
		LPCTSTR str;
		float fData;
	};
	union ITEMDATA perData, newData;
}ListCtrlItemEditInfo;

class CORE_API TAListCtrl : public CListCtrl
{
	DECLARE_DYNAMIC(TAListCtrl)

public:
	TAListCtrl();
	virtual ~TAListCtrl();
	
	static const int COMSTOM_LISTCTRL_IMAGE_SIZE = 16;
protected:
	//default image list
	CImageList	m_CheckList;

	static const int LISTCTRL_IMAGE_SIZE = 13;
	

	//select 
	int m_iSelItem, m_iSelSubItem;
	ListCtrlItemInfo*	m_pCurSelItem;

	//edit ctrls
	CEdit m_editCtrl;
	CComboBox m_comboxCtrl;

	//Last edit information
	ListCtrlItemEditInfo	m_lastEditInfo;

	//Tools
	virtual ListCtrlItemInfo*	GetItemInfo(int _nItem, int _nSubItem) = 0;

	virtual ListCtrlRowColInfo*	GetRowColInfo(int _nRow, int _nCol) = 0;

	virtual int					GetColCount() = 0;

	void		DrawCostomImage(CDC* _pDC, const CRect& rect, CImageList* _pImageList, int _nImage);
	void		DrawImage(CDC* _pDC, const CRect& rect, CImageList* _pImageList, int _nImage);
	void		DrawItemText(CDC* _pDC, const CRect& _rect, LPCTSTR _str, int _nFormat, BOOL _bGrayed);

	virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);

	void		SelectItem( ListCtrlItemInfo* _pItem );
	void		SelectItem( int _nItem, int _nSubItem );
	BOOL		EditItem( CRect& _rect );

	void		OnEditSubItem(int _nItem, int _nSubItem);
	void		OnSelectItemRadio(int _nItem, int _nSubItem);

public:
	BOOL		SetItemColor(int _nItem, int _nSubItem, COLORREF _clr);
	BOOL		SetItemCheck(int _nItem, int _nSubItem, BOOL _bChecked);
	BOOL		SetItemEnable(int _nItem, int _nSubItem, BOOL _bEnable, BOOL _bGray);
	BOOL		SetItemImage(int _nItem, int _nSubItem, int _idx);
	BOOL		SetItemText(int nItem, int nSubItem, LPCTSTR lpszText);

	COLORREF	GetItemColor(int _nItem, int _nSubItem);
	BOOL		IsItemChecked(int _nItem, int _nSubItem);
	BOOL		IsItemEnabled(int _nItem, int _nSubItem);
	int			GetItemImage(int _nItem, int _nSubItem);
	BOOL		GetItemText(int nItem, int nSubItem, CString& _str);

	BOOL			OnAttach(int _mode);


	DECLARE_MESSAGE_MAP()
	afx_msg int		OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void	OnLButtonDown(UINT nFlags, CPoint point);
};


