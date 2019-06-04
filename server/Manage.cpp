
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
		//len = m_sock.Receive(&msg, sizeof(msg_t));
		len = m_sock.ReceiveFrom(&msg, sizeof(msg_t), (LPTSTR)ip, port);
		cout<<"ip:"<<ip<<endl;
		switch(msg.type)
		{
			case MT_CLIENT_LOGIN:m_admin.Login(&msg);break;
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

