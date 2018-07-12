
#pragma once
#include <string>
using std::string;

class HttpConnect
{
public:
	HttpConnect();
	~HttpConnect();
	void socketHttp(string host, string request);
	void postData(string host, string path, string post_content);
	void getData(string host, string path, string get_content);
};