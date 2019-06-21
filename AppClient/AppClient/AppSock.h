#pragma once
#include "afxsock.h"
#include "includes.h"
class CAppSock : public CSocket
{
	typedef struct msg_str
	{
		unsigned int type;
		unsigned char id[USER_ID_SIZE];
		unsigned char ToId[USER_ID_SIZE];
		unsigned char mtext[MSG_MAX_SIZE];
	}msg_t;

	CSocket m_sock;

	msg_t m_msg;

	CString m_strIP;
	int m_port;

public:
	CAppSock();
	~CAppSock();

	int Login(CString user, CString password);
};

