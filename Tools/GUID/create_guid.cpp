
#include <iostream>
#include <ObjBase.h>		// 提供生成guid的函数
#include "uuid_test.hpp"
#include <sstream>			// stringstream
#include <string>
#include <iomanip>

#pragma comment(lib, "ole32.lib")

using std::cout;
using std::endl;
using std::string;
using std::hex;

namespace Liangjisheng
{
	GUID CreateGuid()
	{
		GUID guid;
		CoCreateGuid(&guid);
		return guid;
	}

	string GuidToString(const GUID &guid)
	{
		using std::istringstream;
		using std::ostringstream;
		using std::to_string;
		string strRes = "";
		istringstream instr;
		ostringstream outstr;
		
		outstr << hex << guid.Data1;
		string str = outstr.str();
		str += '-';
		strRes = str;

		outstr.clear();
		outstr.str("");
		outstr << hex << guid.Data2;
		str = outstr.str();
		str += '-';
		strRes += str;

		outstr.clear();
		outstr.str("");
		outstr << hex << guid.Data3;
		str = outstr.str();
		str += '-';
		strRes += str;

		for (int i = 0; i < 8; ++i)
		{
			if(2 == i)
				strRes += '-';
			outstr.clear();
			outstr.str("");
			int num = guid.Data4[i] >> 4;
			outstr << hex << num;
			str = outstr.str();
			strRes += str;
			num = guid.Data4[i] & 0x0f;
			outstr.clear();
			outstr.str("");
			outstr << hex << num;
			str = outstr.str();
			strRes += str;
		}

		return strRes;
	}
}

int main()
{
	using namespace Liangjisheng;
	GUID guid;
	guid = CreateGuid();
	string guid_str = GuidToString(guid);
	cout << "guid_str: " << guid_str << endl;

	system("pause");
	return 0;
}