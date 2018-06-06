
// stream iterator����һ��������дsteram�ĵ�����.�����ṩ�˱�Ҫ�ĳ���
// ��,ʹ�����Լ��̵��������Ǹ�Ⱥ��(collection),�ܹ����ж�ȡ����.ͬ��
// Ҳ���԰�һ���㷨�����������µ���ĳ���ļ�����Ļ��

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;


int main()
{
	vector<string> coll;
	vector<string>::iterator iter;
	cout << "input text(end of Ctrl + Z): " << endl;

	// read all words from the standard input
	// - source: all strings until end-of-file(or error)
	// - destination: coll(inserting)
	// istream_iterator<string>(cin)����һ���ɴӱ�׼������(standard input stream)
	// ��ȡ���ݵ�stream iterator,��ЩԪ��ͨ��һ���operator>>��������
	// ����������һ��Ԫ��ʱ�����Ϊ: cin >> string;
	// istream_iterator<string>()����Ĭ�Ϲ��캯��,����һ����������������
	// (end of stream)�ĵ�����,�������˼��:�����ڴ��ж�ȡ�κζ���
	// ���stringִ��input������ͨ����ȡ�Կհ׷ָ�������,����������Ϊ��
	// ����ʶ�ȡ(word by word)
	copy(istream_iterator<string>(cin),		// start of source
			istream_iterator<string>(),		// end of source
			back_inserter(coll));			// destination

	// print
	cout << "Before sort: " << endl;
	for (iter = coll.begin(); iter != coll.end(); ++iter)
		cout << *iter << endl;
	cout << endl;

	// sort elements
	sort(coll.begin(), coll.end());

	// print all elements without duplicates
	// - source: coll
	// - destination: standard output (with newline between elements)
	cout << "After sort: " << endl;

	// ostream_iterator<string>(cout, "\n")����һ��output stream iterator
	// ͨ��operator<<��cout��д��strings,�ڶ�������(���п���)������ָ��
	// Ԫ��֮��ķָ���
	unique_copy(coll.begin(), coll.end(),				// source
				ostream_iterator<string>(cout, "\n"));	// destination
	cout << endl;

	system("pause");
	return 0;
}