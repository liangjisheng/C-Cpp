#include <iostream>
#include <list>
#include <numeric>

using namespace std;
//����һ��list������ʵ��LISTINT������int������
typedef list<int> LISTINT;

void main(void)
{
    //��LISTINT����һ����ΪlistOne��list����
    LISTINT listOne;
    //ָ��iΪ����������
    LISTINT::iterator i;
    LISTINT::reverse_iterator ir;

    //��ǰ����listOne�������������
    listOne.push_front (2);
    listOne.push_front (1);

    //�Ӻ�����listOne�������������
    listOne.push_back (3);
    listOne.push_back (4);

    //��ǰ�����ʾlistOne�е�����
    for (i = listOne.begin(); i != listOne.end(); ++i)
        cout << *i << " ";
    cout << endl;

    //�Ӻ������ʾlistOne�е�����
    for (ir =listOne.rbegin();ir!=listOne.rend(); ++ir) 
        cout << *ir << " ";
    cout << endl;

    //�Ӽ�������������
    for (i = listOne.begin(); i != listOne.end(); ++i) {
        cout<<"listOne  :";
        cin>>(*i);
    }

    //��ǰ�����ʾlistOne�е�����
    for (i = listOne.begin(); i != listOne.end(); ++i)
        cout << *i << " ";
    cout << endl;
	
    //bidirectional������������Ӽ�����
    // i=listOne.begin()+1;
}
