
// AppClientDlg.h : 头文件
//

#pragma once


// CAppClientDlg 对话框
class CAppClientDlg : public CDialogEx
{
// 构造
public:
	CAppClientDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_APPCLIENT_DIALOG };

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
	// 用户名变量
	CString m_editUserName;
	// 密码
	CString m_editPassword;
//	afx_msg void OnEnChangeEdit1();
	afx_msg void OnClickedButton3();
	afx_msg void OnClickedButton2();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
//	afx_msg void OnSetfocusEdit();
	afx_msg void OnSetfocusEdit1();
	afx_msg void OnSetfocusEdit2();
	CString staErrShow;
};
