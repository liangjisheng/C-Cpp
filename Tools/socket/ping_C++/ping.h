
/**
 * C++ʵ��ping����
 * 1.��������ΪSOCK_RAW��һ���׽��֣�ͬʱ�趨Э��ΪIPPROTO_ICMP
 * 2.��������ʼ��ICMPͷ
 * 3.����sendto��WSASendto����ICMP���󷢸�Զ������
 * 4.����recvfrom��WSARecvfrom���Խ����κ�ICMP��Ӧ
*/

// ��Ĭ��windows.h�����winsock.h���������winsock2.h�ͻ��ͻ������ڰ���windows.hǰ��Ҫ����һ����
// #define WIN32_LEAN_AND_MEAN ;ȥ��winsock.h
// Ҫô��#include <winsock2.h>����#include<windows.h>ǰ�����ֱ��ȥ��#include<windows.h>

#ifndef _MY_PING_H_
#define _MY_PING_H_

#include <WinSock2.h>
#pragma comment(lib, "WS2_32")

#define DEF_PACKET_SIZE 32
#define ECHO_REQUEST 8
#define ECHO_REPLY 0

struct IPHeader
{
	BYTE m_byVerHLen;				// 4λ�汾+4λ�ײ�ͷ��
	BYTE m_byTOS;					// ��������
	USHORT m_usTotalLen;			// �ܳ���
	USHORT m_usID;					// ��ʶ
	USHORT m_usFlagFragOffset;		// 3λ��־+13λƬƫ��
	BYTE m_byTTL;					// Time to Live����ʱ��
	BYTE m_byProtocol;				// Э��
	USHORT m_usHChecksum;			// �ײ�У���
	ULONG m_ulSrcIP;				// ԴIP��ַ
	ULONG m_ulDestIP;				// Ŀ��IP��ַ
};

struct ICMPHeader
{
	BYTE m_byType;					// ����
	BYTE m_byCode;					// ����
	USHORT m_usChecksum;			// У���
	USHORT m_usID;					// ��ʶ��
	USHORT m_usSeq;					// ���
	ULONG m_ulTimeStamp;			// ʱ���(�Ǳ�׼ICMPͷ��)
};

struct PingReply
{
	USHORT m_usSeq;
	DWORD m_dwRoundTripTime;
	DWORD m_dwBytes;
	DWORD m_dwTTL;

	PingReply()
	{
		m_usSeq = 0;
		m_dwRoundTripTime = 0;
		m_dwBytes = 0;
		m_dwTTL = 0;
	}
};

class CPing
{
public:
	CPing();
	~CPing();
	BOOL Ping(DWORD dwDestIP, PingReply *pPingReply = NULL, DWORD dwTimeOut = 2000);
	BOOL Ping(char *szDestIP, PingReply *pPingReply = NULL, DWORD dwTimeOut = 2000);
private:
	BOOL PingCore(DWORD dwDestIP, PingReply *pPingReply, DWORD dwTimeOut);
	USHORT CalCheckSum(USHORT *pBuffer, int nSize);
	ULONG GetTickCountCalibrate();
private:
	SOCKET m_sockRaw;
	WSAEVENT m_event;
	USHORT m_usCurrentProcID;
	char *m_szICMPData;
	BOOL m_bIsInitSucc;
private:
	static USHORT s_usPacketSeq;
};

#endif // _MY_PING_H_