
#include <iostream>
#include <type_traits>
#include <string>

using namespace std;


// ������������ģ��ĵڶ�������Ϊ���������������ں������ؽ���
template<typename T>
void process_helper(const T& t, true_type)
{
	cout << t << " is an integral type." << endl;
}


template<typename T>
void process_helper(const T& t, false_type)
{
	cout << t << " is not an integral type." << endl;
}


template<typename T>
void process(const T& t)
{
	process_helper(t, typename is_integral<T>::type());
}



// is_same(),is_same()����trait�����ж����������Ĳ����Ƿ�������ͬ
template<typename T1, typename T2>
void same(const T1& t1, const T2& t2)
{
	bool areTypesTheSame = is_same<T1, T2>::value;
	cout << "'" << t1 << "' and '" << t2 << "' are ";
	cout << (areTypesTheSame ? "the same types." : "different types.") << endl;
}


// �滻ʧ�ܲ��Ǵ���(Substitution Failure Is Not An Error, SFINAE)��
// ����C++��һ�����ӻ�ɬ�����ԣ������һ�����غ������Ϳ���ʹ��enable_if
// ����ĳЩ����������ѡ��Ľ���ĳЩ���ء�enable_ifͨ���������غ������
// �������͡�enable_if��������ģ�����Ͳ�������һ����bool���ڶ�����Ĭ��Ϊ
// void�����ͣ������һ����true��enable_if�����һ������ʹ��::type���ܵ�
// Ƕ�����ͣ����Ƕ�������еڶ���ģ�����Ͳ��������������һ����false��
// ��û��Ƕ�����͡�
// �����ϣ��check_type()�����κ����ݣ�����ɾ��enable_if�ĵڶ���ģ�����Ͳ���
// ������void�滻�ˣ�������ʵ�ֵĹ��ܺ�same()����ģ����ͬ

template<typename T1, typename T2>
typename enable_if < is_same<T1, T2>::value, bool>::type
check_type(const T1& t1, const T2& t2)
{
	cout << "'" << t1 << "' and '" << t2 << "'";
	cout << " are the same types." << endl;
	return true;
}


template<typename T1, typename T2>
typename enable_if <!is_same<T1, T2>::value, bool>::type
check_type(const T1& t1, const T2& t2)
{
	cout << "'" << t1 << "' and '" << t2 << "'";
	cout << " are different types." << endl;
	return false;
}



int main()
{
	if (is_integral<int>::value)
		cout << "int is integeral" << endl;
	else
		cout << "int is not integeral" << endl;

	cout << endl;
	process(123);
	process(2.2);
	process(string("test"));


	cout << endl;
	same(1, 2);
	same(1, 1.1);
	same(3.01, string("test"));


	cout << endl;
	check_type(1, 2);
	check_type(1, 1.1);
	check_type(3.01, string("test"));

	system("pause");
	return 0;
}

