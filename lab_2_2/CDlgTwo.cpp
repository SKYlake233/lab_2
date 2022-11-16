// CDlgTwo.cpp: 实现文件
//

#include "pch.h"
#include "lab_2_2.h"
#include "afxdialogex.h"
#include "CDlgTwo.h"


// CDlgTwo 对话框

IMPLEMENT_DYNAMIC(CDlgTwo, CDialogEx)

CDlgTwo::CDlgTwo(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

CDlgTwo::~CDlgTwo()
{
}

void CDlgTwo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, m_prog);
}


BEGIN_MESSAGE_MAP(CDlgTwo, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgTwo::OnBnClickedButton1)
	ON_WM_TIMECHANGE()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CDlgTwo 消息处理程序


BOOL CDlgTwo::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_prog.SetRange(0, 100);
	m_prog.SetPos(0);
	m_prog.SetStep(1);


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CDlgTwo::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	SetTimer(0, 10, NULL);
}


void CDlgTwo::OnTimeChange()
{
	CDialogEx::OnTimeChange();

	// TODO: 在此处添加消息处理程序代码
}


void CDlgTwo::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (nIDEvent == 0) {
		m_prog.StepIt();
		int pos = m_prog.GetPos();
		if (pos == 100)
			m_prog.SetPos(0);
		KillTimer(0);
	}
	CDialogEx::OnTimer(nIDEvent);
}
