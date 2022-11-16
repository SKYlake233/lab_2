// CDlgFour.cpp: 实现文件
//

#include "pch.h"
#include "lab_2_2.h"
#include "afxdialogex.h"
#include "CDlgFour.h"


// CDlgFour 对话框

IMPLEMENT_DYNAMIC(CDlgFour, CDialogEx)

CDlgFour::CDlgFour(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG4, pParent)
{

}

CDlgFour::~CDlgFour()
{
}

void CDlgFour::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_TREE1, m_tree);
}


BEGIN_MESSAGE_MAP(CDlgFour, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CDlgFour::OnLvnItemchangedList1)
END_MESSAGE_MAP()


// CDlgFour 消息处理程序


void CDlgFour::OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


BOOL CDlgFour::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	TVINSERTSTRUCT inSertRoot;
	inSertRoot.hParent = TVI_ROOT;
	inSertRoot.hInsertAfter = TVI_LAST;
	inSertRoot.item.mask = TVIF_TEXT;
	inSertRoot.item.pszText = L"河南科技大学";
	//根
	HTREEITEM iRoot = m_tree.InsertItem(&inSertRoot);
	//设置上一层节点
	inSertRoot.hParent = iRoot;
	//
	inSertRoot.hInsertAfter = TVI_LAST;
	inSertRoot.item.mask = TVIF_TEXT;
	inSertRoot.item.pszText = L"信息工程学院";

	HTREEITEM iSubRoot = m_tree.InsertItem(&inSertRoot);
	//inSertRoot.hParent = iSubRoot;
	//inSertRoot.hInsertAfter = iRoot;

	m_list.InsertColumn(0, L"姓名", LVCFMT_CENTER, 50);
	m_list.InsertColumn(0, L"性别", LVCFMT_CENTER, 50);
	int item = m_list.InsertItem(0, L"1");
	m_list.SetItemText(item, 1, L"王");
	m_list.SetItemText(item, 2, L"男");


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
