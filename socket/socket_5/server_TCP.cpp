// Socket program Server.cpp
#include"winsock2.h"
#include"stdio.h"
#include"windows.h"
#pragma comment(lib,"WS2_32.lib")	// 显示连接套接字库

int main()
{
	WSADATA data;			// WSADATA 结构体对象
	WORD w=MAKEWORD(2,0);	// 版本号码
	char sztext[]="Welcome you\r\n";
	::WSAStartup(w,&data);	// 初始化套接字库
	SOCKET s,s1;			// 定义连接套接字和数据收发套接字
	s=::socket(AF_INET,SOCK_STREAM,0);	// 创建TCP套接字
	sockaddr_in addr,addr2;		// 套接字地址结构
	int n=sizeof(addr2);		// 套接字地址结构大小
	addr.sin_family=AF_INET;	// 指定地址家族格式为TCP/IP
	addr.sin_port=htons(75);	// 端口号码
	addr.sin_addr.S_un.S_addr=INADDR_ANY; // 表示服务器接收任何计算机发来的请求
	::bind(s,(sockaddr*)&addr,sizeof(addr));	// 绑定套接字
	::listen(s,5);	// 监听套接字，最大数量为5
	printf("服务器已经启动\r\n");
	while(true) {
		s1=::accept(s,(sockaddr*)&addr2,&n);	// 接收连接请求
		if(s1!=NULL) {
			printf("%s已经连接上\r\n",inet_ntoa(addr2.sin_addr));
			::send(s1,sztext,sizeof(sztext),0);	// 向客户端发送字符
		}
		::closesocket(s);	// 关闭套接字
		::closesocket(s1);
		::WSACleanup();		// 释放套接字库
		if(getchar()) return 0;
		else ::Sleep(1000);
	}

	return 0;
}