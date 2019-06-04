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
	void Login();

	CAdmin(CSockZy * pSock);

	~CAdmin();
};

