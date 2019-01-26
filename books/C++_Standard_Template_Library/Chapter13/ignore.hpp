
#include <istream>
#include <limits>

// �Զ��ٿ�������end-of-line֮ǰ�������ַ�(����ǰ���е�ʣ�ಿ��)���Ե�

template<class charT, class traits>
inline std::basic_istream<charT, traits>&
	ignoreLine(std::basic_istream<charT, traits>& strm)
{
	// skip until end-of-line
	// ��Ա����widen(char c)	// ��char���͵��ַ�cת��Ϊstream�ַ����е��ַ�
	// narrow(c, def);	// ��stream�ַ����е��ַ�cת��Ϊһ��char�ַ�(����޶�Ӧ�ַ����򷵻�def)
	strm.ignore(std::numeric_limits<int>::max(), strm.widen('\n'));
	return strm;
}
