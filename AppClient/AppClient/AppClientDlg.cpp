
// AppClientDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "AppClient.h"
#include "AppClientDlg.h"
#include "afxdialogex.h"
#include "AppSock.h"

#include "afxsock.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnClose();
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
//	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CAppClientDlg 对话框



CAppClientDlg::CAppClientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAppClientDlg::IDD, pParent)
	, m_editUserName(_T(""))
	, m_editPassword(_T(""))
	, staErrShow(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAppClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_editUserName);
	DDX_Text(pDX, IDC_EDIT2, m_editPassword);
	DDV_MaxChars(pDX, m_editPassword, 100);
	DDX_Text(pDX, IDC_STATIC_ERR, staErrShow);
	DDV_MaxChars(pDX, staErrShow, 20);
}

BEGIN_MESSAGE_MAP(CAppClientDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//	ON_EN_CHANGE(IDC_EDIT1, &CAppClientDlg::OnEnChangeEdit1)
ON_BN_CLICKED(IDC_BUTTON3, &CAppClientDlg::OnClickedButton3)
ON_BN_CLICKED(IDC_BUTTON2, &CAppClientDlg::OnClickedButton2)
ON_WM_CTLCOLOR()
//ON_EN_SETFOCUS(IDC_EDIT1, &CAppClientDlg::OnSetfocusEdit)
ON_EN_SETFOCUS(IDC_EDIT1, &CAppClientDlg::OnSetfocusEdit1)
ON_EN_SETFOCUS(IDC_EDIT2, &CAppClientDlg::OnSetfocusEdit2)
END_MESSAGE_MAP()


// CAppClientDlg 消息处理程序

BOOL CAppClientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// TODO:  在此添加额外的初始化代码
	AfxSocketInit();
	staErrShow = _T("用户名或密码错误！");
	UpdateData(FALSE);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CAppClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAppClientDlg::OnPaint()
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
HCURSOR CAppClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//注册
void CAppClientDlg::OnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码

}
//登入
void CAppClientDlg::OnClickedButton3()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);

	CWnd * pWnd = GetDlgItem(IDC_STATIC_ERR);

	if ((m_editUserName.IsEmpty())
		|| (m_editPassword.IsEmpty()))
	{
		pWnd->ShowWindow(SW_SHOW);

		return;
	}
	CAppSock appSock;
	if (! appSock.Login(m_editUserName, m_editPassword))
	{
		//登入失败
		pWnd->ShowWindow(SW_SHOW);

		return;
	}

}




HBRUSH CAppClientDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if (IDC_STATIC_ERR == pWnd->GetDlgCtrlID())
	{
		pDC->SetTextColor(RGB(255, 0, 0));
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}

void CAppClientDlg::OnSetfocusEdit1()
{
	// TODO:  在此添加控件通知处理程序代码
	GetDlgItem(IDC_STATIC_ERR)->ShowWindow(SW_HIDE);
}


void CAppClientDlg::OnSetfocusEdit2()
{
	// TODO:  在此添加控件通知处理程序代码
	GetDlgItem(IDC_STATIC_ERR)->ShowWindow(SW_HIDE);
}


