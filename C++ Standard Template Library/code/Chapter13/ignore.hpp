
#include <istream>
#include <limits>

// 自动操控器，将end-of-line之前的所有字符(即当前此行的剩余部分)忽略掉

template<class charT, class traits>
inline std::basic_istream<charT, traits>&
	ignoreLine(std::basic_istream<charT, traits>& strm)
{
	// skip until end-of-line
	// 成员函数widen(char c)	// 把char类型的字符c转化为stream字符集中的字符
	// narrow(c, def);	// 把stream字符集中的字符c转换为一个char字符(如果无对应字符，则返回def)
	strm.ignore(std::numeric_limits<int>::max(), strm.widen('\n'));
	return strm;
}
