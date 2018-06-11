#include"winsock2.h"
#include"stdio.h"
#pragma comment(lib,"WS2_32.lib")
#define PROG_NAME "DNS Lookup"
#define PF_INET_LENGTH 4		// 定义INTERNET协议族的地址长度

int PASCAL WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,
				   LPSTR lpszCmdParam,int nCmdShow)
{
	WSADATA wd;
	LPHOSTENT lpHostEnt;		// Intetnet host information structure
	DWORD dwIPAddr;				// IP address as an unsigned long
	LPSTR szIPAddr;			// IP address as a dotted decimal string
	char szHostName[128]="梁基圣";		// HostName

	if(WSAStartup(MAKEWORD(2,0),&wd))
		MessageBox(NULL,"Could not load Windows socket DLL.",PROG_NAME,
					MB_OK | MB_ICONSTOP);
	else {
		lpHostEnt=gethostbyname(szHostName);
		if(!lpHostEnt)
			MessageBox(NULL,"Could not get IP address!",szHostName,
						MB_OK | MB_ICONSTOP);
		else {
			szIPAddr=inet_ntoa(*(LPIN_ADDR)*(lpHostEnt->h_addr_list));
			MessageBox(NULL,szIPAddr,lpHostEnt->h_name,
				MB_OK | MB_ICONINFORMATION);
		}
		// Convert a dotted-decimal string into a 32 bit IP address
		dwIPAddr=inet_addr(szIPAddr);
		if(dwIPAddr==INADDR_NONE)
			MessageBox(NULL,"Invalid Internet address!",szIPAddr,
						MB_OK | MB_ICONSTOP);
		else {
			lpHostEnt=gethostbyaddr((LPSTR)&dwIPAddr,PF_INET_LENGTH,PF_INET);
			if(!lpHostEnt)
				MessageBox(NULL,"Could not get host name!",szIPAddr,
							MB_OK | MB_ICONSTOP);
			else
				MessageBox(NULL,lpHostEnt->h_name,szIPAddr,
							MB_OK | MB_ICONINFORMATION);
		}
	}
	WSACleanup();
	return 0;
}