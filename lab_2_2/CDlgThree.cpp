// CDlgThree.cpp: 实现文件
//

#include "pch.h"
#include "lab_2_2.h"
#include "afxdialogex.h"
#include "CDlgThree.h"


// CDlgThree 对话框

IMPLEMENT_DYNAMIC(CDlgThree, CDialogEx)

CDlgThree::CDlgThree(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

CDlgThree::~CDlgThree()
{
}

void CDlgThree::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER1, m_slider);
}


BEGIN_MESSAGE_MAP(CDlgThree, CDialogEx)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER1, &CDlgThree::OnReleasedcaptureSlider1)
END_MESSAGE_MAP()


// CDlgThree 消息处理程序


void CDlgThree::OnReleasedcaptureSlider1(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	int pos = m_slider.GetPos();
	CString sPos;
	sPos.Format(L"%d", pos);
	MessageBox(sPos, L"注意", MB_OK);
	*pResult = 0;
}


BOOL CDlgThree::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_slider.SetRange(0, 10);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
