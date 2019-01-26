#include <iostream>
#include <list>

using namespace std;
typedef list<int> INTLIST;

//��ǰ�����ʾlist���е�ȫ��Ԫ��
void put_list(INTLIST list, char *name)
{
    INTLIST::iterator plist;

    cout << "The contents of " << name << " : ";
    for(plist = list.begin(); plist != list.end(); plist++)
        cout << *plist << " ";
    cout<<endl;
}

//����list�����Ĺ���
void main(void)
{
	//list1�����ʼΪ��
    INTLIST list1;   
    //list2���������10��ֵΪ6��Ԫ��  
    INTLIST list2(10,6);  
    //list3���������3��ֵΪ6��Ԫ��  
    INTLIST list3(list2.begin(),--list2.end());  

    //����һ����Ϊi��˫�������
    INTLIST::iterator i;

    //��ǰ�����ʾ��list�����Ԫ��
    put_list(list1,"list1");
    put_list(list2,"list2");
    put_list(list3,"list3");
    
	//��list1���к����������Ԫ��
	list1.push_back(2);
	list1.push_back(4);
	cout<<"list1.push_back(2) and list1.push_back(4):"<<endl;
    put_list(list1,"list1");

	//��list1����ǰ���������Ԫ��
	list1.push_front(5);
	list1.push_front(7);
	cout<<"list1.push_front(5) and list1.push_front(7):"<<endl;
    put_list(list1,"list1");

	//��list1�����м��������
	list1.insert(++list1.begin(),3,9);
	cout<<"list1.insert(list1.begin()+1,3,9):"<<endl;
    put_list(list1,"list1");

	//���������ຯ��
	cout<<"list1.front()="<<list1.front()<<endl;
	cout<<"list1.back()="<<list1.back()<<endl;

	//��list1���е�ǰ�����ȥһ��Ԫ��
	list1.pop_front();
	list1.pop_back();
	cout<<"list1.pop_front() and list1.pop_back():"<<endl;
    put_list(list1,"list1");

	//���list1�еĵ�2��Ԫ��
	list1.erase(++list1.begin());
	cout<<"list1.erase(++list1.begin()):"<<endl;
    put_list(list1,"list1");

	//��list2��ֵ����ʾ
	list2.assign(8,1);
	cout<<"list2.assign(8,1):"<<endl;
    put_list(list2,"list2");

	//��ʾ���е�״̬��Ϣ
	cout<<"list1.max_size(): "<<list1.max_size()<<endl;
	cout<<"list1.size(): "<<list1.size()<<endl;
	cout<<"list1.empty(): "<<list1.empty()<<endl;

	//list��������������
    put_list(list1,"list1");
    put_list(list3,"list3");
	cout<<"list1>list3: "<<(list1>list3)<<endl;
	cout<<"list1<list3: "<<(list1<list3)<<endl;

	//��list1��������
	list1.sort();
    put_list(list1,"list1");
    
	//��ϴ���
	list1.splice(++list1.begin(), list3);
    put_list(list1,"list1");
    put_list(list3,"list3"); 
}
