
// ����window��ջ�ռ��С�ĳ���

#include <iostream>
#include <iomanip>

using namespace std;

int *addr;
int count;

// ������һ��û�г��ڵĵݹ�������У�û���µݹ�һ�㣬��Ҫ��ջ������ռ�
// ÿ������ռ�Ĵ�С���ԴӲα���i���������ε�ַ�仯�õ��������һֱ���е�
// ��ջ���
void func(int i )
{
	cout << count << " : " << (int)addr - int(&i) << endl;
	count++;
	addr = &i;
	func(i);
}

int main()
{
	int i;
	addr = &i;
	func(2);

	system("pasue");
	return 0;
}