#pragma once
#include "afxdialogex.h"


// CDlgOne 对话框

class CDlgOne : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgOne)

public:
	CDlgOne(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDlgOne();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
//	CComboBox combo;
//	CEdit m_edit;
	afx_msg void OnSelchangeCombo1();
	int m_combo;
	int m_edit;
};
