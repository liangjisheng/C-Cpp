
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// �ɱ����ģ��
template<typename... Types>
class myVariadicTemplate
{

};

// ����ʹ������������������ʵ����myVariadicTemplate
myVariadicTemplate<> c0;
myVariadicTemplate<int> c1;
myVariadicTemplate<string, double> c2;
myVariadicTemplate<char, int, long, double> c3;


// ���Ͱ�ȫ�Ŀɱ䳤�Ȳ����б�
void handleValue(int val) 
{
	cout << "Integer: " << val << endl; 
}

void handleValue(double val)
{
	cout << "double: " << val << endl;
}

void handleValue(const std::string& val)
{
	cout << "string: " << val << endl;
}


template<typename T>
void processValues(T arg)		// Base case��������
{
	handleValue(arg);
}


// �������е�...��ʾ���������Խ��ܿɱ���Ŀ�Ĳ���
template<typename T1, typename... Tn>
void processValues(T1 arg1, Tn... args)
{
	handleValue(arg1);
	// ...��ʾ����������չ�����������/չ��������args���õ�����
	// ����������������ȡ���������ߵ����ݣ�Ϊ���е�ÿ��ģ�����
	// �ظ������ݣ����ö��ŷָ��ģ���ʵ���ǵݹ�ģ���Ҫһ��ֻ
	// ���ܵ���ģ������Ļ�������(Base case)
	processValues(args...);
}


// test
int main()
{
	processValues(1, 2, 3.45, "test", 1.1f);

	system("pause");
	return 0;
}