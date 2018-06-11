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
	SOCKET c;
	sockaddr_in saddr;
	int port;
	char serIP[20]={0};
	char recvbuf[512]={0};
	char sendbuf[512]={0};
	bool consend=true;
	bool conrecv=true;

	saddr.sin_family=AF_INET;
	printf("IP address:");
	scanf("%s",&serIP);
	printf("port number:");
	scanf("%d",&port);
	saddr.sin_port=htons(port);
	// inet_addr() 将点分十进制转换为32位整数
	saddr.sin_addr.S_un.S_addr=inet_addr(serIP);

	c=socket(AF_INET,SOCK_STREAM,0);
	if(c==NULL) {
		perror("create client socket failure\n"); exit(1); 	}
	if(connect(c,(sockaddr*)&saddr,sizeof(saddr))<0) {
		perror("connect s failure\n"); exit(2); 	}
	else {
		printf("The message you send:\n");
		while(consend) {
			scanf("%s",&sendbuf);
			if(strcmp(sendbuf,"end")==0)
				consend=false;
			if(send(c,sendbuf,sizeof(sendbuf),0)<0) {
				perror("send failure\n"); exit(3); 		}
		}

		while(conrecv) {
			if(recv(c,recvbuf,512,0)<0)
				printf("recvive data failure\n");
			else
				printf("server:%s\n",recvbuf);
			if(strcmp(recvbuf,"end")==0)
				conrecv=false;
		}
	}
	closesocket(c);
	::WSACleanup();

	system("pause");
	return 0;
}