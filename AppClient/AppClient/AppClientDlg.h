
// AppClientDlg.h : ͷ�ļ�
//

#pragma once


// CAppClientDlg �Ի���
class CAppClientDlg : public CDialogEx
{
// ����
public:
	CAppClientDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_APPCLIENT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// �û�������
	CString m_editUserName;
	// ����
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
