
#include <iostream>
#include <atomic>

using std::cout;
using std::endl;
using std::atomic;


int main()
{
	atomic<int> value(10);
	cout << "value = " << value << endl;
	// ��ȡһ��ԭ�����͵ĵ�ǰֵ���������ĵ���ֵ��ӵ�
	// ���ԭ��ֵ��Ȼ�󷵻�δ������ֵ
	int fetched = value.fetch_add(4);
	cout << "Fetched = " << fetched << endl;
	cout << "value = " << value << endl;

	system("pause");
	return 0;
}