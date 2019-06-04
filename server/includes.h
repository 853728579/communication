
#pragma once

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS


#define PORT				(10002)

#define MSG_MAX_SIZE		(1024)

#define MSG_NAME_SIZE		(20)

#define USER_ID_SIZE		(6)

#define PASSWORD_SIZE		(20)

#include <iostream>
#include <stdlib.h>
#include "type.h"

#ifdef _WIN32

#include <WinSock2.h>
#include <process.h>
#ifdef _UNICODE
#include <comdef.h>
#endif/* #ifdef _UNICODE */

#else  /* ---------  linux  ----------- */

#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>


#ifndef FALSE
 #define FALSE               (0U)
#endif

#ifndef TRUE
 #define TRUE                (1U)
#endif

#endif  /*#ifdef _WIN32*/

typedef enum{
	/*client*/
	MT_CLIENT_LOGIN  = 100,
	MT_CLIENT_CHAT,
	MT_CLIENT_QUIT,

	/*server*/
	MT_SERVER_CHAT   = 200,
	MT_SERVER_QUIT
}msg_type_e;

typedef struct{
	unsigned int online		: 1;				/*在线状态*/
	unsigned int reserve	: 31;
}user_status_t;

typedef struct user_info{
	unsigned char id[USER_ID_SIZE];				/*用户账号*/
	unsigned char name[MSG_NAME_SIZE];			/*用户名  */
	unsigned char password[PASSWORD_SIZE];		/*密码    */
	user_status_t status;
	IN_ADDR		  ClientAddr;
	struct user_info * pNext;
}user_info_t;

typedef struct{
    unsigned int type;
	unsigned char id[USER_ID_SIZE];
    unsigned char ToId[USER_ID_SIZE];
    unsigned char mtext[MSG_MAX_SIZE];
}msg_t, *msg_pt;


#include "SockZy.h"
#include "Admin.h"
#include "Manage.h"


