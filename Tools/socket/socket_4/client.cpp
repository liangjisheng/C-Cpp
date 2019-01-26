#include"winsock2.h"
#include"stdio.h"
#include"stdlib.h"
#include"windows.h"
#pragma comment(lib,"WS2_32.lib")

int main()
{
	WSADATA data;
	WORD w=MAKEWORD(2,0);
	::WSAStartup(w,&data);
	SOCKET server;
	sockaddr_in seraddr;
	int port;
	char serIP[20]={0};
	char recvbuf[512]={0};
	char sendbuf[512]={0};
	bool consend=true;
	seraddr.sin_family=AF_INET;
	printf("IP address:");
	scanf("%s",&serIP);
	printf("port number:");
	scanf("%d",&port);
	seraddr.sin_port=htons(port);
	// inet_addr() 将点分十进制转换为32位整数
	seraddr.sin_addr.S_un.S_addr=inet_addr(serIP);

	server=socket(AF_INET,SOCK_STREAM,0);
	if(server==NULL) {
		perror("create client socket failure\n"); exit(1); 	}
	if(connect(server,(sockaddr*)&seraddr,sizeof(seraddr))<0) {
		perror("connect server failure\n"); exit(2); 	}
	else {
		printf("The message you send:\n");
		while(consend) {
			scanf("%s",&sendbuf);
			if(sendbuf=="quit")
				consend=false;
			if(send(server,sendbuf,sizeof(sendbuf),0)<0) {
				perror("send failure\n"); exit(3); 		}
		}
	}
	closesocket(server);
	::WSACleanup();

	system("pause");
	return 0;
}