// 通信服务器程序
#include"winsock2.h"
#include"stdio.h"
#include"stdlib.h"
#include"windows.h"
#pragma comment(lib,"WS2_32.lib")

int main(int argc,char * argv[]) 
{
	WSADATA data;
	WORD w=MAKEWORD(2,0);
	::WSAStartup(w,&data);		// 初始化套接字库
	SOCKET server,datasock;
	sockaddr_in seraddr;
	sockaddr clientaddr;
	char recvbuf[512]={0};
	char sendbuf[512]={0};
	int len,recvlen=1;

	server=socket(AF_INET,SOCK_STREAM,0);
	if(server==NULL) {
		perror("opening stream socket error\n"); exit(1); 	}
	seraddr.sin_family=AF_INET;
	seraddr.sin_port=htons(2345);
	seraddr.sin_addr.S_un.S_addr=INADDR_ANY;
	if(bind(server,(sockaddr*)&seraddr,sizeof(seraddr))<0) {
		perror("binding stream socket error\n"); exit(2); 	}
	listen(server,5);
	printf("服务器启动,等待客户端的连接......\n");
	len=sizeof(clientaddr);
	while(1) {
		datasock=accept(server,&clientaddr,&len);
		if(datasock==NULL) {
			perror("connect failure\n"); exit(3); 	}
		else {
			printf("connect succeed\n");
			while(recvlen) {
				if((recvlen=recv(datasock,recvbuf,512,0))<0) {
					perror("recvive data failure\n"); exit(4);	}
				else 
					printf("client:%s\n",recvbuf);
			}
			closesocket(datasock);
		}
	}
	closesocket(server);
	::WSACleanup();

	system("pause");
	return 0;
}