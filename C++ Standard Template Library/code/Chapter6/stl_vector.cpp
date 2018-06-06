
// 容器内的元素必须符合特定的条件,因为容器乃是以一种特别的方式来操作他们
// STL容器元素必须满足以下三个基本要求： 
// 1.必须可以通过拷贝构造函数进行复制,副本与原本必须相同
// 2.必须可以透过assignment操作符完成复制动作
// 3.必须可以通过析构函数完成销毁动作,当容器元素被移除时,它在容器内的副本
//   将被销毁,因此析构函数绝对不能被设计为private.此外,C++惯例,析构函数绝
//   对不能抛出异常(throw exceptions)

// 容器的共同能力
// 1.STL所有容器只支持值(value)语意,不支持引用(reference)语意,如果打算存放
//   的对象不具有public copy构造函数,或者要的不是副本(例如要的是被多个容器
//   共同容纳的元素),那么容器元素就只能是指针
// 2.总体而言,所有元素形成一个次序
// 3.一般而言,各项操作并非绝对安全,调用者必须确保传给操作函数的参数符合需求

// vector是定义于namespace std中的template
// namespace std{
//  template<class T, class Allocator = allocator<T> >
//	class vector{...};
//  }
// 第二个参数可有可无,用来定义内存模型,默认的内存模型是C++标准程序库提供的allocator


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