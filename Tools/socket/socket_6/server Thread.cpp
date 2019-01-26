#include"winsock2.h"
#include"stdio.h"
#include"stdlib.h"
#pragma comment(lib,"WS2_32.lib")

SOCKET c;
DWORD WINAPI ThreadProc1(LPVOID lpParam);

int main()
{
	WSADATA wd;
	SOCKET s;
	sockaddr_in saddr,caddr;
	int IpAddr_len=sizeof(sockaddr);
	::WSAStartup(MAKEWORD(2,0),&wd);

	s=socket(AF_INET,SOCK_STREAM,0);
	saddr.sin_family=AF_INET;
	saddr.sin_addr.S_un.S_addr=htonl(INADDR_ANY);
	saddr.sin_port=htons(8887);
	bind(s,(sockaddr*)&saddr,sizeof(sockaddr));
	listen(s,5);
	printf("服务器已经启动，等待客户端的连接......\n");
	
	c=::accept(s,(sockaddr*)&caddr,&IpAddr_len);
	if(c==INVALID_SOCKET) {
		printf("Invalid_socket --- accept connection abort!\n");
		exit(1);	}
	printf("客户端IP地址为:%s\n",inet_ntoa(caddr.sin_addr));

	// 创建键盘扫描及数据发送线程
	CreateThread(NULL,0,ThreadProc1,NULL,0,NULL);

	// 主线程进入循环接收数据
	while(1) {
		char recvbuf[512];
		int recv_num=0;
		recv_num=recv(c,recvbuf,512,0);
		bool line=(recvbuf[0]=='\0');
		if(recv_num>0 && !line)
			printf("client:%s\n",recvbuf);
	}
	closesocket(c);
	closesocket(s);
	
	system("pause");
	return 0;
}

DWORD WINAPI ThreadProc1(LPVOID lpParam) {
	printf("The data you send to client:\n");
	while(1) {
		char sendbuf[512];
		memset(sendbuf,0,512);
		fflush(stdin);
		gets(sendbuf);
		if(strcmp(sendbuf,"end")==0)
			ExitThread(1);
		//scanf("%s",&sendbuf); // 遇到空格结束
		fflush(stdin);	// 清楚缓冲残留信息
		send(c,sendbuf,strlen(sendbuf)+1,0);
	}
	return 0;
}