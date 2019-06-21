
// AppClientDlg.cpp : ʵ���ļ�
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


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CAppClientDlg �Ի���



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


// CAppClientDlg ��Ϣ�������

BOOL CAppClientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	AfxSocketInit();
	staErrShow = _T("�û������������");
	UpdateData(FALSE);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CAppClientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CAppClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//ע��
void CAppClientDlg::OnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

}
//����
void CAppClientDlg::OnClickedButton3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
		//����ʧ��
		pWnd->ShowWindow(SW_SHOW);

		return;
	}

}




HBRUSH CAppClientDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	if (IDC_STATIC_ERR == pWnd->GetDlgCtrlID())
	{
		pDC->SetTextColor(RGB(255, 0, 0));
	}
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}

void CAppClientDlg::OnSetfocusEdit1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_STATIC_ERR)->ShowWindow(SW_HIDE);
}


void CAppClientDlg::OnSetfocusEdit2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_STATIC_ERR)->ShowWindow(SW_HIDE);
}


