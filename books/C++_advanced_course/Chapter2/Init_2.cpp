
// �����൱��ָ�볣�������Զ�������ʱҲ����ͬʱ��ʼ�������峣�����ʱ��
// ��Ӧ�Ĺ��캯��������ʾ����

#include <iostream>

using std::cout;
using std::endl;
using std::cin;


class A
{
	int num;
public:
	void show() const { cout << num << endl; }
};


void test()
{
	// ���ڳ���Ŀ��ƽṹ���ܵ���ĳЩ�����޷���ʼ�����������������
	int i;
	cout << "input a number:";
	cin >> i;
	if(8 == i)
		goto disp;
	int j = 9;
disp:
	cout << i + j << endl;			// runtime error, j not init
}


void test_1()
{
	// C++�в�û��ǿ��switch���ĸ�case��֧ʹ��break;������һ��case��֧��
	// ����ı����ǿ��ܱ�������֧�������ʹ�õġ�����case��֧��ִ�е������
	// �޷���֤�����к��ʵĳ�ֵ�����Գ���ֻ��һ��case��֧������Ҫ��case��֧
	// �ж���ֲ�����

	int i;
	cout << "input a number;";
	cin >> i;
	switch(i)
	{
	case 1: 
		int j = 6;
		cout << j << endl;
		break;
	//case 2:
		//cout << "hello" << endl;
	}
}


int main()
{
	// û����ʾ�����������Ϊ0�Ĺ��캯�����������ṩ��Ĭ�Ϲ��캯��ʵ����ʲô
	// ��ʼ������û��������a�ǳ�����������캯��������ʼ��������������Զû��
	// �������������ֵ
	const A a;
	a.show();

	test();

	test_1();
	
	system("pause");
	return 0;
}