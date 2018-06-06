
// 二元函数组合配接器(Binary Compose Function Object Adapters)
// 将两个一元运算(分别接受不同参数)的结果加以处理

#include <cctype>			// for toupper()
#include <iostream>
#include <algorithm>
#include <string>
#include <functional>

using namespace std;

// class for the compose_f_gx_hy adapter
template<class OP1, class OP2, class OP3>
class compose_f_gx_hy_t
	: public std::binary_function<typename OP2::argument_type,
									typename OP3::argument_type,
									typename OP1::result_type>
{
private:
	OP1 op1;	// process: op1(op2(x), op3(y))
	OP2 op2;
	OP3 op3;
public:
	compose_f_gx_hy_t(const OP1& o1, const OP2& o2, const OP3& o3)
		: op1(o1), op2(o2), op3(o3) {}

	// function call
	typename OP1::result_type
		operator() (const typename OP2::argument_type& x,
					const typename OP3::argument_type& y) const
	{
		return op1(op2(x), op3(y));
	}
};


// convenience function for the compose_f_gx_hy adapter
template<class OP1, class OP2, class OP3>
inline compose_f_gx_hy_t<OP1, OP2, OP3>
	compose_f_gx_hy(const OP1& o1, const OP2& o2, const OP3& o3)
{
	return compose_f_gx_hy_t<OP1, OP2, OP3>(o1, o2, o3);
}


// 在一个字符串中以不区分大小写的方式搜寻一个子字符串
int main()
{
	string s("Internationalization");
	string sub("Nation");

	// search substring case insensitive
	string::iterator pos;
	pos = search(s.begin(), s.end(),	// string to search in
				sub.begin(), sub.end(),	// substring to search
				compose_f_gx_hy(equal_to<int>(),
								ptr_fun(::toupper),
								ptr_fun(::toupper)));

	if (pos != s.end())
		cout << "\"" << sub << "\" is part of \"" << s << "\"" << endl;

	system("pause");
	return 0;
}
