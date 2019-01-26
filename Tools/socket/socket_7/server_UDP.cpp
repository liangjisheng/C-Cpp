// UDP server.cpp 
#include"winsock2.h"
#include"stdio.h"
#include"windows.h"
#pragma comment(lib,"WS2_32.lib")

int main()
{
	WSADATA data;
	WORD w=MAKEWORD(2,0);
	char sztext[]="Welcome you.\r\n";
	::WSAStartup(w,&data);
	SOCKET s;
	s=::socket(AF_INET,SOCK_DGRAM,0);
	sockaddr_in addr,addr2;
	int n=sizeof(addr2);
	char buffer[20]={0};
	addr.sin_family=AF_INET;
	addr.sin_port=htons(75);
	addr.sin_addr.S_un.S_addr=INADDR_ANY;
	::bind(s,(sockaddr*)&addr,sizeof(addr));
	printf("UDP服务器以启动\r\n");
	if(::recvfrom(s,buffer,20,0,(sockaddr*)&addr2,&n)!=-1) {
		printf("%s已经连接上\r\n",inet_ntoa(addr2.sin_addr));
		::sendto(s,sztext,sizeof(sztext),0,(sockaddr*)&addr2,n);	// 发送到客户端
		::closesocket(s);
		::WSACleanup();
	}
	if(getchar()) return 0;
	else ::Sleep(1000);

	return 0;
}