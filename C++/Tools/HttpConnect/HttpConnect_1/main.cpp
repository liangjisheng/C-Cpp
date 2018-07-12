
#include <iostream>
#include "HttpConnect.h"

int main()
{
	HttpConnect *http = new HttpConnect();
	// http->getData("127.0.0.1", "/login", "id=Administrator&pw=\"\"");
	http->postData("http://192.168.0.116/upImg/upimg", "/login","id=Administrator&pw=123");

	system("pause");
	return 0;
}