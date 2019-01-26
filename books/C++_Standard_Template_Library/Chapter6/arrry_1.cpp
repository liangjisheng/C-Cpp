
// 可以自行编写容器，任可从诸如排序、合并等算法中受益，这样的框架正是开放性封闭(Open-closed)
// 原则的极佳范例:允许扩展，谢绝修改
// 下面是使自己的容器STL化的三种不同的方法
// 1.The invasive approach(侵入性做法)
// 直接提供STL容器所需接口，例如：begin(),end();这种做法以某种特定方式编写容器，所以是侵入性的
// 2.The noninvasive approach(非侵入性做法)
// 所需要的只是遍历容器所有元素的能力----这是任何容器都能以某种形式展现的能力
// 3.The wrapper approach(包装法)
// 将上面的两种方法加以组合，写一个外套类型(wrapper class)来包装任何数据结构，并显示出与STL
// 容器相似的接口

// C++标准程序库中的string是以侵入性做法编写的STL容器
// 标准容器array是以非侵入性法编写的

// 纯粹抽象的泛华概念: 行为类似迭代器的任何东西就是一种迭代器。事实上指针正是一个随机存取迭代器
// 下面示范如何以array作为STL容器

#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>

using namespace std;

int main()
{
	int coll[] = { 5, 6, 2, 4, 1, 3 };

	// print all elements
	// 区间的尾部是最后一个元素的下一个位置，因此这里加6，而不是加5
	copy(coll, coll + 6, ostream_iterator<int>(cout, " "));
	cout << endl;

	// square all elements
	transform(coll, coll + 6,		// first source
			coll,					// second source
			coll,					// destination
			multiplies<int>());		// operation

	// print all elements
	copy(coll, coll + 6, ostream_iterator<int>(cout, " "));
	cout << endl;

	// sort begining with the second element
	sort(coll + 1, coll + 6);

	// print all elements
	copy(coll, coll + 6, ostream_iterator<int>(cout, " "));
	cout << endl;

	system("pause");
	return 0;
}