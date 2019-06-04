
#include "./includes.h"

using namespace std;

void CAdmin::Login(msg_t * pMsg)
{
	UINT port;
	char ip[20] = {0};
	admin_t * pAdmin;

	m_pSockZy->GetSockName((LPTSTR)ip, port);

	printf("%s\n", ip);

	pAdmin = (admin_t *)pMsg->mtext;
	cout<< pAdmin->name <<endl;
	cout<< pAdmin->password <<endl;
}

CAdmin::CAdmin(CSockZy * pSock):m_pSockZy(pSock)
{

}

CAdmin::~ CAdmin()
{

}

