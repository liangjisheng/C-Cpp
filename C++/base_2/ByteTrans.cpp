
// 输入一个数代表多少字节，输出其对应的GBytes/Mbytes/Kbytes/Bytes。

#include <iostream>

using namespace std;

const long GBYTES = 1024 * 1024 * 1024;
const long MBYTES = 1024 * 1024;
const long KBYTES = 1024;


void ByteTrans(long lByteVal)
{
	if(lByteVal < KBYTES)
	{
		cout << lByteVal << " Bytes" << endl;
	}
	else if(lByteVal >= KBYTES && lByteVal < MBYTES)
	{
		cout << lByteVal / KBYTES << " KBytes " 
			<< lByteVal % KBYTES << " Bytes" << endl;
	}
	else if(lByteVal >= MBYTES && lByteVal < GBYTES)
	{
		long lBytes = lByteVal % MBYTES;
		cout << lByteVal / MBYTES << " MBytes "
			<< lBytes / KBYTES << " KBytes "
			<< lBytes % KBYTES << " Bytes" << endl;
	}
	else if(lByteVal >= GBYTES)
	{
		long lBytes_1 = lByteVal % GBYTES;
		long lBytes_2 = lBytes_1 % MBYTES;
		cout << lByteVal / GBYTES << " GBytes "
			<< lBytes_1 / MBYTES << " MBytes "
			<< lBytes_2 / KBYTES << " KBytes "
			<< lBytes_2 % KBYTES << " Bytes" << endl;
	}
}


int main()
{
	long lBytes_1 = 512;
	long lBytes_2 = 1024;
	long lBytes_3 = 1024 + 512;
	long lBytes_4 = 1024 * 1024;
	long lBytes_5 = 1024 * 1024 + 2 * 1024 + 512;
	long lBytes_6 = 1024 * 1024 * 1024;
	long lBytes_7 = 1024 * 1024 * 1024 + 200 * 1024 * 1024 + 200 * 1024 + 512;

	// ByteTrans(lBytes_1);
	// ByteTrans(lBytes_2);
	// ByteTrans(lBytes_3);
	// ByteTrans(lBytes_4);
	// ByteTrans(lBytes_5);
	// ByteTrans(lBytes_6);
	// ByteTrans(lBytes_7);

	system("pause");
	return 0;
}


