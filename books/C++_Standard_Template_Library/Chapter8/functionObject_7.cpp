
// 以compose_f_gx_hx组合两个运算准则
// 这也许是最重要的一个组合型函数配接器，它允许你将两个准则加以组合，形成单一准则
// 当需要大于4且小于7这样的准则是，就需要这样的配接器

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include "..\..\print.hpp"

using namespace std;

// class for the compose_f_gx_hx adapter
template<class OP1, class OP2, class OP3>
class compose_f_gx_hx_t
	: public std::unary_function<typename OP2::argument_type,
								typename OP1::result_type>
{
private:
	OP1 op1;	// process: op1(op2(x), op3(x))
	OP2 op2;
	OP3 op3;

public:
	compose_f_gx_hx_t(const OP1& o1, const OP2& o2, const OP3& o3)
		: op1(o1), op2(o2), op3(o3) {}

	// function call
	typename OP1::result_type
		operator() (const typename OP2::argument_type& x) const
	{
		return op1(op2(x), op3(x));
	}
};


// convenience functions for the compose_f_gx_hx adapter
// compose_f_gx_hx将"两个一元表达式对同一对象的运算结果"再以一个表达式加以组合，
// 所以compose_f_gx_hx_t(o1, o2, o3)实际相当于一个一元判断式(unary predicate)
// 并对x调用一下表达式op1(op2(x), op3(x))
template<class OP1, class OP2, class OP3>
inline compose_f_gx_hx_t<OP1, OP2, OP3>
	compose_f_gx_hx(const OP1& o1, const OP2& o2, const OP3& o3)
{
	return compose_f_gx_hx_t<OP1, OP2, OP3>(o1, o2, o3);
}


int main()
{
	vector<int> coll;

	for (int i = 1; i <= 9; ++i)
		coll.push_back(i);
	PRINT_ELEMENTS(coll);

	// remove all elements that are greater than four and less than seven
	// retain new end
	vector<int>::iterator pos;
	pos = remove_if(coll.begin(), coll.end(),
					compose_f_gx_hx(logical_and<bool>(),
									bind2nd(greater<int>(), 4),
									bind2nd(less<int>(), 7)));

	// remove "removed" elements in coll
	coll.erase(pos, coll.end());
	PRINT_ELEMENTS(coll);

	system("pause");
	return 0;
}
