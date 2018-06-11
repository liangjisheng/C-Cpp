// UDP client.cpp
#include"winsock2.h"
#include"stdio.h"
#include"windows.h"
#pragma comment(lib,"WS2_32.lib")

int main()
{
	WSADATA data;
	WORD w=MAKEWORD(2,0);
	::WSAStartup(w,&data);
	SOCKET s;
	s=::socket(AF_INET,SOCK_DGRAM,0);
	sockaddr_in addr,addr2;
	int n=sizeof(addr2);
	char buffer[20]={0};
	char sztext[20];
	addr.sin_family=AF_INET;
	addr.sin_port=htons(75);
	addr.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");
	printf("UDP客户端已经启动\r\n");
	if(::sendto(s,sztext,sizeof(sztext),0,(sockaddr*)&addr,n)!=0) {
		::recvfrom(s,buffer,20,0,(sockaddr*)&addr2,&n);
		printf("%s\r\n",buffer);
		::closesocket(s);
		::WSACleanup();
	}
	if(getchar()) return 0;
	else ::Sleep(1000);

	return 0;
}