
// �ڳ�ʼ���б��У��޷����Ϊ����������Ա���г�ʼ���Ĺ�����ԭ����C++����û��
// �����Ļ��ƣ�����ֻ���ڹ��캯�����ڷֱ�Ϊ��Ա�����ÿ��Ԫ�طֱ𸳳�ֵ�����
// ����Ԫ�ر���Ҳ�Ƕ�����ô���ָ��Ʋ�������ɽϴ������ʱ������
// �޷������ж���һ���������飬��Ϊ�޷�Ϊ����ĳ��������Ա��ʼ����ʵ����ͨ��
// ���徲̬�ĳ������飬���ȷʵ�������ж���һ���������飬һ����ͨ�������Ƕ���
// һ��ָ������ָ�볣����Ȼ���ڳ�ʼ���б���Ϊ����ʼ��

#include <iostream>

using std::cout;
using std::endl;


int* CreateArr(int n)
{
	int *p = NULL;
	p = new int[n];
	for(int i = 0; i < n; i++)
		p[i] = i + 1;
	return p;
}


class A
{
	int arrsize;
	const int *const arr;
public:
	A() : arr(CreateArr(0)) 
	{
		arrsize = 0; 
		cout << "default constructor" << endl;
	}
	A(int n) : arr(CreateArr(n)) { arrsize = n; }
	void show()
	{
		for(int i = 0; i < arrsize; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	~A() { delete[] arr; }
};


int main()
{
	A a(3);
	a.show();

	// ��û�е���A�Ĺ��캯��
	A *ptr = NULL;

	system("pause");
	return 0;
}