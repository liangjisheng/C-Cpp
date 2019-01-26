
// ������������Щ����������(compose adapters)�����ã�

// f(g(elem)):����һԪ��Ϻ���(unary compose function)��һ����ʽ��һԪ�ж�ʽ��Ƕ�׵���
// g()ִ�н��������f()�������������ʽ�Ĳ���������һ��һԪ�ж�ʽ

// f(g(elem1, elem2)):����Ԫ��elem1, elem2��Ϊ�������ݸ���Ԫ�ж�ʽg(),��������Ϊ����
// ���ݸ�һԪ�ж�ʽf(),�������ʽ�Ĳ�������һ����Ԫ�ж�ʽ

// f(g(elem), h(elem)):elem��Ϊ���������ݸ�������ͬ��һԪ�ж�ʽg()��h(),���ߵĽ����
// ��Ԫ�ж�ʽf()����������ʽϵ��ĳ�ַ�������һ����"ע��(injects)"��һ����Ϻ�����
// �������ʽ�Ĳ���������һ��һԪ�ж�ʽ

// f(g(elem1), h(elem2)): ����Ԫ��elem1, elem2��Ϊ�������ݸ�������ͬ��һԪ�ж�ʽg()��
// h(),���������ͬ����Ԫ�ж�ʽf()����ĳ�̶ֳ���������ʽϵ�������������Ϸֲ�(distributes)
// һ����Ϻ������������ʽ������һ����Ԫ�ж�ʽ


// һԪ��Ϻ��������(Unary Compose Function Object Adapters)

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
	// ����compose_f_gx�ĵڶ����������ִ�У�compose_f_gx�����һ��һԪ�º�����
	// �Ƚ�Ԫ�ؼ�10���ڳ���5
	transform(coll.begin(), coll.end(),
		ostream_iterator<int>(cout, " "),
		compose_f_gx(bind2nd(multiplies<int>(), 5),
					bind2nd(plus<int>(), 10)));
	cout << endl;

	system("pause");
	return 0;
}
