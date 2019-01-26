
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "json/json.h"

using namespace std;

void t1()
{
	const char* str = "{\"uploadid\": \"UP000000\",\"code\": 100,\"msg\": \"\",\"files\": \"\"}";

	Json::Reader reader;
	Json::Value root;
	// reader将Json字符串解析到root，root将包含Json里所有子元素  
	if (reader.parse(str, root))  
	{
		// 访问节点，upload_id = "UP000000"  
		std::string upload_id = root["uploadid"].asString();
		cout << upload_id << endl;
		// 访问节点，code = 100 
		int code = root["code"].asInt();
		cout << code << endl;
	}
}

void WriterJsonData(const char* filename)
{
	Json::Reader reader;
	// Json::Value是一种很重要的类型，可以代表任意类型。如int, string, object, array
	Json::Value root;

	std::ifstream is;
	is.open(filename, std::ios::binary);
	if (reader.parse(is, root))
	{
		Json::Value arrayObj;
		Json::Value new_item, new_item1;
		new_item["date"] = "2011-11-11";
		new_item1["time"] = "11:11:11";
		arrayObj.append(new_item);	// 插入数组成员
		arrayObj.append(new_item1);
		int file_size = root["files"].size();
		for (int i = 0; i < file_size; ++i)
			root["files"][i]["exifs"] = arrayObj;	// 插入原json中
		std::string out = root.toStyledString();

		// 输出无格式json字符串
		Json::FastWriter writer;
		std::string strWriter = writer.write(root);
		std::ofstream ofs;
		ofs.open("test_write.json");
		ofs << strWriter;
		ofs.close();
	}
}

void marshal()
{
	Json::Value root;
	Json::Value arrayObj;
	Json::Value item;

	for (int i = 0; i < 2; ++i)
	{
		item["key"] = i;
		arrayObj.append(item);
	}

	root["key1"] = "value1";
	root["key2"] = "value2";
	root["array"] = arrayObj;
	std::string out = root.toStyledString();
	cout << out << endl;
}

void unmarshal()
{
	std::string strValue = "{ \"key1\":\"value1\",\"array\":[{\"key2\":\"value2\"},{\"key2\":\"value3\"},{\"key2\":\"value4\"}]}";
	Json::Reader reader;
	Json::Value root;

	if (reader.parse(strValue, root))
	{
		string out = root["key1"].asString();
		cout << out << endl;
		const Json::Value arrayObj = root["array"];
		for (int i = 0; i < arrayObj.size(); ++i)
		{
			out = arrayObj[i]["key2"].asString();
			cout << out;
			if (i != arrayObj.size() - 1)
				cout << endl;
		}
	}
}

void readJson()
{
	Json::Reader *pJsonParser = new Json::Reader(Json::Features::strictMode());
	string strJson = "{\"name\":\"tom\",\"sex\":\"男\",\"age\":\"24\",\"friends\":[{\"name\":\"chen\",\"sex\":\"男\"},{\"name\":\"li\",\"sex\":\"女\"}]}";
	Json::Value tempVal;
	if (!pJsonParser->parse(strJson, tempVal))
	{
		cout << "parse error" << endl;
		return;
	}

	string name = tempVal["name"].asString();
	string sex = tempVal["sex"].asString();
	string age = tempVal["age"].asString();

	Json::Value friends = tempVal["friends"];
	for (int i = 0; i < friends.size(); ++i)
		cout << friends[i]["name"].asString() << endl;

	cout << "name = " << name << 
		"    age = " << age << 
		"    sex = " << sex << endl;

	delete pJsonParser;
}

void writerJson()
{
	Json::Value root;
	Json::FastWriter writer;
	Json::Value person;

	person["name"] = "hello ljs";
	person["age"] = 24;
	root.append(person);
	string json_file = writer.write(root);
	cout << json_file << endl;
}

void test2() {
	Json::Value jRoot;
	jRoot["type"] = 1;

	Json::Value jCreateAccount;
	jCreateAccount["dest_address"] = "123456";
	Json::Value jContract;
	jContract["payload"] = "";
	jCreateAccount["contract"] = jContract;

	jCreateAccount["init_balance"] = 0;
	jCreateAccount["init_input"] = "";

	Json::Value jMetaDatasArray, jItem;
	jItem["key"] = "111";
	jItem["value"] = "hello 111.";
	jItem["version"] = 0;
	jMetaDatasArray.append(jItem);

	jItem["key"] = "222";
	jItem["value"] = "hello 222.";
	jItem["version"] = 0;
	jMetaDatasArray.append(jItem);
	jCreateAccount["metadatas"] = jMetaDatasArray;

	Json::Value jPriv, jThresholds;
	jPriv["master_weight"] = 1;
	jThresholds["tx_threshold"] = 1;
	jPriv["thresholds"] = jThresholds;

	jCreateAccount["priv"] = jPriv;
	jRoot["create_account"] = jCreateAccount;

	std::string str_json = jRoot.toStyledString();
	std::cout << str_json << std::endl;

	vector<string> vec_names = jRoot.getMemberNames();
	for (size_t i = 0; i < vec_names.size(); ++i)
		cout << vec_names[i] << endl;
}


int main()
{
	// t1();
	marshal();
	// unmarshal();
	// readJson();
	// writerJson();
	// test2();

	return 0;
}
