
// ʹ��copy()��Ϊ��׼����ͱ�׼���֮������ݹ�����
// �����ȡstrings������һ��һ���ķ�ʽ��ӡ����

#include "..\..\algostuff.hpp"
using namespace std;

int main()
{
	copy(istream_iterator<string>(cin),			// begin of source
		istream_iterator<string>(),				// end of source
		ostream_iterator<string>(cout, "\n"));	// destination

	system("pause");
	return 0;
}