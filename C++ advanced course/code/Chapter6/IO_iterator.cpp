
// ���Խ���׼�������cin��װ��������������(istream iterator),Ҳ���Խ���׼���
// ����cout��װ�������������(ostream iterator),�Դ�����������������


#include <iostream>
#include <iterator>		// ostream_iterator and istream_iterator

using std::cin;
using std::cout;
using std::endl;


int main()
{
	cout << "Enter two integers:";
	// create istream_iterator for reading int values from cin
	// ֻ�����������������������͵�ֵ���׳�����ʱ�쳣
	std::istream_iterator<int> inputInt(cin);
	int number1 = *inputInt;		// read int from standard input
	// ͨ��++���������ƶ�����һ���������ݴ�
	++inputInt;						// move iterator to the next input value
	int number2 = *inputInt;		// read int from standard input

	// create ostream_iterator for writing int value to cout
	// ֻ�����int���͵����ݣ�����������͵����ݣ�����ֱ������
	std::ostream_iterator<int> outputInt(cout);
	cout << "The sum is:";
	// ��������Ը�ֵ��ʽ����
	*outputInt = number1 + number2;	// output result to cout
	cout << endl;

	system("pause");
	return 0;
}

