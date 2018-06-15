
#include <WinSock2.h>
#include <stdio.h>
#include "ping.h"

BOOL GetRealIpByDomainName(char *szHost, char szIP[50][100], int *nCount)
{
	WSADATA wsaData;
	HOSTENT *pHostEnt;
	int nAdapter = 0;
	struct sockaddr_in sAddr;

	if (WSAStartup(0x0202, &wsaData))
	{
		printf("gethostbyname error for host\n");
		return FALSE;
	}

	pHostEnt = gethostbyname(szHost);
	if (pHostEnt)
	{
		while (pHostEnt->h_addr_list[nAdapter])
		{
			memcpy(&sAddr.sin_addr.S_un.S_addr, pHostEnt->h_addr_list[nAdapter], pHostEnt->h_length);
			sprintf_s(szIP[nAdapter], "%s", inet_ntoa(sAddr.sin_addr));
			nAdapter++;
		}

		*nCount = nAdapter;
	}
	else
	{
		DWORD dwError = GetLastError();
		*nCount = 0;
	}

	WSACleanup();
	return TRUE;
}

// ip����洢���ַ�����ʽ�ĵ��ʮ����IP��ַ
void pingIP(char ip[100])
{
	CPing objPing;
	PingReply reply;

	printf("Pinging %s with %d bytes of data:\n", ip, DEF_PACKET_SIZE);
	for (int i = 0; i < 4; ++i)
	{
		objPing.Ping(ip, &reply);
		printf("Reply from %s: bytes = %d time = %ld ms TTL = %ld\n", 
			ip, reply.m_dwBytes, reply.m_dwRoundTripTime, reply.m_dwTTL);
		Sleep(500);
	}
}

int main()
{
	// char *szDestIP = "127.0.0.1";
	// char *szDestIP = "192.168.0.116";
	//char *szDestIP = "119.75.216.20";			// www.baidu.com
	char *szDestIP = "119.75.213.61";			// www.baidu.com
	pingIP(szDestIP);

	int nIpCount = 0;
	char szIpList[50][100];
	char szDamain[256] = {0};
	char szIp[1024] = {0};
	strcpy_s(szDamain, "www.baidu.com");
	GetRealIpByDomainName(szDamain, szIpList, &nIpCount);

	printf("����: %s\n", szDamain);
	for (int i = 0; i < nIpCount; ++i)
	{
		pingIP(szIpList[i]);
		strcat_s(szIp, szIpList[i]);
		strcat_s(szIp, "\t");
	}
	printf("\n��������IP�б�: %s\n\n", szIp);

	printf("over\n");
	getchar();
	return 0;
}