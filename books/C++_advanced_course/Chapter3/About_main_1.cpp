
// ͨ����������errorlevel���Ի�ȡ��C++������Ӧ�ó����main()�����ķ���ֵ

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	int i = 0;
	cout << "input a number:";
	cin >> i;

	system("pause");
	// exit(i);ִ�е�Ч����return i;��Ч����һ���ģ����ǽ�i��Ϊ����ķ��ؽ��
	// ����C++��exit()���ܻ��ƻ�����������������ĵ��ã���C++��Ӧ��ʹ���쳣
	// �������
	return i;
}