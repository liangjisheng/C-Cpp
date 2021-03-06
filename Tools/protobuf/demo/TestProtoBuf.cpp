
#include <iostream>
#include <string>
#include <string.h>

#include "person.pb.h"
#include "base16.h"

using namespace std;

int main()
{
	string str_ljs = "ljs";
	string str_ljs_en;
	encode_base16(str_ljs_en, str_ljs);
	// cout << str_ljs_en << endl;

	Test::PersonInfo ps;
	ps.set_name("ljs");
	ps.set_age(1000000);
	// ps.add_phone_num(1000);

	string str_ps, str_ps_base16;
	str_ps = ps.SerializeAsString();	
	encode_base16(str_ps_base16, str_ps);
	cout << str_ps_base16 << endl;

	unsigned char sz_ps[1024] = { 0 };
	bool ok = ps.SerializePartialToArray(sz_ps, sizeof(sz_ps));
	if (ok)
	{
		string str_ps_en1;
		encode_base16(str_ps_en1, sz_ps, strlen((char*)sz_ps));
		cout << str_ps_en1 << endl;
	}
	else
		cout << "serialize failed." << endl;

	cout << ps.name() << endl;
	cout << ps.age() << endl;
	// cout << ps.phone_num(0) << endl;

	string str_en = ps.SerializePartialAsString();
	string str_en_base16;
	encode_base16(str_en_base16, str_en);
	cout << str_en_base16 << endl;

	ok = false;
	ok = ps.SerializePartialToOstream(&cout);
	cout << endl;
	if (ok)
		cout << "serialize ostream ok." << endl;
	else
		cout << "serialize ostream ok." << endl;

	string str_en1, str_en1_base16;
	ok = ps.SerializePartialToString(&str_en1);
	if (ok)
	{
		encode_base16(str_en1_base16, str_en1);
		cout << str_en1_base16 << endl;
	}
	else
		cout << "SerializePartialToString failed." << endl;

	memset(sz_ps, 0, sizeof(sz_ps));
	ok = ps.SerializeToArray(sz_ps, sizeof(sz_ps));
	if (ok)
	{
		string str_ps_en1;
		encode_base16(str_ps_en1, sz_ps, strlen((char*)sz_ps));
		cout << str_ps_en1 << endl;
	}
	else
		cout << "SerializeToArray failed." << endl;

	cout << 2562750 / 3 << endl;

	return 0;
}