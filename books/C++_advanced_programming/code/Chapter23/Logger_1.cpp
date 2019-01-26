
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
	// base template,�����ݹ�
	template<typename T1>
	static void logHelper(ofstream& ofs, const T1& t1)
	{
		ofs << t1; 
	}

	// �ݹ�ģ��
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

// ʹ�ø��������ڼ򻯼�¼��־��
#define log(...) Logger::log(__func__, "(): ", __VA_ARGS__)


// C++û�н��������в����ı�׼�⹦�ܡ�ʹ����������򵥵ĺ�����
// ���������в����м����Ա�ǡ�
bool isDebugSet(int argc, char* argv[])
{
	for (int i = 0; i < argc; ++i)
	{
		if (strcmp(argv[i], "-d") == 0)
			return true;
	}
	return false;
}


// �����������࣬������operator<<, �Խ����ǵ�ʵ��д������
// Logger��ʹ����������������ת������־��
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
