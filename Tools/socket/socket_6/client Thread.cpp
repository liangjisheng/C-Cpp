#include"winsock2.h"
#include"stdio.h"
#include"stdlib.h"
#pragma comment(lib,"WS2_32.lib")

SOCKET c;
DWORD WINAPI ThreadProc1(LPVOID lpParam) {
	printf("The data you send to server:\n");
	while(1) {
		char sendbuf[512];
		memset(sendbuf,0,512);
		fflush(stdin);
		gets(sendbuf);	// 读取一行，遇到换行或回车结束
		if(strcmp(sendbuf,"end")==0)
			ExitThread(1);
		//scanf("%s",&sendbuf); // 遇到空格结束
		fflush(stdin);	 // 清楚缓冲区残留信息
		send(c,sendbuf,strlen(sendbuf)+1,0);
	}
	return 0;
}

int main()
{
	WSADATA wd;
	sockaddr_in caddr;
	char strIP[20]="";
	char recvbuf[512]="";
	::WSAStartup(MAKEWORD(2,0),&wd);

	c=socket(AF_INET,SOCK_STREAM,0);
	caddr.sin_family=AF_INET;
	caddr.sin_port=htons(8887);
	printf("IP address:");
	scanf("%s",&strIP);
	caddr.sin_addr.S_un.S_addr=inet_addr(strIP);

	if(connect(c,(sockaddr*)&caddr,sizeof(sockaddr))!=0) {
		printf("connect failure\n"); exit(1); 	}
	//Sleep(1000);
	//if(recv(c,recvbuf,512,0)>0)
	//	printf("server:%s\n",recvbuf);
	//else exit(2);

	CreateThread(NULL,0,ThreadProc1,NULL,0,NULL);

	while(1) {
		int recv_num=0;
		recv_num=recv(c,recvbuf,512,0);
		bool line=(recvbuf[0]=='\0');
		if(recv_num>0 && !line)
			printf("server:%s\n",recvbuf);
	}
	closesocket(c);

	system("pause");
	return 0;
}