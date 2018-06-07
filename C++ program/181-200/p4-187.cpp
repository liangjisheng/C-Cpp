#include <iostream>
#include <string>
#include <map>

using namespace std;

//����multimap��ʵ��������(int)ӳ���ַ���(string)
typedef multimap<int, string> INT2STRING;

//����multimap����
void main()
{
    //����multimap����theMap
    INT2STRING theMap;
    INT2STRING::iterator theIterator,it;

    //��theMap�������������ݣ����ֺ��ַ������
    //ÿ��Ԫ����һ��ӳ���
    theMap.insert(INT2STRING::value_type(90,"����"));
    theMap.insert(INT2STRING::value_type(85,"�"));
    theMap.insert(INT2STRING::value_type(73,"����"));
    theMap.insert(INT2STRING::value_type(96,"����"));

    //��ʾmultimap���������ж���
    cout<<"theMap.begin()--theMap.end():"<<endl;
    for (theIterator=theMap.begin();theIterator!=theMap.end();++theIterator){
        cout<<(*theIterator).second;
		cout<<"\t"<<(*theIterator).first<<endl;
    }

	//����multimap����key�ķ�Ωһ��
    theMap.insert(INT2STRING::value_type(90,"����"));
    theMap.insert(INT2STRING::value_type(85,"Ǯ��"));
    theMap.insert(INT2STRING::value_type(93,"�Ը�"));

    //���ɼ��ߵ����multimap���������ж���
    INT2STRING::reverse_iterator i;
    cout<<"theMap.rbegin()--theMap.rend():"<<endl;
    for (i=theMap.rbegin();i!=theMap.rend();++i){
        cout<<(*i).second;
		cout<<"\t"<<(*i).first<<endl;
    }

	//���ؼ�������������ʾ�����е�Ԫ��
	cout<<"[theMap.lower_bound(80),theMap.upper_bound(90)] :"<<endl;
	for (it=theMap.lower_bound(80);it!=theMap.upper_bound(90);it++) {
        cout<<(*it).second;
		cout<<"\t"<<(*it).first<<endl;
    }

	//��ʾtheMap��״̬��Ϣ
    cout<<"theMap.size():"<<theMap.size()<<endl;
    cout<<"theMap.max_size():"<<theMap.max_size()<<endl;
    cout<<"theMap.count(90):"<<theMap.count(90)<<endl;

	//���90�����µ�����,����ʾ���
	theMap.erase(theMap.lower_bound(60),theMap.upper_bound(89));
    cout<<"theMap.rbegin()--theMap.rend():"<<endl;
    for (i=theMap.rbegin();i!=theMap.rend();++i){
        cout<<(*i).second;
		cout<<"\t"<<(*i).first<<endl;
    }
}
