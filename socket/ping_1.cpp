
// Ping功能是在ICMP基础上实现的。IP协议并不是一个可靠的协议，它不保证数据被送达，
// 那么，保证数据送达的工作应该由其他的模块来完成。其中一个重要的模块就是ICMP
// (网络控制报文)协议。ICMP主要是用来实现IP系统间传递差错和管理报文，是任何IP实现
// 必须和要求的组成部分。它是TCP/IP协议族的一个子协议，属于网络层协议。ICMP提供一
// 致易懂的出错报告信息。发送的出错报文返回到发送原数据的设备，因为只有发送设备才
// 是出错报文的逻辑接受者。发送设备随后可根据ICMP报文确定发生错误的类型，并确定如何
// 才能更好地重发失败的数据包。当传送IP数据包发生错误－－比如主机不可达，路由不可达等等，
// ICMP协议将会把错误信息封包，然后传送回给主机。给主机一个处理错误的机会，这也就是
// 为什么说建立在IP层以上的协议是可能做到安全的原因

#include <Windows.h>
#include <stdio.h>
#include <string.h>

// 判断数据包是否到达，依次查询了192.168.0.1从到192.168.0.254看是否连通
char YN(int k)
{
	FILE *f;
	char fn[40];
	char ln[80];
	char yn;
	int n;

	yn = 'N';
	sprintf(fn, "D:\\tmp\\ping%d.txt", k);
	f = fopen(fn, "r");

	if (NULL != f)
	{
		n = 0;
		while (1)
		{
			if (NULL == fgets(ln, 80, f))
				break;
			if (strstr(ln, "ms "))
			{
				yn = 'Y';
				break;
			}
			n++;
			if (n >= 4)
				break;
		}
		fclose(f);
	}

	return yn;
}

void main(int argc, char **argv)
{
	char cmdstr[256] = {0};
	int i;
	int ip[3];
	char c;

	if (argv < 0)
	{
USAGE:
		printf("Usage example: \n %s 192.168.0.\nto test 192.168.0.1-254\n", argv[0]);
		return ;
	}

	if (4 == sscanf(argv[1], "%d.%d.%d%c", &ip[0], &ip[1], &ip[2], &c))
	{
		if (0 <= ip[0] && ip[0] <= 255
			&& 0 <= ip[1] && ip[1] <= 255
			&& 0 <= ip[2] && ip[2] <= 255
			&& '.' == c)
		{
			for (i = 1; i < 255; i++)
			{
				sprintf(cmdstr, "cmd /c ping %s%d -n 1 -w 1000 > D:\\tmp\\ping%d.txt", argv[1], i, i);
				WinExec(cmdstr, SW_HIDE);
			}
			Sleep(3000);
			for (i = 1; i < 255; ++i)
				printf("%c %s%d\n", YN(i), argv[1], i);
			//Sleep(3000);
			//WinExec("cmd /c del /q D:\\tmp\\ping*.txt", SW_HIDE);
		}
		else 
			goto USAGE;
	}
	else
		goto USAGE;

	getchar();
}