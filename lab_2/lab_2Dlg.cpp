
// lab_2Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "lab_2.h"
#include "lab_2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// Clab2Dlg 对话框



Clab2Dlg::Clab2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LAB_2_DIALOG, pParent)
	, m_sex(0)
	, m_result(_T(""))
	, m_name(_T(""))
	, m_score(FALSE)
	, m_class(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Clab2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO_MAN, m_sex);
	DDX_Text(pDX, IDC_EDIT_RESULT, m_result);
	DDX_Text(pDX, IDC_EDIT_NAME, m_name);
	DDX_Radio(pDX, IDC_RADIO_JIGE, m_score);
	DDX_Radio(pDX, IDC_RADIO_CLASS1, m_class);
	DDX_Control(pDX, IDC_SCROLLBAR_RED, m_red);
	DDX_Control(pDX, IDC_SCROLLBAR_GREEN, m_green);
	DDX_Control(pDX, IDC_SCROLLBAR_BLUE, m_blue);
	DDX_Control(pDX, IDC_COLOR, m_color);
	DDX_Control(pDX, IDC_LIST_LEFT, m_left);
	DDX_Control(pDX, IDC_LIST_RIGHT, m_right);
}

BEGIN_MESSAGE_MAP(Clab2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_SHOW, &Clab2Dlg::OnBnClickedButtonShow)
	//ON_LBN_SELCHANGE(IDC_LIST1, &Clab2Dlg::OnLbnSelchangeList1)
	ON_NOTIFY(NM_THEMECHANGED, IDC_SCROLLBAR_RED, &Clab2Dlg::OnNMThemeChangedScrollbarRed)
	ON_WM_HSCROLL()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON_ADD, &Clab2Dlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_DEL, &Clab2Dlg::OnBnClickedButtonDel)
	ON_BN_CLICKED(IDC_BUTTON_ADDALL, &Clab2Dlg::OnBnClickedButtonAddall)
	ON_BN_CLICKED(IDC_BUTTON_DELALL, &Clab2Dlg::OnBnClickedButtonDelall)
END_MESSAGE_MAP()


// Clab2Dlg 消息处理程序

BOOL Clab2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_red.SetScrollRange(0, 255);
	m_red.SetScrollPos(10);
	m_green.SetScrollRange(0, 255);
	m_green.SetScrollPos(10);
	m_blue.SetScrollPos(10);
	m_blue.SetScrollRange(0, 255);

	m_left.AddString(L"1");
	m_left.AddString(L"2");
	m_left.AddString(L"3");
	m_left.AddString(L"4");
	m_left.AddString(L"5");

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void Clab2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Clab2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Clab2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Clab2Dlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}



void Clab2Dlg::OnBnClickedButtonShow()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_result = "";

	m_result += m_name += " ";
	m_result += (m_sex == 0) ? "男 " : "女 ";
	m_result += (m_score == 0) ? "及格 " : "不及格 ";
	if (m_class == 0) m_result += "一班 ";
	else if (m_class == 1) m_result += "二班 ";
	else if (m_class == 3) m_result += "三班 ";
	else if (m_class == 4) m_result += "四班 ";
	UpdateData(FALSE);
}


void Clab2Dlg::OnLbnSelchangeList1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void Clab2Dlg::OnNMThemeChangedScrollbarRed(NMHDR* pNMHDR, LRESULT* pResult)
{
	// 该功能要求使用 Windows XP 或更高版本。
	// 符号 _WIN32_WINNT 必须 >= 0x0501。
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void Clab2Dlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int pos = pScrollBar->GetScrollPos();
	if (nSBCode == SB_LINELEFT) pScrollBar->SetScrollPos(++pos);
	if (nSBCode == SB_LINERIGHT) pScrollBar->SetScrollPos(--pos);
	if (nSBCode == SB_PAGELEFT) pScrollBar->SetScrollPos(pos - 10);
	if (nSBCode == SB_PAGERIGHT) pScrollBar->SetScrollPos(pos + 10);
	if (nSBCode == SB_THUMBPOSITION) pScrollBar->SetScrollPos(nPos);
	m_color.Invalidate();
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}



HBRUSH CAboutDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	// TODO:  在此更改 DC 的任何特性
	if (pWnd->GetDlgCtrlID() == IDC_COLOR) {
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}



HBRUSH Clab2Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if (pWnd->GetDlgCtrlID() == IDC_COLOR) {
		byte red = m_red.GetScrollPos();
		byte green = m_green.GetScrollPos();
		byte blue = m_blue.GetScrollPos();

		HBRUSH hBRUSH = CreateSolidBrush(RGB(red, green, blue));
		return hBRUSH;
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


void Clab2Dlg::OnBnClickedButtonAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	int i = m_left.GetSel(0);
	if (i != LB_ERR) {
		CString str;
		m_left.GetText(i, str);
		m_left.DeleteString(i);
		m_right.AddString(str);
	}
}


void Clab2Dlg::OnBnClickedButtonDel()
{
	// TODO: 在此添加控件通知处理程序代码
	int i = m_right.GetSel(0);
	if (i != LB_ERR) {
		CString str;
		m_right.GetText(i, str);
		m_right.DeleteString(i);
		m_left.AddString(str);
	}
}


void Clab2Dlg::OnBnClickedButtonAddall()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i = 0; i < m_left.GetCount(); i++) {
		CString str;
		m_left.GetText(i, str);
		m_right.AddString(str);
	}
	m_left.ResetContent();
}


void Clab2Dlg::OnBnClickedButtonDelall()
{
	// TODO: 在此添加控件通知处理程序代码
	// TODO: 在此添加控件通知处理程序代码
	for (int i = 0; i < m_right.GetCount(); i++) {
		CString str;
		m_right.GetText(i, str);
		m_left.AddString(str);
	}
	m_right.ResetContent();
}
