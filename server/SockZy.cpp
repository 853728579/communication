
#include "./includes.h"

#ifdef _WIN32
#pragma comment (lib,"ws2_32.lib")
#endif

CSockZy::CSockZy()
{
#ifdef _WIN32
	WSAData wd;
	WSAStartup(0x0202, &wd);
#endif
	m_hSocket = INVALID_SOCKET;
}


CSockZy::~CSockZy()
{
	Close();
}
//
//鎿嶄綔鎴愬姛杩斿洖true,澶辫触杩斿洖false
BOOL CSockZy::Create(UINT nSocketPort, int nSocketType, LPCTSTR lpszSocketAddress)
{//socket & bind
	m_hSocket = socket(AF_INET, nSocketType, 0);
	if (m_hSocket == INVALID_SOCKET)
	{
		return FALSE;
	}
	sockaddr_in sa = { AF_INET,htons(nSocketPort) };
	if(lpszSocketAddress)
		Pton(lpszSocketAddress, sa.sin_addr);

	return !bind(m_hSocket, (sockaddr*)&sa, sizeof(sa));
}

BOOL CSockZy::Accept(CSockZy & socka, LPTSTR sIP, UINT * nPort)
{
	sockaddr_in sa = { AF_INET };
	socklen_t nLen = sizeof(sa);
	socka.m_hSocket = accept(m_hSocket, (sockaddr*)&sa, &nLen);
	if (INVALID_SOCKET == socka.m_hSocket)
		return FALSE;
	if (sIP)
		Ntop(sa.sin_addr, sIP);
	if (nPort)
		*nPort = htons(sa.sin_port);
	return TRUE;
}

BOOL CSockZy::Connect(LPCTSTR lpszHostAddress, UINT nHostPort)
{
	sockaddr_in sa = { AF_INET,htons(nHostPort) };
	Pton(lpszHostAddress, sa.sin_addr);
	return !connect(m_hSocket, (sockaddr*)&sa, sizeof(sa));
}

int CSockZy::SendTo(const void * lpBuf, int nBufLen, UINT nHostPort, LPCTSTR lpszHostAddress, int nFlags)
{
	sockaddr_in sa = { AF_INET,htons(nHostPort) };
	Pton(lpszHostAddress, sa.sin_addr);
	sendto(m_hSocket, (const char*)lpBuf, nBufLen, 0, (sockaddr*)&sa, sizeof(sa));
	return 0;
}

int CSockZy::ReceiveFrom(void * lpBuf, int nBufLen, LPTSTR  rSocketAddress, UINT & rSocketPort, int nFlags)
{
	sockaddr_in sa = { AF_INET };
	socklen_t nLen = sizeof(sa);
	int nRet = recvfrom(m_hSocket, (char*)lpBuf, nBufLen, 0, (sockaddr*)&sa, &nLen);
	if (nRet <= 0)
		return nRet;

	rSocketPort = htons(sa.sin_port);
	if (rSocketAddress)
		Ntop(sa.sin_addr, rSocketAddress);
	return nRet;
}
/*
   我们可以通过套接字描述符来获取自己的IP地址和连接对端的IP地址
   如在未调用bind函数的TCP客户端程序上，可以通过调用getsockname()
   函数获取由内核赋予该连接的本地IP地址和本地端口号，还可以在TCP的
   服务器端accept成功后，通过getpeername()函数来获取当前连接的客户
   端的IP地址和端口号。

 */
BOOL CSockZy::GetPeerName(LPTSTR rSocketAddress, UINT & rSocketPort)
{
	sockaddr_in sa = { AF_INET };
	socklen_t nLen = sizeof(sa);
	if (getpeername(m_hSocket, (sockaddr*)&sa, &nLen) < 0)
		return FALSE;
	rSocketPort = htons(sa.sin_port);
	if (rSocketAddress)
		Ntop(sa.sin_addr, rSocketAddress);
	return TRUE;

}

BOOL CSockZy::GetSockName(LPTSTR rSocketAddress, UINT & rSocketPort)
{
	sockaddr_in sa = { AF_INET };
	socklen_t nLen = sizeof(sa);
	if (getsockname(m_hSocket, (sockaddr*)&sa, &nLen) < 0)
		return FALSE;
	rSocketPort = htons(sa.sin_port);
	if (rSocketAddress)
		Ntop(sa.sin_addr, rSocketAddress);
	return TRUE;
}
