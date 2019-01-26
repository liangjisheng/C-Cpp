
#include <istream>

namespace MyLib
{
	double readAndProcessSum1(std::istream& strm)
	{
		double value, sum = 0;

		// while stream is OK read value and add it to sum
		while (strm >> value)
			sum += value;

		if (!strm.eof())
			// �������ʹ���Զ���Ĵ�����Ϣ���Զ���Ĵ���������
			throw std::ios::failure("input error in readAndProcessSum1()");

		return sum;
	}
}