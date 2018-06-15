
#include <iostream>

using std::cout;
using std::endl;

// ģ��Ԫ��̿����ڱ�����չ��ѭ����������������ʱִ��ѭ����

template<int i>
class Loop
{
public:
	template<typename FuncType>
	static inline void Do(FuncType func)
	{
		func(i);
		Loop<i - 1>::Do(func);
		func(i);
	}
};


// �ػ��������ݹ�Ļ���ģ��,����ʱ��ģ��ʲôҲ����
template<>
class Loop<0>
{
public:
	template<typename FuncType>
	static inline void Do(FuncType /* func */) {}
};


void DoWork(int i)
{
	cout << "DoWork(" << i << ")" << endl;
}


// test
int main()
{
	Loop<3>::Do(DoWork);

	system("pause");
	return 0;
}