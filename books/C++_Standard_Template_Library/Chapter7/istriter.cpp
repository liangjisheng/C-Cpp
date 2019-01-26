
// ͨ��istream���������㷨����ֱ�Ӵ�steam�ж�ȡ���ݣ�istream��������ostream������Ҫ����һЩ
// ͨ�������,����дҪ���ӡ���ȡ��������ʧ��(���ܶ�ȡ���ļ�β�����ȡ����)�������㷨Ҳ��Ҫ
// ֪�������Ƿ��Ѿ������յ㡣Ϊ�˽����Щ���⣬����ʹ��һ��end-of-stream����������istream
// ��������Ĭ�Ϲ��캯�����ɣ�ֻҪ���κ�һ�ζ�ȡʧ�ܣ�����istream������������end-of-stream
// ���������ڽ���һ�ζ�ȡ��Ӧ�ý�istream��������end-of-stream���������бȽϣ��������������
// �Ƿ�Ϸ�

// ����������������������Ϊ����istream���������
// ���߶���end-of-istream������(���ܽ��ж�ȡ����)��
// ���߶����Խ��ж�ȡ��������ָ����ͬ��stream

#include <iostream>
#include <iterator>

using namespace std;

// ���룺 1 2 3 f 4 

int main()
{
	// create istream iterator that reads integers from cin
	istream_iterator<int> intReader(cin);

	// create end-of-stream iterator
	istream_iterator<int> intReaderEOF;

	// while able to read tokens with istream iterator
	// write them twice
	while (intReader != intReaderEOF)
	{
		cout << "once: " << *intReader << endl;
		cout << "once again: " << *intReader << endl;
		// ��ȡ��һ��Ԫ��
		++intReader;
	}

	system("pause");
	return 0;
}