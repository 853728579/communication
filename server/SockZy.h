#pragma once

#ifndef _WIN32

#define INVALID_SOCKET  (SOCKET)(~0)
#define SOCKET_ERROR            (-1)

#ifndef _T
#define _T(x) x
#endif /*#ifndef _T*/

inline int GetLastError()
{
	return errno;
}
#define closesocket(x) close(x)

#endif


//MFC中已有CScoket，不太支持控制台，不支持多线程
class CSockZy
{
protected:
	SOCKET m_hSocket;//核心成员变量
public:
	operator SOCKET() const
	{
		return m_hSocket;
	}
	BOOL Create(UINT nSocketPort = 0, int nSocketType = SOCK_STREAM
		, LPCTSTR lpszSocketAddress = NULL);

	BOOL Accept(CSockZy& rConnectedSocket, LPTSTR szIP = NULL, UINT *nPort = NULL);
	BOOL Connect(LPCTSTR lpszHostAddress, UINT nHostPort);
	BOOL Listen(int nConnectionBacklog = 5)
	{
		return !listen(m_hSocket, nConnectionBacklog);
	}
	int SendTo(const void* lpBuf, int nBufLen, UINT nHostPort, LPCTSTR lpszHostAddress = NULL, int nFlags = 0);

	int ReceiveFrom(void* lpBuf, int nBufLen, LPTSTR rSocketAddress, UINT& rSocketPort, int nFlags = 0);

	int Send(const void* lpBuf, int nBufLen, int nFlags = 0)
	{
		return send(m_hSocket, (LPCSTR)lpBuf, nBufLen, nFlags);
	}
	int Receive(void* lpBuf, int nBufLen, int nFlags = 0)
	{
		return recv(m_hSocket, (LPSTR)lpBuf, nBufLen, nFlags);
	}
	BOOL GetPeerName(LPTSTR rSocketAddress, UINT& rSocketPort);
	BOOL GetSockName(LPTSTR rSocketAddress, UINT& rSocketPort);

	void Close()
	{
		closesocket(m_hSocket);
		m_hSocket = INVALID_SOCKET;
	}

#ifdef _UNICODE
	inline static void Pton(LPCTSTR sHostAddr, IN_ADDR &in)
	{
			in.s_addr = inet_addr(_bstr_t(sHostAddr));
	}
	inline static void Ntop(IN_ADDR &in, LPTSTR sHostAddr)
	{
		_tcscpy(sHostAddr, _bstr_t(inet_ntoa(in)));
	}

#else
	inline static void Pton(LPCTSTR sHostAddr, IN_ADDR &in)
	{
		in.s_addr = inet_addr(sHostAddr);
	}
	inline static void Ntop(IN_ADDR &in, LPTSTR sHostAddr)
	{
		strcpy(sHostAddr, inet_ntoa(in));
	}
#endif

	CSockZy();
	virtual ~CSockZy();
};
