
#include <iostream>
#include <string>
#include <string.h>

#include "userInfo.pb.h"
#include "base16.h"

using namespace std;


int main()
{
	pt::userInfo test;
	test.set_name("ljs");
	// test.set_age(500);

	unsigned char sz_seria[1024] = { 0 };
	bool ok = test.SerializeToArray(sz_seria, size((sz_seria)));
	if (ok)
	{
		string str_encode;
		encode_base16(str_encode, sz_seria, strlen((char *)sz_seria));
		cout << str_encode << endl;
	}
	else
		cout << "SerializeToArray failed." << endl;

	getchar();
	return 0;
}