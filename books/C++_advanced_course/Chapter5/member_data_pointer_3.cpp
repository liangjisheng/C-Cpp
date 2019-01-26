
// ��Ա����ָ����ʵ�����Ĺ��г�Ա������ó�Ա����ָ��ָ�����˽�г�Ա��ʹ�ò���
// �������������

#include <iostream>

using std::cout;
using std::endl;

class HaveTwoArray
{
	int arr1[5];
	int arr2[5];
public:
	HaveTwoArray()
	{
		for(int i = 0; i < 5; i++)
		{
			arr1[i] = i + 1;
			arr2[i] = i + 5;
		}
	}

	friend void PrintArray(HaveTwoArray &s, int i);
};

// pmָ�����HaveTwoArray���е���5��int����Ԫ�ص�����ָ��,������������ó�
// ��HaveTwoArray����Ԫ�����ǲ��еģ���Ϊ���ڵ��ú�����ʱ����������˽�г�Ա��
// ���ԣ����Զ���һ��������PrintArray()����Ԫ�������ú����Ĳ����в�����Ҫ����
// ��HaveTwoArray��˽�г�Ա
void PrintArray(HaveTwoArray &s, int (HaveTwoArray::* pm)[5])
{
	int *p;
	p = s.*pm;
	for(int i = 0; i < 5; i++)
		cout << p[i] << " ";
}


void PrintArray(HaveTwoArray &s, int i)
{
	if(1 == i)
		PrintArray(s, &HaveTwoArray::arr1);
	else if(2 == i)
		PrintArray(s, &HaveTwoArray::arr2);
}


int main()
{
	HaveTwoArray me;

	// PrintArray(me, &HaveTwoArray::arr2);

	PrintArray(me, 1);
	cout << endl;
	PrintArray(me, 2);
	cout << endl;

	system("pause");
	return 0;
}