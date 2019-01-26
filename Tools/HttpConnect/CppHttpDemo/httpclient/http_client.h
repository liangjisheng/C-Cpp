#pragma once
#include <string>
#include <functional>
#include "../common/mongoose.h"

// �˴�������function�࣬typedef�ٺ��溯��ָ�븳ֵ��Ч
using ReqCallback = std::function<void (std::string)>;

class HttpClient
{
public:
	HttpClient() {}
	~HttpClient() {}

	static void SendReq(const std::string &url, ReqCallback req_callback, const std::string &str_post_data = "");
	static void OnHttpEvent(mg_connection *connection, int event_type, void *event_data);
	static int s_exit_flag;
	static ReqCallback s_req_callback;
};