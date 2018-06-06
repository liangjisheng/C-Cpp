
// Ϊ�˱��ּ��ݣ�streams��Ĭ������²����׳��쳣
// exceptions(falgs);		�趨�������쳣�ı�־��һ��ָ���ı�־�����������̾ͻ������쳣
// exception();				���������쳣�ı�־������goodbit��ʾû���κ��쳣���׳�

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