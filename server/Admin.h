
#pragma once

class CAdmin
{
	typedef struct Admin{
		unsigned char name[MSG_NAME_SIZE];
		unsigned char password[PASSWORD_SIZE];
	}admin_t;

	admin_t m_admin;

	CSockZy * m_pSockZy;

public:
	//µ«»Î
	void Login(msg_t * pMsg);

	CAdmin(CSockZy * pSock);
	~CAdmin();
};

