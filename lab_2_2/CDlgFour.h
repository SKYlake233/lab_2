#pragma once
#include "afxdialogex.h"


// CDlgFour 对话框

class CDlgFour : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgFour)

public:
	CDlgFour(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDlgFour();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	CListCtrl m_list;
	CTreeCtrl m_tree;
	virtual BOOL OnInitDialog();
};
