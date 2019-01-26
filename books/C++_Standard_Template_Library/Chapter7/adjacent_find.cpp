

/***********************************************************
 * @brief: adjacent_find
 * @author: Jisheng Liang
 * @email: 1294851990@qq.com
 * @date: 2017/12/20 15:58:06
 * @version: 1.0
 **********************************************************/

/* adjacent_find���ڲ�����Ȼ������������ڽ�Ԫ�ضԡ�����������ԭ��: һ�����ڵ���������
 * [first, last)�ϲ�������������Ԫ�����ʱ������Ԫ�ض��еĵ�һ��Ԫ�صĵ�����λ�á�
 * ��һ����ʹ�ö�Ԫν���ж�binary_pred,���ҵ���������[first, last)����������binary_pred
 * �������ڽ�Ԫ�ضԣ�δ�ҵ�����last
*/

/**
template<class ForwardIterator>
	ForwardIterator adjacent_find(
	ForwardIterator _First,
	ForwardIterator _Last
	);  
template<class ForwardIterator , class BinaryPredicate>  
	ForwardIterator adjacent_find(  
	ForwardIterator _First,   
	ForwardIterator _Last,   
	BinaryPredicate _Comp  
	);
*/


#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>

using namespace std;

// �ж�x��y�Ƿ���żͬ��
bool parity_equal(int x, int y) 
{
	return abs(x - y) % 2 == 0 ? 1 : 0;
}

int main()
{
	list<int> coll;
	coll.push_back(3);
	coll.push_back(6);
	coll.push_back(9);
	coll.push_back(11);
	coll.push_back(11);
	coll.push_back(18);
	coll.push_back(20);
	coll.push_back(20);

	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	// �����ڽ���ȵ�Ԫ��
	list<int>::iterator iter = adjacent_find(coll.begin(), coll.end());
	if (iter != coll.end())
	{
		cout << "�����е�һ����ȵ�����Ԫ��Ϊ: " << endl;
		cout << *iter++ << " " ;
		cout << *iter << endl;
	}
	else
		cout << "������û����ȵ�����Ԫ��" << endl;

	// ������żͬ�Ե�����Ԫ��
	iter = adjacent_find(coll.begin(), coll.end(), parity_equal);
	if (iter != coll.end())
	{
		cout << "�����е�һ����żͬ�Ե�����Ԫ��Ϊ�� " << endl;
		cout << *iter++ << " " ;
		cout << *iter << endl;
	}
	else
		cout << "������û����żͬ�Ե�����Ԫ��" << endl;

	system("pause");
	return 0;
}