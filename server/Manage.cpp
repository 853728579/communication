
#include "./includes.h"

using namespace std;

void CManage::Start()
{
	msg_t msg;
	int len;
	UINT port;
	char ip[20] = {0};

	//SOCK_DGRAM UDP
	if (!m_sock.Create(PORT, SOCK_DGRAM))
	{
		cout<<"create error!"<<endl;
		
		return ;
	}

	while (1)
	{
		memset(msg.id, 0, USER_ID_SIZE);
		memset(msg.ToId, 0, USER_ID_SIZE);
		memset(msg.mtext, 0, MSG_MAX_SIZE);
		//len = m_sock.Receive(&msg, sizeof(msg_t));
		len = m_sock.ReceiveFrom(&msg, sizeof(msg_t), (LPTSTR)ip, port);

		strncpy((char *)msg.id, (const char *)ip, USER_ID_SIZE);
		cout<<"ip:"<<msg.id<<endl;

		switch(msg.type)
		{
			case MT_LOGIN:		m_admin.Login(&msg);	break;
			case MT_REGISTER:	m_admin.Register(&msg);	break;
			case MT_GET_FRIEND:/*»ñÈ¡ºÃÓÑ*/  break;
			case MT_CLIENT_CHAT: break;
			default:break;
		}
	}
}

CManage::CManage():m_admin(&m_sock)
{
	
}
CManage::~CManage()
{
	
}

