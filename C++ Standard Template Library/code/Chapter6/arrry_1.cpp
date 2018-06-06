
// �������б�д�������οɴ��������򡢺ϲ����㷨�����棬�����Ŀ�����ǿ����Է��(Open-closed)
// ԭ��ļ��ѷ���:������չ��л���޸�
// ������ʹ�Լ�������STL�������ֲ�ͬ�ķ���
// 1.The invasive approach(����������)
// ֱ���ṩSTL��������ӿڣ����磺begin(),end();����������ĳ���ض���ʽ��д�����������������Ե�
// 2.The noninvasive approach(������������)
// ����Ҫ��ֻ�Ǳ�����������Ԫ�ص�����----�����κ�����������ĳ����ʽչ�ֵ�����
// 3.The wrapper approach(��װ��)
// ����������ַ���������ϣ�дһ����������(wrapper class)����װ�κ����ݽṹ������ʾ����STL
// �������ƵĽӿ�

// C++��׼������е�string����������������д��STL����
// ��׼����array���Է������Է���д��

// �������ķ�������: ��Ϊ���Ƶ��������κζ�������һ�ֵ���������ʵ��ָ������һ�������ȡ������
// ����ʾ�������array��ΪSTL����

#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>

using namespace std;

int main()
{
	int coll[] = { 5, 6, 2, 4, 1, 3 };

	// print all elements
	// �����β�������һ��Ԫ�ص���һ��λ�ã���������6�������Ǽ�5
	copy(coll, coll + 6, ostream_iterator<int>(cout, " "));
	cout << endl;

	// square all elements
	transform(coll, coll + 6,		// first source
			coll,					// second source
			coll,					// destination
			multiplies<int>());		// operation

	// print all elements
	copy(coll, coll + 6, ostream_iterator<int>(cout, " "));
	cout << endl;

	// sort begining with the second element
	sort(coll + 1, coll + 6);

	// print all elements
	copy(coll, coll + 6, ostream_iterator<int>(cout, " "));
	cout << endl;

	system("pause");
	return 0;
}