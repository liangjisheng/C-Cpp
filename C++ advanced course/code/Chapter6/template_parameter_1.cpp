
// ģ��ķ����Ͳ���������ֻ��ʵ����Ϊ���ֳ�������Ҳ���Ա�ʵ����Ϊ�ڱ���׶���
// ����̬������κα��ʽ

#include <iostream>

using std::cout;
using std::endl;

template<typename T, T *Total, int *Number>
class Single
{
	T single_value;
public:
	Single(T s)
	{
		single_value = s;
		(*Total) += s;
		(*Number)++;
	}
};

// ȫ�ֱ����ĵ�ַ���Կ�����������������ʵ����ģ��ķ����Ͳ���
int Int_Total;
int Int_Number;
double Dbl_Total;
int Dbl_Number;


int main()
{
	// ��3,6,9����ʼ��һ����������
	Single<int, &Int_Total, &Int_Number> arr_int[3] = {3, 6, 9};
	Single<double, &Dbl_Total, &Dbl_Number> arr_dbl[4] = {1.1, 2.2, 4.4, 8.8};
	cout << "The number of integers is: " << Int_Number << endl;
	cout << "The total value of integers is: " << Int_Total << endl;
	cout << "The number of double is: " << Dbl_Number << endl;
	cout << "The total value of double is: " << Dbl_Total << endl;

	system("pause");
	return 0;
}

