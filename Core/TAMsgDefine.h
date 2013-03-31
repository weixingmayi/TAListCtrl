#pragma once

//ListCtrl
/*
//wparam: list ptr, lparam ptr of
struct{	int nItem, 
		int nSubItem,
		LPCTSTR _perText,
		LPCTSTR _newText};
*/
#define		WM_LISTCTRL_EDITED	WM_USER + 1
/*
//wparam: list ptr, lparam ptr of
struct{	int nItem, 
		int nSubItem,
		int eType,

		vector<CString> vals};
*/
#define		WM_LISTCTRL_COSTOMACTION WM_USER + 2