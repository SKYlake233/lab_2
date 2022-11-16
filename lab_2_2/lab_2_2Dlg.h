
// lab_2_2Dlg.h: 头文件
//

#pragma once
#include"CDlgOne.h"
#include"CDlgTwo.h"
#include"CDlgThree.h"
#include"CDlgFour.h"


// Clab22Dlg 对话框
class Clab22Dlg : public CDialogEx
{
// 构造
public:
	Clab22Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LAB_2_2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	CDlgOne cDlgOne;
	CDlgTwo cDlgTwo;
	CDlgThree cDlgThree;
	CDlgFour cDlgFour;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tab;
	afx_msg void OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
};
