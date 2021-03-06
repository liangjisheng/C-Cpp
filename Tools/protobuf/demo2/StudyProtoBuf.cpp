#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <fcntl.h>
#include <vector>

#ifdef WIN32
#include <io.h>
#else
#include <unistd>
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/util/json_util.h>

#include "game.pb.h"
#include "hello.pb.h"
#include "base16.h"

using namespace std;

void test_game_pb_1(pt::rsp_login &rsp)
{
	std::string buff{};
	rsp.SerializeToString(&buff);
	//------------------解析----------------------
	pt::rsp_login rsp2{};
	if (!rsp2.ParseFromString(buff)) {
		std::cout << "parse error\n";
		return;
	}

	const pt::obj_user_info temp_user_info = rsp2.user_info();
	std::cout << "nickname:" << temp_user_info.nickname() << std::endl;
	std::cout << "coin:" << temp_user_info.coin() << std::endl;
	for (int m = 0; m < rsp2.record_size(); m++) {
		const pt::obj_user_game_record temp_record = rsp2.record(m);
		std::cout << "time:" << temp_record.time() << " kill:" << temp_record.kill() << " dead:" << temp_record.dead() << " assist:" << temp_record.assist() << std::endl;
	}
}

void serializeToString(pt::rsp_login &rsp)
{
	std::string str, str_base16;
	rsp.SerializeToString(&str);
	encode_base16(str_base16, str);
	cout << "parse from string size:" << str_base16 << endl;

	pt::rsp_login rsp2;
	rsp2.ParseFromString(str);
	cout << "parse from string size:" << rsp2.ByteSize() << endl;

	string str1 = rsp.SerializeAsString();
	string str1_bas16;
	encode_base16(str1_bas16, str1);
	cout << "serialize as string:" << str1_bas16 << endl;
}

void serializeToArray(pt::rsp_login& rsp)
{
	vector<uint8_t> buff;
	buff.resize(rsp.ByteSize());
	rsp.SerializeToArray(buff.data(), buff.size());

	pt::rsp_login rsp2{};
	if (!rsp2.ParseFromArray(buff.data(), (int)(buff.size())))
	{
		std::cout << "parse error\n";
		return;
	}

	std::cout << "parse from array size:" << rsp2.ByteSize() << std::endl;
}

void serializeToCodeStream(pt::rsp_login& rsp)
{
	using namespace google::protobuf::io;
	int fd1 = open("myfile", O_CREAT | O_RDWR);
	if (-1 == fd1)
		return;

	ZeroCopyOutputStream *raw_output = new FileOutputStream(fd1);
	google::protobuf::io::CodedOutputStream coded_output(raw_output);
	rsp.SerializeToCodedStream(&coded_output);
	delete raw_output;
	close(fd1);

	pt::reg_login rsp2{};
	int fd2 = open("myfile", O_RDONLY);
	if (-1 == fd2)
		return;

	ZeroCopyInputStream *raw_input = new FileInputStream(fd2);
	google::protobuf::io::CodedInputStream coded_input(raw_input);
	// rsp2.ParseFromCodedStream(&coded_input);
	// cout << rsp2.ByteSize() << endl;	// 34 error
	delete raw_input;
	close(fd2);
}

void test_game()
{
	pt::rsp_login rsp{};
	rsp.set_ret(pt::rsp_login_RET_SUCCESS);
	pt::obj_user_info *user_info = rsp.mutable_user_info();
	user_info->set_nickname("dsw");
	user_info->set_icon("345DS55GF34D774S");
	user_info->set_coin(2000);
	user_info->set_location("zh");

	for (int i = 0; i < 5; i++) {
		pt::obj_user_game_record* record = rsp.add_record();
		record->set_time("2017/4/13 12:22:11");
		record->set_kill(i * 4);
		record->set_dead(i * 2);
		record->set_assist(i * 5);
	}

	// test_game_pb_1(rsp);
	// serializeToString(rsp);
	// serializeToArray(rsp);
	// serializeToCodeStream(rsp);
}

void list_hello(const helloworld &msg)
{
	cout << msg.id() << endl;
	cout << msg.str() << endl;
}

int write_hello()
{
	helloworld msg1;
	msg1.set_id(101);
	msg1.set_str("hello");

	fstream output("./log", ios::out | ios::trunc | ios::binary);
	if (!msg1.SerializePartialToOstream(&output))
	{
		cerr << "Failed to write msg." << endl;
		return -1;
	}
	return 0;
}

int read_hello()
{
	helloworld msg;
	fstream input("./log", ios::in | ios::binary);
	if (!msg.ParseFromIstream(&input))
	{
		cerr << "Failed to parse msg." << endl;
		return -1;
	}

	list_hello(msg);
	return 0;
}

void test_hello()
{
	write_hello();
	read_hello();
}


int main()
{
	test_hello();
	
	getchar();
	return 0;
}
