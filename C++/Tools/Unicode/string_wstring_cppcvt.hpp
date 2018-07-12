
// Filename string_wstring_cppcvt.hpp

#ifndef STRING_WSTRING_CPPCVT_HPP
#define STRING_WSTRING_CPPCVT_HPP

#include <iostream>
#include <string>

const std::wstring s2ws(const std::string& s);
const std::string ws2s(const std::wstring& ws);


mbstate_t in_cvt_state;
mbstate_t out_cvt_state;

const std::wstring s2ws(const std::string& s)
{
	std::locale sys_loc("");

	const char* src_str = s.c_str();
	const size_t buffer_size = s.size() + 1;
	wchar_t* intern_buffer = new wchar_t[buffer_size];
	wmemset(intern_buffer, 0, buffer_size);

	const char* extern_from = src_str;
	const char* extern_from_end = extern_from + s.size();
	const char* extern_from_next = 0;
	wchar_t* intern_to = intern_buffer;
	wchar_t* intern_to_end = intern_to + buffer_size;
	wchar_t* intern_to_next = 0;

	typedef std::codecvt<wchar_t, char, mbstate_t> CodecvtFacet;

	CodecvtFacet::result cvt_rst = 
		std::use_facet<CodecvtFacet>(sys_loc).in(
			in_cvt_state,
			extern_from, extern_from_end, extern_from_next,
			intern_to, intern_to_end, intern_to_next);
	if(cvt_rst != CodecvtFacet::ok)
	{
		switch(cvt_rst)
		{
		case CodecvtFacet::partial:
			std::cerr << "partial" << std::endl;
			break;
		case CodecvtFacet::error:
			std::cerr << "error" << std::endl;
			break;
		case CodecvtFacet::noconv:
			std::cerr << "noconv" << std::endl;
			break;
		default:
			std::cerr << "unknow" << std::endl;
		}
		std::cerr << "please check in_cvt_state." << std::endl;
	}

	std::wstring result = intern_buffer;
	delete []intern_buffer;
	return result;
}


const std::string ws2s(const std::wstring& ws)
{
	std::locale sys_loc("");

	const wchar_t* src_wstr = ws.c_str();
	const size_t MAX_UNICODE_BYTES = 4;
	const size_t BUFFER_SIZE =
		ws.size() * MAX_UNICODE_BYTES + 1;
	char* extern_buffer = new char[BUFFER_SIZE];
	memset(extern_buffer, 0, BUFFER_SIZE);

	const wchar_t* intern_from = src_wstr;
	const wchar_t* intern_from_end = intern_from + ws.size();
	const wchar_t* intern_from_next = 0;
	char* extern_to = extern_buffer;
	char* extern_to_end = extern_to + BUFFER_SIZE;
	char* extern_to_next = 0;

	typedef std::codecvt<wchar_t, char, mbstate_t> CodecvtFacet;
	
	CodecvtFacet::result cvt_rst =
		std::use_facet<CodecvtFacet>(sys_loc).out(
		out_cvt_state,
		intern_from, intern_from_end, intern_from_next,
		extern_to, extern_to_end, extern_to_next);

	if (cvt_rst != CodecvtFacet::ok) {
		switch(cvt_rst) {
		case CodecvtFacet::partial:
			std::cerr << "partial";
			break;
		case CodecvtFacet::error:
			std::cerr << "error";
			break;
		case CodecvtFacet::noconv:
			std::cerr << "noconv";
			break;
		default:
			std::cerr << "unknown";
		}

		std::cerr    << ", please check out_cvt_state."	<< std::endl;
	}

	std::string result = extern_buffer;
	delete []extern_buffer;
	return result;
}

#endif