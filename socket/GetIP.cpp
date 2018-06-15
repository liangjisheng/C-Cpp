
// ��cmd�����У�ͨ��ping���Եõ�һ��������Ӧ��ʵ��IP��ַ������ͨ��������ʵ��
// �����ܹ�����������Ӧ��ȫ��IP��ַ
#include <WinSock2.h>
// #include <Windows.h>
#include <iostream>

#pragma comment(lib, "WS2_32")

using std::cout;
using std::endl;

BOOL GetRealIpByDomainName(char *szHost, char szIP[50][100], int *nCount)
{
	WSADATA wsaData;
	HOSTENT *pHostEnt;
	int nAdapter = 0;
	struct sockaddr_in sAddr;

	if (WSAStartup(0x0202, &wsaData))
	{
		cout << "gethostbyname error for host\n";
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

int main()
{
	int nIpCount = 0;				// ����������Ӧʵ��IP�ĸ���
	char szIpList[50][100];			// ����������Ӧʵ��IP�б�
	char szDomain[256] = {0};		// ����
	char szIp[1024] = {0};
	strcpy_s(szDomain, "www.baidu.com");
	GetRealIpByDomainName(szDomain, szIpList, &nIpCount);

	for (int i = 0; i < nIpCount; ++i)
	{
		strcat_s(szIp, szIpList[i]);
		strcat_s(szIp, "\t");
	}

	printf("DomainName: %s\n", szDomain);
	printf("Real IPList: %s\n", szIp);

	system("pause");
	return 0;
}