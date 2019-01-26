
#include <iostream>
#include <fstream>
#include <string.h>

using std::cout;
using std::endl;
using std::cerr;
using std::ofstream;
using std::ostream;


class Logger
{
public:
	static  void enableLogging(bool enable)
	{
		msLoggingEnabled = enable;
	}

	static bool isLoggingEnabled() { return msLoggingEnabled;  }

	template<typename... Args>
	static void log(const Args&... args)
	{
		if (!msLoggingEnabled)
			return;

		ofstream ofs(msDebugFileName, ios_base::app);
		if (ofs.fail())
		{
			cerr << "Unable to open debug file." << endl;
			return;
		}
		logHelper(ofs, args...);
		ofs << endl;
	}

private:
	// base template,结束递归
	template<typename T1>
	static void logHelper(ofstream& ofs, const T1& t1)
	{
		ofs << t1; 
	}

	// 递归模板
	template<typename T1, typename... Tn>
	static void logHelper(ofstream& ofs, const T1& t1, const Tn&... args)
	{
		ofs << t1;
		logHelper(ofs, args...);
	}

	static const char* msDebugFileName;
	static bool msLoggingEnabled;
};


const char* Logger::msDebugFileName = "debugfile.out";
bool Logger::msLoggingEnabled = false;

// 使用辅助宏用于简化记录日志。
#define log(...) Logger::log(__func__, "(): ", __VA_ARGS__)


// C++没有解析命令行参数的标准库功能。使用下面这个简单的函数在
// 所有命令行参数中检查调试标记。
bool isDebugSet(int argc, char* argv[])
{
	for (int i = 0; i < argc; ++i)
	{
		if (strcmp(argv[i], "-d") == 0)
			return true;
	}
	return false;
}


// 定义了两个类，重载了operator<<, 以将他们的实例写入流，
// Logger类使用这个运算符将对象转储到日志中
class ComplicatedClass
{
public:
	ComplicatedClass() {}
};

ostream& operator<<(ostream& ostr, const ComplicatedClass& src)
{
	ostr << "ComplicatedClass";
	return ostr;
}


class UserCommand
{
public:
	UserCommand() {}
};

ostream& operator<<(ostream& ostr, const UserCommand& src)
{
	ostr << "UserCommand";
	return ostr;
}
