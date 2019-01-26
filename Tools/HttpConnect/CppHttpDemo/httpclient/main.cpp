#include <iostream>
#include "http_client.h"

void handle_func_hello(std::string rsp)
{
	// do sth according to rsp
	std::cout << "http rsp hello: " << rsp << std::endl;
}

void handle_fun1(std::string rsp)
{
	// do sth according to rsp
	std::cout << "http rsp fun1: " << rsp << std::endl;
}

void handle_sum(std::string rsp)
{
	// do sth according to rsp
	std::cout << "http rsp sum: " << rsp << std::endl;
}

int main()
{
	// 拼完整url，带参数
	std::string url1 = "http://127.0.0.1:7999/api/hello";
	//url1 = "http://localhost:7999/api/hello";
	//url1 = "http://127.0.0.1:15500/";
	//url1 = "http://localhost:15500/";
	//url1 = "http://github.com";
	//url1 = "http://baidu.com";

	//url1 = "http://seed1.bumo.io:16002/getLedger?with_fee=true";
	url1 = "http://seed1.bumotest.io:26002/getAccount?";
	url1 = "http://seed1.bumo.io:16002/getAccount?";
	std::string str_address = "buQs9npaCq9mNFZG18qu88ZcmXYqd6bqpTU3";	// 只有测试网有
	url1 = url1 + "address=" + str_address;

	std::string str_post_data = "hello";

	HttpClient::SendReq(url1, handle_func_hello);
	std::cout << std::endl;

	/*std::string url2 = "http://127.0.0.1:7999/api/fun1";
	HttpClient::SendReq(url2, handle_fun1);
	std::cout << std::endl;
	
	std::string url3 = "http://127.0.0.1:7999/api/fun2";
	HttpClient::SendReq(url3, [](std::string rsp) { 
		std::cout << "http rsp2: " << rsp << std::endl; 
	});
	std::cout << std::endl;

	std::string str_post_data = "n1=1&n2=2";
	std::string url4 = "http://127.0.0.1:7999/api/sum";
	HttpClient::SendReq(url4, handle_sum, str_post_data);
	std::cout << std::endl;

	str_post_data = "{\"value\":\"bae95aa05a180b0092812df2c1cd33e94936d4ee407cd94753de0abdd54590dd\"}";
	std::string url5 = "54.236.37.243:8090/wallet/gettransactionbyid";
	HttpClient::SendReq(url5, handle_sum, str_post_data);
	std::cout << std::endl;*/

	getchar();
	return 0;
}