
// ��compose_f_gx_hx�����������׼��
// ��Ҳ��������Ҫ��һ������ͺ�����������������㽫����׼�������ϣ��γɵ�һ׼��
// ����Ҫ����4��С��7������׼���ǣ�����Ҫ�����������

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
// compose_f_gx_hx��"����һԪ���ʽ��ͬһ�����������"����һ�����ʽ������ϣ�
// ����compose_f_gx_hx_t(o1, o2, o3)ʵ���൱��һ��һԪ�ж�ʽ(unary predicate)
// ����x����һ�±��ʽop1(op2(x), op3(x))
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
