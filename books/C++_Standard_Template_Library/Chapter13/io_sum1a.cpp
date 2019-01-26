
// 为了保持兼容，streams于默认情况下并不抛出异常
// exceptions(falgs);		设定会引发异常的标志，一旦指定的标志被设立，立刻就会引发异常
// exception();				返回引发异常的标志，返回goodbit表示没有任何异常被抛出

#include <istream>

namespace MyLib
{
	double readAndProcessSum(std::istream& strm)
	{
		using std::ios;
		double value, sum;

		// save current state of exception flags
		ios::iostate oldExceptions = strm.exceptions();

		// let failbit and badbit throw exceptions
		// note: failbit is also set at end-of-file
		strm.exceptions(ios::failbit | ios::badbit);

		try{
			// while stream is OK read value and add it to sum
			sum = 0;
			while (strm >> value)
				sum += value;
		}
		catch (...){
			// if exception not caused by end-of-file
			// restore old state of exception flags
			// rethrow exception
			if (!strm.eof())
			{
				// restore exception flags
				strm.exceptions(oldExceptions);
				throw;	// rethrow
			}
		}

		// restore old state of exception flags
		strm.exceptions(oldExceptions);

		return sum;
	}
}