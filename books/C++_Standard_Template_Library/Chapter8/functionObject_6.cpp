
// 理论上下面这些组合型配接器(compose adapters)很有用：

// f(g(elem)):这是一元组合函数(unary compose function)的一般形式。一元判断式被嵌套调用
// g()执行结果被当做f()参数。整个表达式的操作类似于一个一元判断式

// f(g(elem1, elem2)):两个元素elem1, elem2作为参数传递给二元判断式g(),其结果在作为参数
// 传递给一元判断式f(),整个表达式的操作类似一个二元判断式

// f(g(elem), h(elem)):elem作为参数被传递给两个不同的一元判断式g()和h(),两者的结果由
// 二元判断式f()处理。这种形式系以某种方法将单一参数"注射(injects)"到一个组合函数中
// 整个表达式的操作类似于一个一元判断式

// f(g(elem1), h(elem2)): 两个元素elem1, elem2作为参数传递给两个不同的一元判断式g()和
// h(),两个结果共同被二元判断式f()处理。某种程度上这种形式系在两个参数身上分布(distributes)
// 一个组合函数，整个表达式类似于一个二元判断式


// 一元组合函数配接器(Unary Compose Function Object Adapters)

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
#include "..\..\print.hpp"

using namespace std;


// class for the compose_f_gx adapter
template<class OP1, class OP2>
class compose_f_gx_t 
	: public std::unary_function<typename OP2::argument_type,
								typename OP1::result_type>
{
private:
	OP1 op1;	// process: op1(op2(x))
	OP2 op2;
public:
	compose_f_gx_t(const OP1& o1, const OP2& o2) : op1(o1), op2(o2) {}

	// function call
	typename OP1::result_type
		operator() (const typename OP2::argument_type& x) const { return op1(op2(x)); }
};


// convenience functions for the compose_f_gx adapter
template<class OP1, class OP2>
inline compose_f_gx_t<OP1, OP2>
	compose_f_gx(const OP1& o1, const OP2& o2)
{
	return compose_f_gx_t<OP1, OP2>(o1, o2);
}


int main()
{
	vector<int> coll;

	for (int i = 1; i <= 9; ++i)
		coll.push_back(i);
	PRINT_ELEMENTS(coll);

	// for each element add 10 and multiply by 5
	// 传给compose_f_gx的第二个运算会先执行，compose_f_gx会产生一个一元仿函数，
	// 先将元素加10，在乘以5
	transform(coll.begin(), coll.end(),
		ostream_iterator<int>(cout, " "),
		compose_f_gx(bind2nd(multiplies<int>(), 5),
					bind2nd(plus<int>(), 10)));
	cout << endl;

	system("pause");
	return 0;
}
