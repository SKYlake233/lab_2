
// lab_2Dlg.h: 头文件
//

#pragma once


// Clab2Dlg 对话框
class Clab2Dlg : public CDialogEx
{
// 构造
public:
	Clab2Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LAB_2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
//	BOOL m_sex;
//	CString c_result;
//	int m_sex;
	afx_msg void OnBnClickedButton1();
	// 性别
	BOOL m_sex;
//	BOOL c_socre;
	CString m_result;
	CString m_name;
	BOOL m_score;
	afx_msg void OnBnClickedButtonShow();
	int m_class;
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnNMThemeChangedScrollbarRed(NMHDR* pNMHDR, LRESULT* pResult);
	CScrollBar m_red;
	CScrollBar m_green;
	CScrollBar m_blue;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	CStatic m_color;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CListBox m_left;
	CListBox m_right;
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonDel();
	afx_msg void OnBnClickedButtonAddall();
	afx_msg void OnBnClickedButtonDelall();
};
