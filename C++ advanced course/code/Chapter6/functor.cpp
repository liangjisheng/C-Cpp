
// �º�����ʹ��

#include <iostream>

using std::cout;
using std::endl;

template<class T>
class Less
{
public:
	bool operator()(const T &t1, const T &t2)
	{ return t1 < t2; }
};

template<class T>
class Bigger
{
public:
	bool operator()(const T &t1, const T &t2)
	{ return t1 > t2; }
};

template<class T, class T1>
void PrintValue(const T &t1, const T &t2, T1 cmp)
{
	if(cmp(t1, t2))				// �Ѷ���������ʹ��
		cout << t1 << endl;
	else
		cout << t2 << endl;
}

int main()
{
	PrintValue(1, 7, Bigger<int>());
	PrintValue(4.5, 8.6, Less<double>());

	// 32λ������size_t��4���ֽڣ�64λ��������8���ֽ�
	cout << sizeof(size_t) << endl;

	system("pause");
	return 0;
}
