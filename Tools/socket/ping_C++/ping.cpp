
#include "ping.h"
#include <iostream>

USHORT CPing::s_usPacketSeq = 0;

CPing::CPing() : m_szICMPData(NULL), m_bIsInitSucc(FALSE)
{
	WSADATA WSAData;
	// WSAStartup(MAKEWORD(2, 2), &WSAData);
	if (WSAStartup(MAKEWORD(1, 1), &WSAData) != 0)
	{
		// �����ʼ�����ɹ��򱨴�GetLastError()���ط����Ĵ�����Ϣ
		printf("WSAStartup() failed: %d\n", GetLastError());
		return ;
	}

	m_event = WSACreateEvent();
	m_usCurrentProcID = (USHORT)GetCurrentProcessId();
	//setsockopt(m_sockRaw);
    /*if ((m_sockRaw = WSASocket(AF_INET, SOCK_RAW, IPPROTO_ICMP, NULL, 0, 0)) != SOCKET_ERROR)
    {
        WSAEventSelect(m_sockRaw, m_event, FD_READ);
        m_bIsInitSucc = TRUE;

        m_szICMPData = (char*)malloc(DEF_PACKET_SIZE + sizeof(ICMPHeader));

        if (m_szICMPData == NULL)
        {
            m_bIsInitSucc = FALSE;
        }
    }*/
	m_sockRaw = WSASocket(AF_INET, SOCK_RAW, IPPROTO_ICMP, NULL, 0, 0);
	if (m_sockRaw == INVALID_SOCKET)
		//10013 ��һ�ַ���Ȩ�޲�����ķ�ʽ����һ�������׽��ֵĳ���
		std::cerr << "WSASocket() failed: " << WSAGetLastError() << std::endl;
	else
	{
		WSAEventSelect(m_sockRaw, m_event, FD_READ);
		m_bIsInitSucc = TRUE;

		m_szICMPData = (char *)malloc(DEF_PACKET_SIZE + sizeof(ICMPHeader));
		if (NULL == m_szICMPData)
			m_bIsInitSucc = FALSE;
	}
}

CPing::~CPing()
{
	WSACleanup();
	if (m_szICMPData)
	{
		free(m_szICMPData);
		m_szICMPData = NULL;
	}
}

BOOL CPing::Ping(DWORD dwDestIP, PingReply *pPingReply /* = NULL */, DWORD dwTimeOut /* = 2000 */)
{
	return PingCore(dwDestIP, pPingReply, dwTimeOut);
}

BOOL CPing::Ping(char *szDestIP, PingReply *pPingReply /* = NULL */, DWORD dwTimeOut /* = 2000 */)
{
	if (szDestIP)
		// inet_addr()����������Ϊ��Ӧ�ĵ��ʮ����
		return PingCore(inet_addr(szDestIP), pPingReply, dwTimeOut);
	return FALSE;
}

