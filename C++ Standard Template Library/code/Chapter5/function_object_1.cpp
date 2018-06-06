
// �º����Ƿ��ͱ��ǿ�������ʹ������������һ������,������ô˵
// �κζ���,ֻҪ����Ϊ����,�����Ǹ�����.���,����㶨����һ������
// ��Ϊ����,���Ϳ��Ա���������ʹ��
// ��ν������Ϊ: ��ָ������С���Ŵ��ݲ���,���Ե���ĳ������
// funtion(arg1, arg2);		// a function call

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// simple function object that prints the passed argument
class PrintInt
{
public:
	void operator() (int elem) const { cout << elem << ' '; }
};


int main()
{
	vector<int> coll;
	for (int i = 1; i <= 9; ++i)
		coll.push_back(i);

	// print all elements
	// PrintInt()���������һ����ʱ����,����for_each()��һ������
	for_each(coll.begin(), coll.end(),	// range
		PrintInt());					// source
	cout << endl;

	system("pause");
	return 0;
}