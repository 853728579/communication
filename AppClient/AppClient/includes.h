#pragma once

#define PORT				(10002)

#define MSG_MAX_SIZE		(1024)

#define MSG_NAME_SIZE		(20)

#define USER_ID_SIZE		(20)

#define PASSWORD_SIZE		(20)

typedef enum{

	MT_LOGIN = 10,		/*登入*/
	MT_REGISTER,		/*注册*/
	MT_GET_FRIEND,		/*获取好友*/
	/*client*/
	MT_CLIENT_CHAT,
	MT_CLIENT_QUIT,

	/*server*/
	MT_SERVER_CHAT = 200,
	MT_SERVER_QUIT
}msg_type_e;
