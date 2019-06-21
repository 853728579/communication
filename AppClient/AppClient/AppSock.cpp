#include "stdafx.h"
#include "AppSock.h"
#include <stdio.h>

using namespace std;

CAppSock::CAppSock()
{
	m_strIP = _T("192.168.0.103");
	m_port = 10002;

	if (!m_sock.Create(m_port, SOCK_DGRAM))
	{
		return;
	}
	m_sock.Connect(m_strIP, m_port);
}


CAppSock::~CAppSock()
{
	m_sock.Close();
}

int CAppSock::Login(CString user, CString password)
{
	m_msg.type = MT_LOGIN;

	memcpy(m_msg.mtext, user, user.GetLength());
	memcpy(&(m_msg.mtext[20]), password, password.GetLength());

	m_sock.Send((void *)&m_msg, sizeof(msg_t));
	m_sock.Receive((void *)&m_msg, sizeof(msg_t));

	if ((m_msg.type == MT_LOGIN)
		&& (m_msg.mtext[0] == 0x01))
	{
		return 1;
	}

	return 0;
}


