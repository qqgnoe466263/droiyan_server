// SessDesc.cpp: implementation of the CSessDesc class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "BadukDir.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSessDesc::CSessDesc()
{
	m_buf = (char*)m_msg.GetBuf ();
	m_nRdCnt = 0;
	m_sockClient = INVALID_SOCKET;
	m_pObject = NULL;
	m_fCheckTimeouts = TRUE;
}

CSessDesc::~CSessDesc()
{
	Close ();
}

BOOL CSessDesc::Create (SOCKET sockListen)
{
	Close ();

	m_sockClient = accept (sockListen, NULL, NULL);
	if (m_sockClient != INVALID_SOCKET)
	{
		m_dwLastTime = GetTickCount ();
		return TRUE;
	}
	return FALSE;
}

void CSessDesc::Close ()
{
	if (m_sockClient != INVALID_SOCKET)
	{
		shutdown (m_sockClient, SD_BOTH);
		closesocket (m_sockClient);
		m_sockClient = INVALID_SOCKET;
	}
	m_nRdCnt = 0;
	m_msg.Clear ();
}

BOOL CSessDesc::Connect (LPCTSTR lpszAddr, int nPort)
{
	Close ();

	m_fCheckTimeouts = FALSE;
	m_sockClient = OpenClient (lpszAddr, nPort);
	return (m_sockClient != INVALID_SOCKET);
}

BOOL CSessDesc::CheckMsg ()
{
	if (m_nRdCnt < 4)
		return FALSE;
	int nSize = m_msg.GetSize ();
	if (DEFAULT_SIZE < nSize)
	{
		m_msg.Clear ();
		m_nRdCnt = 0;
		return FALSE;
	}
	if (m_nRdCnt < nSize)
		return FALSE;
	return TRUE;
}

int CSessDesc::Hear ()
{
	if (m_sockClient == INVALID_SOCKET)
		return ERROR_INVALID;

	int nRecv = recv (m_sockClient, m_buf + m_nRdCnt, 
		DEFAULT_SIZE - m_nRdCnt, 0);
	if (nRecv <= 0)
		return ERROR_CLIENTRECV;
	m_nRdCnt += nRecv;
	return 0;
}

int CSessDesc::Say (CMsg& msg)
{
	if (m_sockClient == INVALID_SOCKET)
		return ERROR_INVALID;

	int nSize = msg.GetSize ();
	char* pBuf = (char*)msg.GetBuf ();

	if (::send (m_sockClient, pBuf, nSize, 0) < 0)
		return ERROR_CLIENTSEND;

	return 0;
}

void CSessDesc::Copy ()
{
	int nSize = m_msg.GetSize ();
	m_msg.Clear ();
	m_nRdCnt -= nSize;
	if (m_nRdCnt)
		memmove (m_buf, m_buf + nSize, m_nRdCnt);
}

