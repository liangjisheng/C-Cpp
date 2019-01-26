
#ifndef __ICSTRING_H__
#define __ICSTRING_H__

// ��дһ���࣬ʹ���ַ������ں��Դ�Сд�ķ�ʽ�±�����

#include <string>
#include <iostream>
#include <cctype>		// for toupper()

// replace functions of the standard char_traits<char>
// so that strings behave in a case-insensitive way
struct ignorecase_traits : public std::char_traits<char>
{
	// return whether c1 and c2 are equal
	static bool eq(const char& c1, const char& c2)
	{
		return std::toupper(c1) == std::toupper(c2);
	}

	// return whether c1 is less than c2
	static bool lt(const char& c1, const char& c2)
	{
		return std::toupper(c1) < std::toupper(c2);
	}

	// compare up to n characters of s1 and s2
	static int compare(const char* s1, const char* s2, std::size_t n)
	{
		for (std::size_t i = 0; i < n; ++i)
			if (!eq(s1[i], s2[i]))
				return lt(s1[i], s2[i]) ? -1 : 1;

		return 0;
	}

	// search c in s
	static const char* find(const char* s, std::size_t n, const char& c)
	{
		for (std::size_t i = 0; i < n; ++i)
			if (eq(s[i], c))
				return &(s[i]);

		return 0;
	}
};

// define a special type for such strings
typedef std::basic_string<char, ignorecase_traits> icstring;

// ����C++StandardֻΪ"������ͬ�ַ����ͺ���������"��stream����I/O���������˴�
// ���������Ͳ�����ͬ��������Ҫ�����Լ���output������.ͬ���ĵ���������input
// define an output operator
// because the traits type is different than that for std::ostream
inline std::ostream& operator << (std::ostream& strm, const icstring& s)
{
	// simply convert the icstring into a normal string
	return strm << std::string(s.data(), s.length());
}

#endif  //__ICSTRING_H__