
#include "./includes.h"

using namespace std;

void CAdmin::Login(msg_t * pMsg)
{
	admin_t * pAdmin;

	pAdmin = (admin_t *)pMsg->mtext;
	cout<<"name:" <<pAdmin->name <<endl;
	cout<<"password:"<< pAdmin->password <<endl;

	//����ʧ��
	
	//����ɹ�
	msg_t * pTxMsg = new msg_t;

	pTxMsg->type = MT_LOGIN;
	pTxMsg->mtext[0] = 1;

	m_pSockZy->SendTo((const void *)pTxMsg, sizeof(msg_t), PORT, (LPCTSTR)pMsg->id);

	delete pTxMsg;
}

void CAdmin::Register(msg_t * pMsg)
{
	//�û�ע�ᴦ��
	
}

CAdmin::CAdmin(CSockZy * pSock):m_pSockZy(pSock)
{

}

CAdmin::~ CAdmin()
{

}

