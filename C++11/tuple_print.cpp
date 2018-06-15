
#include <iostream>
#include <string>
#include <tuple>

//using std::cout;
//using std::endl;
//using std::string;
//using std::tuple;
//using std::tuple_size;

using namespace std;


// 元组有固定的大小和固定的值类型，这些都是在编译时确定的，
// 元组没有提供任何内置的机制来遍历其元素。

template<int n, typename TupleType>
class tuple_print
{
public:
	tuple_print(const TupleType& t)
	{
		tuple_print<n - 1, TupleType> tp(t);
		cout << get<n - 1>(t) << endl;
	}
};


// 特化，结束递归的基本模板,什么也不做
template<typename TupleType>
class tuple_print<0, TupleType>
{
public:
	tuple_print(const TupleType&) {}
};



// test
int main()
{
	using myTuple = tuple<int, string, bool>;
	myTuple t1(16, "test", true);
	tuple_print<tuple_size<myTuple>::value, myTuple> tp(t1);

	system("pause");
	return 0;
}
