#pragma once
#include "afxdialogex.h"


// CDlgThree 对话框

class CDlgThree : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgThree)

public:
	CDlgThree(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDlgThree();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CSliderCtrl m_slider;
	afx_msg void OnReleasedcaptureSlider1(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
};
