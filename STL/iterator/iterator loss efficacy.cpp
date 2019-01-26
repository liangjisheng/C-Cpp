
/***********************************************************
 * @name: iterator loss efficacy.cpp
 * @brief: 迭代器失效
 * @author: 梁基圣
 * @date: 2018/7/23 20:27:41
 * @version: 1.0
 **********************************************************/

// C++ STL中容器扩容会使得迭代器失效，删除也有可能使得迭代器失效

#include <iostream>
#include <vector>

using namespace std;

void push_back_test()
{
	// 那么当vector的长度增加时，也就是往里面继续pushback新的数据，
	// 当前块的内存不够，vector不得不重新申请一块新的更大的内存，
	// 然后把之前的数据复制过来，再插入新的数据
	vector<int> vectmp;
	vectmp.push_back(1);
	cout << &vectmp[0] << endl;
	vectmp.push_back(2);
	cout << &vectmp[0] << endl;
	vectmp.push_back(3);
	cout << &vectmp[0] << endl;
	vectmp.push_back(1);
	cout << &vectmp[0] << endl;
	vectmp.push_back(2);
	cout << &vectmp[0] << endl;
	vectmp.push_back(3);
	cout << &vectmp[0] << endl;

	// 上面每次都是输出第一个元素的地址，但不一定全一样
	// 所以，当定义一个vector的迭代器后，如果在这之后发生了插入新的数据，
	// 那么这个迭代器将失效，因为迭代器是通过指针实现的，
	// 内存地址都发生了改变，迭代器当然会失效
}

void erase_test()
{
	vector<int> vectmp;
	vectmp.push_back(1);
	cout << &vectmp[0] << endl;
	vectmp.push_back(2);
	cout << &vectmp[0] << endl;
	vectmp.push_back(3);
	cout << &vectmp[0] << endl;
	vectmp.push_back(4);
	cout << &vectmp[0] << endl;
	cout << endl;

	// 下面三个输出和上面的最后一个输出相同，说明vector在删除的
	// 时候不会改变内存地址，从而迭代器不会失效
	vector<int>::iterator iter = vectmp.begin() + 1;
	vectmp.erase(iter);
	cout << &vectmp[0] << endl;
	iter = vectmp.begin() + 1;
	vectmp.erase(iter);
	cout << &vectmp[0] << endl;
	iter = vectmp.begin() + 1;
	vectmp.erase(iter);
	cout << &vectmp[0] << endl;
}

int main()
{
	// push_back_test();
	erase_test();

	getchar();
	return 0;
}
