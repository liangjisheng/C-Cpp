
// sets��multisets��Ԫ�ؿ��ٲ��ҷ������Ż���ƣ������ṩ������Ĳ��Һ���
// ������Ӧ����ʹ�ó�Ա��������˿��Ի�ö���ʱ�临�Ӷȣ�����STL�㷨������
// ʱ�临�Ӷ�
// count(elem)	����Ԫ��ֵΪelem��Ԫ�ظ���
// find(elem)	����Ԫ��ֵΪelem�ĵ�һ��Ԫ�أ�����Ҳ����ͷ���end()
// lower_bound(elem)����elem�ĵ�һ���ɲ���λ�ã�Ҳ����Ԫ��ֵ>=elem�ĵ�һ��Ԫ��λ��
// upper_bound(elem)����elem�����һ���ɲ���λ�ã�Ҳ����Ԫ��ֵ>elem�ĵ�һ��Ԫ��λ��
// equal_range(elem)����elem�ɲ���ĵ�һ��λ�ú����һ��λ�ã�Ҳ����Ԫ��ֵ==elem��Ԫ������

#include <iostream>
#include <set>

using namespace std;

int main()
{
	set<int> c;

	c.insert(1);
	c.insert(2);
	c.insert(4);
	c.insert(5);
	c.insert(6);

	cout << "lower_bound(3): " << *c.lower_bound(3) << endl;
	cout << "upper_bound(3): " << *c.upper_bound(3) << endl;
	cout << "equal_range(3): " << *c.equal_range(3).first << " " 
		<< *c.equal_range(3).second << endl;

	cout << endl;
	cout << "lower_bound(5): " << *c.lower_bound(5) << endl;
	cout << "upper_bound(5): " << *c.upper_bound(5) << endl;
	cout << "equal_range(5): " << *c.equal_range(5).first << " " 
		<< *c.equal_range(5).second << endl;

	cout << endl;
	cout << "lower_bound(1): " << *c.lower_bound(1) << endl;
	cout << "upper_bound(1): " << *c.upper_bound(1) << endl;
	cout << "equal_range(1): " << *c.equal_range(1).first << " " 
		<< *c.equal_range(1).second << endl;

	system("pause");
	return 0;
}