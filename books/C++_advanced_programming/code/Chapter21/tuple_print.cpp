
#include <iostream>
#include <string>
#include <tuple>

//using std::cout;
//using std::endl;
//using std::string;
//using std::tuple;
//using std::tuple_size;

using namespace std;


// Ԫ���й̶��Ĵ�С�͹̶���ֵ���ͣ���Щ�����ڱ���ʱȷ���ģ�
// Ԫ��û���ṩ�κ����õĻ�����������Ԫ�ء�

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


// �ػ��������ݹ�Ļ���ģ��,ʲôҲ����
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
