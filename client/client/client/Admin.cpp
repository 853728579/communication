#include "./includes.h"

using namespace std;

void CAdmin::Login()
{
	system("cls");
	cout << endl << endl << endl;
	cout << "\t user name: ";
	cin >> m_admin.name;
	cout << "\t password: ";
	cin >> m_admin.password;

	msg_t msg;

	char hostname[100];
	struct hostent* phost;
	gethostname(hostname, 100);
	phost = gethostbyname(hostname);

	for (int i = 0; phost->h_addr_list[i]; i++)
	{
		char *pIP = inet_ntoa(*(in_addr *)phost->h_addr_list[i]);
		if (pIP)
			cout << pIP << endl;
	}

	msg.type = MT_CLIENT_LOGIN;
	memset(msg.id, 0xff, USER_ID_SIZE);
	memset(msg.ToId, 0xff, USER_ID_SIZE);
	memcpy(msg.mtext, &m_admin, sizeof(admin_t));

	m_pSockZy->SendTo(&msg, sizeof(msg_t), PORT, "192.168.1.202");
}

CAdmin::CAdmin(CSockZy * pSock):m_pSockZy(pSock)
{
}

CAdmin::~CAdmin()
{
}
