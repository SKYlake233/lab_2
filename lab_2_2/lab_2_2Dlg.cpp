
// lab_2_2Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "lab_2_2.h"
#include "lab_2_2Dlg.h"
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
	virtual BOOL OnInitDialog();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Clab22Dlg 对话框



Clab22Dlg::Clab22Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LAB_2_2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Clab22Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tab);
}

BEGIN_MESSAGE_MAP(Clab22Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &Clab22Dlg::OnSelchangeTab1)
END_MESSAGE_MAP()


// Clab22Dlg 消息处理程序

BOOL Clab22Dlg::OnInitDialog()
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
	m_tab.DeleteAllItems();
	m_tab.InsertItem(0, L"编辑框");
	m_tab.InsertItem(0, L"进度条");
	m_tab.InsertItem(0, L"滑动条");
	m_tab.InsertItem(0, L"树形控件");
	CRect rect;
	m_tab.GetClientRect(&rect);
	rect.top += 200;
	rect.left += 500;
	rect.bottom += 200;
	rect.right += 500;


	cDlgOne.Create(IDD_DIALOG1, &m_tab);
	cDlgTwo.Create(IDD_DIALOG2, &m_tab);
	cDlgThree.Create(IDD_DIALOG3, &m_tab);
	cDlgFour.Create(IDD_DIALOG4, &m_tab);

	cDlgOne.ShowWindow(SW_NORMAL);
	cDlgOne.MoveWindow(&rect);
	cDlgTwo.MoveWindow(&rect);
	cDlgThree.MoveWindow(&rect);
	cDlgFour.MoveWindow(&rect);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void Clab22Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void Clab22Dlg::OnPaint()
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
HCURSOR Clab22Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Clab22Dlg::OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	int t = m_tab.GetCurSel();
	switch (t)
	{
	case 0:
		cDlgOne.ShowWindow(SW_NORMAL);
		cDlgTwo.ShowWindow(SW_HIDE);
		cDlgThree.ShowWindow(SW_HIDE);
		cDlgFour.ShowWindow(SW_HIDE);
		break;
	case 1:
		cDlgOne.ShowWindow(SW_HIDE);
		cDlgTwo.ShowWindow(SW_NORMAL);
		cDlgThree.ShowWindow(SW_HIDE);
		cDlgFour.ShowWindow(SW_HIDE);
		break;
	case 2:
		cDlgOne.ShowWindow(SW_HIDE);
		cDlgTwo.ShowWindow(SW_HIDE);
		cDlgThree.ShowWindow(SW_NORMAL);
		cDlgFour.ShowWindow(SW_HIDE);
		break;
	case 3:
		cDlgOne.ShowWindow(SW_HIDE);
		cDlgTwo.ShowWindow(SW_HIDE);
		cDlgThree.ShowWindow(SW_HIDE);
		cDlgFour.ShowWindow(SW_NORMAL);
		break;
	default:
		break;
	}

	*pResult = 0;
}


BOOL CAboutDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
