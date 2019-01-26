
// �����ڵ�Ԫ�ر�������ض�������,��Ϊ����������һ���ر�ķ�ʽ����������
// STL����Ԫ�ر�������������������Ҫ�� 
// 1.�������ͨ���������캯�����и���,������ԭ��������ͬ
// 2.�������͸��assignment��������ɸ��ƶ���
// 3.�������ͨ����������������ٶ���,������Ԫ�ر��Ƴ�ʱ,���������ڵĸ���
//   ��������,��������������Բ��ܱ����Ϊprivate.����,C++����,����������
//   �Բ����׳��쳣(throw exceptions)

// �����Ĺ�ͬ����
// 1.STL��������ֻ֧��ֵ(value)����,��֧������(reference)����,���������
//   �Ķ��󲻾���public copy���캯��,����Ҫ�Ĳ��Ǹ���(����Ҫ���Ǳ��������
//   ��ͬ���ɵ�Ԫ��),��ô����Ԫ�ؾ�ֻ����ָ��
// 2.�������,����Ԫ���γ�һ������
// 3.һ�����,����������Ǿ��԰�ȫ,�����߱���ȷ���������������Ĳ�����������

// vector�Ƕ�����namespace std�е�template
// namespace std{
//  template<class T, class Allocator = allocator<T> >
//	class vector{...};
//  }
// �ڶ����������п���,���������ڴ�ģ��,Ĭ�ϵ��ڴ�ģ����C++��׼������ṩ��allocator


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;


int main()
{
	// create empty vector for strings
	vector<string> sentence;

	// reserve memory for five elements to avoid reallocation
	sentence.reserve(5);

	// append some elements
	sentence.push_back("hello,");
	sentence.push_back("how");
	sentence.push_back("are");
	sentence.push_back("you");
	sentence.push_back("?");

	// print element separated with spaces
	copy(sentence.begin(), sentence.end(),
			ostream_iterator<string>(cout, " "));
	cout << endl;

	// print "technical data"
	cout << "max_size(): " << sentence.max_size() << endl;
	cout << "size(): " << sentence.size() << endl;
	cout << "capacity(): " << sentence.capacity() << endl;

	// swap second and fourth element
	swap(sentence[1], sentence[3]);

	// insert element "always" before element "?"
	sentence.insert(find(sentence.begin(), sentence.end(), "?"), "always");

	// assign "!" to the last element
	sentence.back() = "!";

	// print element separated with spaces
	copy(sentence.begin(), sentence.end(),
		ostream_iterator<string>(cout, " "));
	cout << endl;

	// print "technical data"
	cout << "max_size(): " << sentence.max_size() << endl;
	cout << "size(): " << sentence.size() << endl;
	cout << "capacity(): " << sentence.capacity() << endl;

	system("pause");
	return 0;
}