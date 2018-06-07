#include <iostream>
#include <list>
#include <numeric>
#include <algorithm>

using namespace std;

//����һ��list������ʵ��LISTINT
typedef list<int> LISTINT;

//����һ��list������ʵ��LISTCHAR
typedef list<int> LISTCHAR;

void main(void)
{
    //--------------------------
    //��list����������������
    //--------------------------
    //��LISTINT����һ����ΪlistOne��list����
    LISTINT listOne;
    //����iΪ������
    LISTINT::iterator i;

    //��ǰ����listOne�������������
    listOne.push_front (2);
    listOne.push_front (1);

    //�Ӻ�����listOne�������������
    listOne.push_back (3);
    listOne.push_back (4);

    //��ǰ�����ʾlistOne�е�����
    cout<<"listOne.begin()--- listOne.end():"<<endl;
    for (i = listOne.begin(); i != listOne.end(); ++i)
        cout << *i << " ";
    cout << endl;

    //�Ӻ������ʾlistOne�е�����
	LISTINT::reverse_iterator ir;
    cout<<"listOne.rbegin()---listOne.rend():"<<endl;
    for (ir =listOne.rbegin(); ir!=listOne.rend();ir++) {
        cout << *ir << " ";
    }
    cout << endl;

    //ʹ��STL��accumulate(�ۼ�)�㷨
    int result = accumulate(listOne.begin(), listOne.end(),0);
    cout<<"Sum="<<result<<endl;
    cout<<"------------------"<<endl;

    //--------------------------
    //��list���������ַ�������
    //--------------------------

    //��LISTCHAR����һ����ΪlistOne��list����
    LISTCHAR listTwo;
    //����iΪ������
    LISTCHAR::iterator j;

    //��ǰ����listTwo�������������
    listTwo.push_front ('A');
    listTwo.push_front ('B');

    //�Ӻ�����listTwo�������������
    listTwo.push_back ('x');
    listTwo.push_back ('y');

    //��ǰ�����ʾlistTwo�е�����
    cout<<"listTwo.begin()---listTwo.end():"<<endl;
    for (j = listTwo.begin(); j != listTwo.end(); ++j)
        cout << char(*j) << " ";
    cout << endl;

    //ʹ��STL��max_element�㷨��listTwo�е����Ԫ�ز���ʾ
    j=max_element(listTwo.begin(),listTwo.end());
    cout << "The maximum element in listTwo is: "<<char(*j)<<endl;
}
