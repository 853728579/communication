
#pragma once

#ifdef _WIN32

typedef int socklen_t;
typedef void RET_TYPE;

#else

typedef unsigned int 		SOCKET;
typedef struct in_addr 		IN_ADDR;
typedef unsigned long       DWORD;
typedef int                 BOOL;
typedef unsigned char       BYTE;
typedef unsigned short      WORD;
typedef float               FLOAT;
typedef FLOAT               *PFLOAT;
typedef BOOL            	*PBOOL;
typedef BOOL             	*LPBOOL;
typedef BYTE            	*PBYTE;
typedef BYTE             	*LPBYTE;
typedef int             	*PINT;
typedef int              	*LPINT;
typedef WORD            	*PWORD;
typedef WORD             	*LPWORD;
typedef long             	*LPLONG;
typedef DWORD           	*PDWORD;
typedef DWORD            	*LPDWORD;
typedef void             	*LPVOID;

typedef int                 INT;
typedef unsigned int        UINT;
typedef unsigned int        *PUINT;
typedef const char* LPCTSTR,*LPCSTR;
typedef char * LPTSTR,*LPSTR;
typedef void * RET_TYPE;
	
#endif /* #ifdef _WIN32 */
