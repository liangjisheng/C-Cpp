
//filename string_wstring_fstream.hpp

#ifndef STRING_WSTRING_FSTREAM_HPP
#define STRING_WSTRING_FSTREAM_HPP

#include <string>
#include <fstream>

const std::wstring s2ws(const std::string& s);
const std::string ws2s(const std::wstring& ws);

// 在窄到宽的转化中，我们先使用默认的本地化策略集(locale)
// 将s通过窄文件流ofs传入文件，这是char到char的传递，没有
// 任何转换；然后我们打开宽文件流wifs，并用系统的本地化策
// 略集(locale)去激活(imbue)之,流在读回宽串wstr的时候就是
// char到wchar_t的转换，并且因为激活了sys_loc，所以实现标
// 准窄到宽的转换。

// 在宽到窄的转化中，我们先打开的是宽文件流wofs，并且用系
// 统的本地化策略集sys_loc激活（imbue）之，这时候，因为要
// 写的文件cvt_buf是一个外部编码,所以执行了从wchar_t到char
// 的标准转换。读回来的文件流从char到char，不做任何转换

const std::wstring s2ws(const std::string& s)
{
	std::locale sys_loc("");

	std::ofstream ofs("cvt_buf");
	ofs << s;
	ofs.close();

	std::wifstream wifs("cvt_buf");
	wifs.imbue(sys_loc);
	std::wstring wstr;
	wifs >> wstr;
	wifs.close();

	return wstr;
}

const std::string ws2s(const std::wstring& ws)
{
	std::locale sys_loc("");

	std::wofstream wofs("cvt_buf");
	wofs.imbue(sys_loc);
	wofs << ws;
	wofs.close();

	std::ifstream ifs("cvt_buf");
	std::string str;
	ifs >> str;
	ifs.close();

	return str;
}

#endif
