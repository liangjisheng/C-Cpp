
// Ping��������ICMP������ʵ�ֵġ�IPЭ�鲢����һ���ɿ���Э�飬������֤���ݱ��ʹ
// ��ô����֤�����ʹ�Ĺ���Ӧ����������ģ������ɡ�����һ����Ҫ��ģ�����ICMP
// (������Ʊ���)Э�顣ICMP��Ҫ������ʵ��IPϵͳ�䴫�ݲ��͹����ģ����κ�IPʵ��
// �����Ҫ�����ɲ��֡�����TCP/IPЭ�����һ����Э�飬���������Э�顣ICMP�ṩһ
// ���׶��ĳ�������Ϣ�����͵ĳ����ķ��ص�����ԭ���ݵ��豸����Ϊֻ�з����豸��
// �ǳ����ĵ��߼������ߡ������豸���ɸ���ICMP����ȷ��������������ͣ���ȷ�����
// ���ܸ��õ��ط�ʧ�ܵ����ݰ���������IP���ݰ��������󣭣������������ɴ·�ɲ��ɴ�ȵȣ�
// ICMPЭ�齫��Ѵ�����Ϣ�����Ȼ���ͻظ�������������һ���������Ļ��ᣬ��Ҳ����
// Ϊʲô˵������IP�����ϵ�Э���ǿ���������ȫ��ԭ��

#include <Windows.h>
#include <stdio.h>
#include <string.h>

// �ж����ݰ��Ƿ񵽴���β�ѯ��192.168.0.1�ӵ�192.168.0.254���Ƿ���ͨ
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