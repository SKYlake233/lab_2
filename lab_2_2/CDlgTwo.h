#pragma once
#include "afxdialogex.h"


// CDlgTwo 对话框

class CDlgTwo : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgTwo)

public:
	CDlgTwo(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDlgTwo();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CProgressCtrl m_prog;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnTimeChange();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
