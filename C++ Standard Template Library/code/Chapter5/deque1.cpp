
#include <iostream>
#include <deque>

using std::cout;
using std::endl;
using std::deque;

// vector��δ�ṩpush_front()����Ϊ��ʱ�����ܸ��壬��vectorͷ�˰���һ��
// Ԫ�أ���Ҫ�ƶ�ȫ��Ԫ�أ�һ�����STL����ֻ�ṩͨ���߱�����ʱ������
// �ĳ�Ա����(��ν���ã�ͨ����ζ�ž��г������ӶȻ��߶������Ӷ�)������
// ���Է�ֹ����Ա�������ܺܲ�ĺ���

int main()
{
	deque<float> coll;

	// insert elements from 1.1 to 6.6 each at the front
	for (int i = 1; i <= 6; ++i)
		coll.push_front(i * 1.1);

	// print all elements followed by a space
	for (unsigned int i = 0; i < coll.size(); ++i)
		cout << coll[i] << ' ';
	cout << endl;

	system("pause");
	return 0;
}