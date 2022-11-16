// CDlgOne.cpp: 实现文件
//

#include "pch.h"
#include "lab_2_2.h"
#include "afxdialogex.h"
#include "CDlgOne.h"


// CDlgOne 对话框

IMPLEMENT_DYNAMIC(CDlgOne, CDialogEx)

CDlgOne::CDlgOne(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_combo(0)
	, m_edit(0)
{

}

CDlgOne::~CDlgOne()
{
}

void CDlgOne::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_COMBO1, combo);
	//  DDX_Control(pDX, IDC_EDIT1, m_edit);
	DDX_CBIndex(pDX, IDC_COMBO1, m_combo);
	DDX_Text(pDX, IDC_EDIT1, m_edit);
}


BEGIN_MESSAGE_MAP(CDlgOne, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CDlgOne::OnSelchangeCombo1)
END_MESSAGE_MAP()


// CDlgOne 消息处理程序


void CDlgOne::OnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_edit = m_combo;
	UpdateData(FALSE);
}