BOOL CPing::PingCore(DWORD dwDestIP, PingReply *pPingReply, DWORD dwTimeOut)
{
	if (!m_bIsInitSucc)
		return FALSE;

	// ����SOCKET
	sockaddr_in sockaddrDest;
	sockaddrDest.sin_family = AF_INET;
	sockaddrDest.sin_addr.S_un.S_addr = dwDestIP;
	int nSockaddrDestSize = sizeof(sockaddrDest);

	// ����ICMP��
	int nICMPDataSize = DEF_PACKET_SIZE + sizeof(ICMPHeader);
	ULONG ulSendTimestamp = GetTickCountCalibrate();
	USHORT usSeq = ++s_usPacketSeq;
	memset(m_szICMPData, 0, nICMPDataSize);
	ICMPHeader *pICMPHeader = (ICMPHeader *)m_szICMPData;
	pICMPHeader->m_byType = ECHO_REQUEST;
	pICMPHeader->m_byCode = 0;
	pICMPHeader->m_usID = m_usCurrentProcID;
	pICMPHeader->m_usSeq = usSeq;
	pICMPHeader->m_ulTimeStamp = ulSendTimestamp;
	pICMPHeader->m_usChecksum = CalCheckSum((USHORT *)m_szICMPData, nICMPDataSize);

	// ����ICMP����
	if (sendto(m_sockRaw, m_szICMPData, nICMPDataSize, 0, 
		(struct sockaddr *)&sockaddrDest, nSockaddrDestSize) == SOCKET_ERROR)
	{
		return FALSE;
	}

	// �ж��Ƿ���Ҫ������Ӧ����
	if (pPingReply == NULL)
		return TRUE;

	char recvbuf[256] = {0};
	while (TRUE)
	{
		// ������Ӧ����
		if (WSAWaitForMultipleEvents(1, &m_event, FALSE, 100 ,FALSE) != WSA_WAIT_TIMEOUT)
		{
			WSANETWORKEVENTS netEvent;
			WSAEnumNetworkEvents(m_sockRaw, m_event, &netEvent);

			if (netEvent.lNetworkEvents & FD_READ)
			{
				ULONG nRecvTimestamp = GetTickCountCalibrate();
				int nPacketSize = recvfrom(m_sockRaw, recvbuf, 256, 0, (struct sockaddr *)&sockaddrDest, &nSockaddrDestSize);
				if (nPacketSize != SOCKET_ERROR)
				{
					IPHeader *pIPHeader = (IPHeader *)recvbuf;
					USHORT usIPHeaderLen = (USHORT)((pIPHeader->m_byVerHLen & 0x0f) * 4);
					ICMPHeader *pICMPHeader = (ICMPHeader *)(recvbuf + usIPHeaderLen);

					if (pICMPHeader->m_usID == m_usCurrentProcID	// �ǵ�ǰ���̷����ı���
						&& pICMPHeader->m_byType == ECHO_REPLY		// ��ICMP��Ӧ����
						&& pICMPHeader->m_usSeq == usSeq)			// �Ǳ��������ĵ���Ӧ����
					{
						pPingReply->m_usSeq = usSeq;
						pPingReply->m_dwRoundTripTime = nRecvTimestamp - pICMPHeader->m_ulTimeStamp;
						pPingReply->m_dwBytes = nPacketSize - usIPHeaderLen - sizeof(ICMPHeader);
						pPingReply->m_dwTTL = pIPHeader->m_byTTL;
						return TRUE;
					}
				}
			}
		}

		// ��ʱ
		if (GetTickCountCalibrate() - ulSendTimestamp >= dwTimeOut)
			return FALSE;
	}
}

USHORT CPing::CalCheckSum(USHORT *pBuffer, int nSize)
{
	unsigned long ulCheckSum = 0;
	while (nSize > 1)
	{
		ulCheckSum += *pBuffer++;
		nSize -= sizeof(USHORT);
	}

	if (nSize)
		ulCheckSum += *(UCHAR*)pBuffer;

	ulCheckSum = (ulCheckSum >> 16) + (ulCheckSum & 0xffff);
	ulCheckSum += (ulCheckSum >> 16);

	return (USHORT)(~ulCheckSum);
}

ULONG CPing::GetTickCountCalibrate()
{
	static ULONG s_ulFirstCallTick = 0;
	static LONGLONG s_ullFirstCallTickMS = 0;

	SYSTEMTIME systemtime;
	FILETIME filetime;
	GetLocalTime(&systemtime);
	SystemTimeToFileTime(&systemtime, &filetime);
	LARGE_INTEGER liCurrentTime;
	liCurrentTime.HighPart = filetime.dwHighDateTime;
	liCurrentTime.LowPart = filetime.dwLowDateTime;
	LONGLONG llCurrentTimeMS = liCurrentTime.QuadPart / 10000;

	if (s_ulFirstCallTick == 0)
		s_ulFirstCallTick = GetTickCount();
	if (s_ullFirstCallTickMS == 0)
		s_ullFirstCallTickMS = llCurrentTimeMS;

	return s_ulFirstCallTick + (ULONG)(llCurrentTimeMS - s_ullFirstCallTickMS);
}