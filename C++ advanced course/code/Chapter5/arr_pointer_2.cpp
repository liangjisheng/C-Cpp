
#include <iostream>

using std::cout;
using std::endl;

// ��C�����У���������±��ǲ���Խ���飬����ں����Ĳ����У�int[5]��int[1]
// ���ᱻ����int[]Ҳ����int*
void show(int A[5])
{
	A++;
	cout << A[0] << endl;
}

void show1(int A[1])
{
	A++;
	cout << A[0] << endl;
}


// ����������β�������ʵ�ε����ã���ô����ĳ��Ⱦ�����Ϊ���͵�һ���֣�ʵ����
// �����齨�����ã����Ƕ�������׵�ַ����һ�������ã�int(&)[5],int(&)[6]����Ϊ
// �ǲ�ͬ����������
void show2(int (&A)[5])
{
	cout << "The type is int(&)[5]" << endl;
}

void show2(int (&A)[6])
{
	cout << "The type is int(&)[6]" << endl;
}


int main()
{
	int d[5] = {1, 2, 3, 4, 5};
	show(d);
	show1(d);

	show2(d);

	system("pause");
	return 0;
}