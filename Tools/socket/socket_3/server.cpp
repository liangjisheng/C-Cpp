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
	SOCKET s,c;
	sockaddr_in seraddr;
	sockaddr clientaddr;
	char recvbuf[512]={0};
	char sendbuf[512]={0};
	int len,recvlen=1;
	bool conrecv=true;
	bool consend=true;

	s=socket(AF_INET,SOCK_STREAM,0);
	if(s==NULL) {
		perror("opening stream socket error\n"); exit(1); 	}
	seraddr.sin_family=AF_INET;
	seraddr.sin_port=htons(2345);
	seraddr.sin_addr.S_un.S_addr=INADDR_ANY;

	if(bind(s,(sockaddr*)&seraddr,sizeof(seraddr))<0) {
		perror("binding stream socket error\n"); exit(2); 	}
	listen(s,5);

	printf("服务器启动,等待客户端的连接......\n");
	len=sizeof(clientaddr);
	while(1) {
		c=accept(s,&clientaddr,&len);
		if(c==NULL) {
			perror("connect failure\n"); exit(3); 	}
		else {
			printf("connect succeed\n");
			while(conrecv) {
				if((recvlen=recv(c,recvbuf,512,0))<0) {
					perror("recvive data failure\n"); exit(4);	}
				else 
					printf("client:%s\n",recvbuf);
				if(strcmp(recvbuf,"end")==0)
					conrecv=false;
			}

			printf("send data to client:\n");
			while(consend) {
				scanf("%s",&sendbuf);
				if(strcmp(sendbuf,"end")==0)
					consend=false;
				if(send(c,sendbuf,512,0)<0)
					printf("send failure\n");
			}
			closesocket(c);
		}
	}
	closesocket(s);
	::WSACleanup();

	system("pause");
	return 0;
}