// Socket program Server.cpp
#include"winsock2.h"
#include"stdio.h"
#include"windows.h"
#pragma comment(lib,"WS2_32.lib")	// ��ʾ�����׽��ֿ�

int main()
{
	WSADATA data;			// WSADATA �ṹ�����
	WORD w=MAKEWORD(2,0);	// �汾����
	char sztext[]="Welcome you\r\n";
	::WSAStartup(w,&data);	// ��ʼ���׽��ֿ�
	SOCKET s,s1;			// ���������׽��ֺ������շ��׽���
	s=::socket(AF_INET,SOCK_STREAM,0);	// ����TCP�׽���
	sockaddr_in addr,addr2;		// �׽��ֵ�ַ�ṹ
	int n=sizeof(addr2);		// �׽��ֵ�ַ�ṹ��С
	addr.sin_family=AF_INET;	// ָ����ַ�����ʽΪTCP/IP
	addr.sin_port=htons(75);	// �˿ں���
	addr.sin_addr.S_un.S_addr=INADDR_ANY; // ��ʾ�����������κμ��������������
	::bind(s,(sockaddr*)&addr,sizeof(addr));	// ���׽���
	::listen(s,5);	// �����׽��֣��������Ϊ5
	printf("�������Ѿ�����\r\n");
	while(true) {
		s1=::accept(s,(sockaddr*)&addr2,&n);	// ������������
		if(s1!=NULL) {
			printf("%s�Ѿ�������\r\n",inet_ntoa(addr2.sin_addr));
			::send(s1,sztext,sizeof(sztext),0);	// ��ͻ��˷����ַ�
		}
		::closesocket(s);	// �ر��׽���
		::closesocket(s1);
		::WSACleanup();		// �ͷ��׽��ֿ�
		if(getchar()) return 0;
		else ::Sleep(1000);
	}

	return 0;
}