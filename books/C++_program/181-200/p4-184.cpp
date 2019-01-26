#include <iostream.h>
#include <set>

using namespace std;

//����setģ���ʵ��
typedef set<int> SET_INT;

//put_HTset��������ͷ��β��ʾset����������Ԫ��
void put_HTset(SET_INT set1,char *name)
{
    SET_INT::iterator it;

    cout<<name<<": ";
	cout<<"Head to Tail=";
    for (it=set1.begin();it!=set1.end();++it)
        cout<<(*it)<<" ";
    cout<<endl;
}

//put_THset��������β��ͷ��ʾset����������Ԫ��
void put_THset(SET_INT s1,char *name)
{
    SET_INT::reverse_iterator i;

    cout<<name<<": ";
  	cout<<"Tail to Head=";
    for (i=s1.rbegin(); i!=s1.rend();i++)
        cout <<(*i) <<" ";
    cout<<endl;
}

//����setģ��
void main(void)
{
	int i;
    //����set�Ķ���͵�����
    SET_INT s1;      //������ʼβ��
    SET_INT::iterator it;

    //��s1�����в���ֵ
	for (i=1;i<20;i=i+2) {
        s1.insert(i);
	}

    //������ʾs1�е�����
    put_HTset(s1,"s1");

    //������ʾs1�е�����
    put_THset(s1,"s1");

	//���캬��Ԫ�ص����в���ʾ
    SET_INT s2(s1);
    put_HTset(s2,"s2");

	//ɾ��s2�ĵ�2��Ԫ�ز���ʾ
    s2.erase(++s2.begin());
    put_HTset(s2,"s2");

	//��s2����8��9����ʾ
    s2.insert(8);
    s2.insert(9);
    put_HTset(s2,"s2");

	//���s2������
    s2.clear();
    put_HTset(s2,"s2");

	//���ؼ�������������ʾ�����е�Ԫ��
	cout<<"[s1.lower_bound(5),s1.upper_bound(15)] :";
	for (it=s1.lower_bound(4);it!=s1.upper_bound(16);it++)
		cout<<(*it)<<" ";
	cout<<endl;

    //��ʾs1��״̬��Ϣ
    cout<<"s1.size():"<<s1.size()<<endl;
    cout<<"s1.max_size():"<<s1.max_size()<<endl;
    cout<<"s1.count(15):"<<s1.count(15)<<endl;

	//��������set������Ԫ�ز���ʾ
	s1.swap(s2);
    put_HTset(s1,"s1");
    put_HTset(s2,"s2");

	//��ϵ����
	s1.insert(5);
	cout<<"s1>s2 = "<<(s1>s2)<<endl;
}
