
#include <iostream>
#include <string>

#include "json/json.h"

using namespace std;

int main()
{
	string str_response = R"({
    "blockID": "000000000044cd55d046d7c84623079e490edee05e6825126f7fde25eee40c2f",
    "block_header": {
        "raw_data": {
            "number": 4509013,
            "txTrieRoot": "91a33cec5eb8fadb569b493a1c61e4f61638605b0d91c75ae30cec43d5e0d2c1",
            "witness_address": "41c05142fd1ca1e03688a43585096866ae658f2cb2",
            "parentHash": "000000000044cd54ae9a5b41454584be3962059b678f1f53d47677a34cf898ef",
            "version": 3,
            "timestamp": 1543489869000
        }
	},
	"name": "ljs"
})";
     
	// const char* str = "{\"uploadid\": \"UP000000\",\"code\": 100,\"msg\": \"\",\"files\": \"\"}";
	Json::Reader reader;
	Json::Value root;
	if (reader.parse(str_response.c_str(), root))  // reader将Json字符串解析到root，root将包含Json里所有子元素
	{
		std::string upload_id = root["blockID"].asString();  // 访问节点，upload_id = "UP000000"
		cout << upload_id << endl;
		//string str_header = root["block_header"].;    // 访问节点，code = 100
		//cout << str_header << endl;
		string str_name = root["name"].asString();
		cout << str_name << endl;
	}
	else
		cout << "parse failed." << endl;

	return 0;
}

