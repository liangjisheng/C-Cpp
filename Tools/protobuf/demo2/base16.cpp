
#include <algorithm>
#include <iterator>
#include <sstream>
#include <iomanip>

#include "base16.h"

using namespace std;

bool encode_base16(std::string& out, const std::string& in)
{
	if (0 == in.size())
		return false;

	std::stringstream ss;
	ss << std::hex << std::setfill('0');
	for (int val : in)
		ss << std::setw(2) << val;

	out = ss.str();
	return true;
}

bool encode_base16(std::string& out, const std::vector<unsigned char>& in)
{
	if (0 == in.size())
		return false;

	std::stringstream ss;
	ss << std::hex << std::setfill('0');
	for (int val : in)
		ss << std::setw(2) << val;

	out = ss.str();
	return true;
}

bool encode_base16(std::vector<unsigned char>& out, const std::string& in)
{
	if (0 == in.size())
		return false;

	std::stringstream ss;
	ss << std::hex << std::setfill('0');
	for (int val : in)
		ss << std::setw(2) << val;

	string strRes = ss.str();
	vector<unsigned char>().swap(out);
	copy(strRes.begin(), strRes.end(), back_inserter(out));

	return true;
}

bool encode_base16(std::vector<unsigned char>& out, const std::vector<unsigned char>& in)
{
	if (0 == in.size())
		return false;

	std::stringstream ss;
	ss << std::hex << std::setfill('0');
	for (int val : in)
		ss << std::setw(2) << val;

	string strRes = ss.str();
	vector<unsigned char>().swap(out);
	copy(strRes.begin(), strRes.end(), back_inserter(out));

	return true;
}

bool encode_base16(std::string& str_out, const unsigned char *in, int in_len)
{
	if (NULL == in || in_len <= 0)
		return false;

	std::vector<unsigned char> vec_in;
	std::copy(in, in + in_len, std::back_inserter(vec_in));
	encode_base16(str_out, vec_in);
	return true;
}


static bool decode_base16_private(unsigned char* out, size_t out_size, const char* in);
static bool is_base16(const char c);
static unsigned from_hex(const char c);

bool decode_base16_private(unsigned char* out, size_t out_size, const char* in)
{
	if (!std::all_of(in, in + 2 * out_size, is_base16))
		return false;

	for (size_t i = 0; i < out_size; ++i)
	{
		out[i] = (from_hex(in[0]) << 4) + from_hex(in[1]);
		in += 2;
	}

	return true;
}

bool is_base16(const char c)
{
	return
		('0' <= c && c <= '9') ||
		('A' <= c && c <= 'F') ||
		('a' <= c && c <= 'f');
}

unsigned from_hex(const char c)
{
	if ('A' <= c && c <= 'F')
		return 10 + c - 'A';
	if ('a' <= c && c <= 'f')
		return 10 + c - 'a';
	return c - '0';
}

bool decode_base16(std::string& out, const std::string& in)
{
	// This prevents a last odd character from being ignored:
	if (in.size() % 2 != 0)
		return false;

	vector<unsigned char> vecOut(in.size() / 2);
	if (!decode_base16_private(vecOut.data(), vecOut.size(), in.data()))
		return false;

	out = "";
	copy(vecOut.begin(), vecOut.end(), back_inserter(out));
	return true;
}

bool decode_base16(std::string& out, const std::vector<unsigned char>& in)
{
	// This prevents a last odd character from being ignored:
	if (in.size() % 2 != 0)
		return false;

	vector<unsigned char> vecOut(in.size() / 2);
	string strIn;
	copy(in.begin(), in.end(), back_inserter(strIn));
	if (!decode_base16_private(vecOut.data(), vecOut.size(), strIn.data()))
		return false;

	out = "";
	copy(vecOut.begin(), vecOut.end(), back_inserter(out));
	return true;
}

bool decode_base16(std::vector<unsigned char>& out, const std::string& in)
{
	// This prevents a last odd character from being ignored:
	if (in.size() % 2 != 0)
		return false;

	vector<unsigned char> vecOut(in.size() / 2);
	if (!decode_base16_private(vecOut.data(), vecOut.size(), in.data()))
		return false;

	vector<unsigned char>().swap(out);
	copy(vecOut.begin(), vecOut.end(), back_inserter(out));
	return true;
}

bool decode_base16(std::vector<unsigned char> &out, const std::vector<unsigned char>& in)
{
	// This prevents a last odd character from being ignored:
	if (in.size() % 2 != 0)
		return false;

	vector<unsigned char> vecOut(in.size() / 2);
	string strIn;
	copy(in.begin(), in.end(), back_inserter(strIn));
	if (!decode_base16_private(vecOut.data(), vecOut.size(), strIn.data()))
		return false;

	vector<unsigned char>().swap(out);
	copy(vecOut.begin(), vecOut.end(), back_inserter(out));
	return true;
}

bool decode_base16(unsigned char* out, const std::string& str_in)
{
	if ("" == str_in || NULL == out)
		return false;

	std::vector<unsigned char> vec_out;
	decode_base16(vec_out, str_in);
	std::copy(vec_out.begin(), vec_out.end(), out);
	return true;
}

