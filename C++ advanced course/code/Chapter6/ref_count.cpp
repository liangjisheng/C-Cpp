
// 利用引用计数实现string类对象的创建和销毁

#include <iostream>

using std::cout;
using std::endl;

class String
{
	static int nCharArray;
	char *str;
	size_t _len;
public:
	String();
	String(char *p);
	String(const String &s);
	char& operator[](unsigned int idx);
	String& operator=(const String &s);
	~String();
	const char* c_str() { return str + 1; }
};

int String::nCharArray;

String::String()
{
	str = NULL;
	_len = 0;
	cout << "in constructor,nCharArray = " << nCharArray << endl;
}

String::String(char *p)
{
	_len = strlen(p);
	str = new char[_len + 1 + 1];
	memset(str, 0, _len + 2);
	strcpy(str + 1, p);
	str[0] = 1;
	nCharArray++;
	cout << "in constructor,nCharArray = " << nCharArray << endl;
}

String::String(const String &s)
{
	str = s.str;
	_len = s._len;
	str[0]++;
	cout << "in constructor,nCharArray = " << nCharArray << endl;
}

char& String::operator[](unsigned int idx)
{
	if(idx < 0 || idx > _len || NULL == str)
	{
		// 因为返回的是char的引用,表明返回值是可以修改的，如果真的
		// idx出错，或者str为NULL，返回静态字符的引用，此时返回值
		// 也是可以修改的，如果不是静态字符，则返回值是不能修改的
		static char nullchar = 0;
		return nullchar;
	}

	if(str[0] > 1)
	{
		char *buf = new char[_len + 1 + 1];
		memset(buf, 0, _len + 2);
		strcpy(buf + 1, str + 1);
		str[0]--;
		str = buf;
		str[0] = 1;
		nCharArray++;
	}
	cout << "in operator[], nCharArray = " << nCharArray << endl;
	return str[idx + 1];
}

String& String::operator=(const String &s)
{
	if(!str)
	{
		_len = s._len;
		str = s.str;
		s.str[0]++;
	}
	else
	{
		str[0]--;
		if(!str[0])
		{
			delete [] str;
			nCharArray--;
		}
		_len = s._len;
		str = s.str;
		str[0]++;
	}
	cout << "in operator=, nCharArray = " << nCharArray << endl;
	return *this;
}

String::~String()
{
	if(str)
	{
		str[0]--;
		if(!str[0])
		{
			delete [] str;
			nCharArray--;
		}
	}
	cout << "in destructor, nCharArray = " << nCharArray << endl;
}

// #pragma pack(8)

struct buffer
{
	char *p;
	int nLength;
	int pnum[10];
	buffer() { p = NULL; }
};

void test()
{
	buffer buf;
	buffer &r = buf;
	cout << sizeof(int) << endl;
	cout << sizeof(buf) << endl;
	cout << sizeof(r) << endl;
}


int main()
{
	test();

	String s1;
	String s2 = "abc";
	String s3 = s2;
	s3[0] = 'p';
	cout << s2.c_str() << endl;
	cout << s3.c_str() << endl;
	s1 = s3;
	s2 = s3;
	cout << s1.c_str() << endl;
	cout << s2.c_str() << endl;

	system("pause");
	return 0;
}

