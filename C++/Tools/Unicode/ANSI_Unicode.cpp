
// 字符串和宽字符串之间的转化不是简单的、固定的数学关系，宽窄转换
// 依赖于本地化策略集(locale)，换句话说，一个程序在运行之前并不知
// 道系统的本地化策略集是什么，程序只有在运行之后才通过locale获得
// 当时的本地化策略集

// locale()		// 获得当前程序的locale
// explicit locale(const char *name);		// 创建新的locale
// std::locale sys_loc("");		// 获得当前系统的locale
// 获得C定义的locale
// std::locale C_loc("C"); or std::locale C_loc = std::locale::classic()
// std::locale old_loc = std::locale::global(new_loc);

// mbstowcs() and wcstombs()这两个C运行时库函数依赖于全局locale进行转换
// 所以，使用前必须先设置全局locale

#include <iostream>
#include <string>
#include <locale>

using namespace std;

// 在制定转换空间缓存大小的时候，考虑如下：char是用1个或多个对象
// 也就是1个或者多个字节来表示各种符号:比如，GB2312用1个字节表示
// 数字和字母,2个字节表示汉字;UTF-8用一个字节表示数字和字母，3个
// 字节表示汉字，4个字节表示一些很少用到的符号,比如音乐中G大调符
// 号等.wchar_t是用1个对象（2字节或者4字节）来表示各种符号。因此
// 表示同样的字符串，宽字符串的大小（也就是wchar_t对象的数量）总
// 是小于或者等于窄字符串大小（char对象数量）的。+1 是为了在最后
// 预留一个值为0的对象,以便让C风格的char或者wchar_t字符串自动截断
// ——这当然是宽串大小等于窄串大小的时候才会用上的，大部分时候字
// 符串早在前面某个转换完毕的位置就被0值对象所截断了。


const std::wstring s2ws(const std::string &s)
{
	locale old_loc = locale::global(locale(""));

	const char* src_str = s.c_str();
	const size_t buffer_size = s.size() + 1;
	wchar_t* dst_wstr = new wchar_t[buffer_size];
	wmemset(dst_wstr, 0, buffer_size);
	mbstowcs(dst_wstr, src_str, buffer_size);
	wstring result = dst_wstr;
	delete []dst_wstr;
	dst_wstr = NULL;

	locale::global(old_loc);
	return result;
}

// 这里考虑转换空间缓存大小的策略正好相反，在最极端的情况下
// 所有的wchar_t都需要4个char来表示，所以最大的可能就是4倍加1

const std::string ws2s(const std::wstring& ws)
{
	locale old_loc = locale::global(locale(""));

	const wchar_t* src_wstr = ws.c_str();
	size_t buffer_size = ws.size() * 4 + 1;
	char* dst_src = new char[buffer_size];
	memset(dst_src, 0, buffer_size);
	wcstombs(dst_src, src_wstr, buffer_size);
	string result = dst_src;
	delete [] dst_src;
	dst_src = NULL;

	locale::global(old_loc);
	return result;
}