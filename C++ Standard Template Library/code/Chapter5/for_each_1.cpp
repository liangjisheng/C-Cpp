
// һЩ�㷨���Խ����û�����ĸ����Ժ���,�ɴ��ṩ������Ժ�����
// ��Щ���������㷨�ڲ�������

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// function that prints the passed argument
void print(int elem) { std::cout << elem << ' '; }


int main()
{
	vector<int> coll;

	for (int i = 1; i <= 9; ++i)
		coll.push_back(i);

	// for_each()�������ڵ�ÿһ��Ԫ�ص���print����
	// ÿ��Ԫ����Ϊ��������print
	for_each(coll.begin(), coll.end(),	// range
		print);							// operation
	cout << endl;

	system("pause");
	return 0;
}